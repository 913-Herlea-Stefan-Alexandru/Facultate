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

    a db 0101_0111b
    b dw 1001_1011_1011_1110b
    c dd 0
    
; our code starts here
segment code use32 class=code
    start:
        
        mov ebx, 0
    
        ; the bits 24-31 of C are the same as the bits of A
        
        mov eax, 0
        mov al, [a]
        mov cl, 24
        shl eax, cl
        or ebx, eax ; ebx = 0101_0111_0000_0000_0000_0000_0000_0000  hexa: 57 00 00 00
        
        ; the bits 16-23 of C are the invert of the bits of the lowest byte of B
        
        mov eax, 0
        mov ax, [b]
        and ax, 0000_0000_1111_1111b
        not al
        mov cl, 16
        shl eax, cl
        or ebx, eax ; ebx = 0101_0111_0100_0001_0000_0000_0000_0000   hexa: 57 41 00 00
        
        ; the bits 10-15 of C have the value 1
        
        or ebx, 0000_0000_0000_0000_1111_1100_0000_0000b ; 0101_0111_0100_0001_1111_1100_0000_0000   hexa: 57 41 FC 00 
        
        ; the bits 2-9 of C are the same as the bits of the highest byte of B
        
        mov eax, 0
        mov ax, [b]
        and ax, 1111_1111_0000_0000b
        mov cl, 6
        shr eax, cl
        or ebx, eax ; ebx = 0101_0111_0100_0001_1111_1110_0110_1100  hexa: 57 41 FE 6C
        
        ; the bits 0-1 both contain the value of the sign bit of A
        
        mov eax, 0
        mov al, [a]
        and al, 1000_0000b
        mov cl, 6
        shr eax, cl
        or ebx, eax
        mov cl, 1
        shr eax, cl
        or ebx, eax ; ebx = 0101_0111_0100_0001_1111_1110_0110_1100   hexa: 57 41 FE 6C
        
        ; move to c
        
        mov [c], ebx ; c = 0101_0111_0100_0001_1111_1110_0110_1100b  little indian: 6C FE 41 57
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
