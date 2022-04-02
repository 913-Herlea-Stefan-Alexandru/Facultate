bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    a dw 0111_0111_0101_0111b
    b dw 1001_1011_1011_1110b
    c db 0
    d dd 0

; our code starts here
segment code use32 class=code
    start:
    
        mov bl, 0
        
        ; the bits 0-5 are the same as the bits 5-10 of A
        
        mov ax, [a]
        and ax, 0000_0111_1110_0000b
        mov cl, 5
        shr ax, cl
        or bl, al ; bl = 0011_1010  hexa: 3A
        
        ; the bits 6-7 are the same as the bits 1-2 of B.
        
        mov ax, [b]
        and ax, 0000_0000_0000_0110b
        mov cl, 5
        shl ax, cl
        or bl, al ; bl = 1111_1010  hexa: DD
        
        ; move to c
        
        mov [c], bl ; c = 1111_1101  little indian: DD
        
        mov ebx, 0
        
        ; the bits 8-15 are the same as the bits of C
        
        mov eax, 0
        mov al, [c]
        mov cl, 8
        shl eax, cl
        or ebx, eax ; ebx = 0000_0000_0000_0000_1111_1101_0000_0000  hexa: 00 00 FA 00
        
        ; the bits 0-7 are the same as the bits 8-15 of B
        
        mov eax, 0
        mov ax, [b]
        and ax, 1111_1111_0000_0000b
        mov cl, 8
        shr eax, cl
        or ebx, eax ; ebx = 0000_0000_0000_0000_1111_1101_1001_1011  hexa: 00 00 FA 9B
        
        ; the bits 24-31 are the same as the bits 0-7 of A
        
        mov eax, 0
        mov ax, [a]
        and ax, 0000_0000_1111_1111b
        mov cl, 24
        shl eax, cl
        or ebx, eax ; ebx = 0101_0111_0000_0000_1111_1101_1001_1011  hexa: 57 00 FA 9B
        
        ; the bits 16-23 are the same as the bits 8-15 of A.
        
        mov eax, 0
        mov ax, [a]
        and ax, 1111_1111_0000_0000b
        mov cl, 8
        shl eax, cl
        or ebx, eax ; ebx = 0101_0111_0111_0111_1111_1101_1001_1011  hexa: 57 77 FA 9B
        
        ; move to d
        
        mov [d], ebx ; d = 0101_0111_0111_0111_1111_1101_1001_1011  little indian: 9B FA 77 57
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
