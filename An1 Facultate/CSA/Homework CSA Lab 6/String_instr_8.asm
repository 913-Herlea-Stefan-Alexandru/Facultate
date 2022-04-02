bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    
    s dd 12345678h, 1A2C3C4Dh, 98FCDC76h
    l_s equ ($-s)/4
    d times l_s db -1

; our code starts here
segment code use32 class=code
    start:
        ; A list of doublewords is given. Obtain the list made out of the low bytes of the high words of each doubleword from the given list with the property that these bytes are palindromes in base 10.
        
        mov esi, s
        mov ecx, l_s
        mov edi, d
        mov ebx, 0
        cld
        start_loop:
            lodsd
            and eax, 0000_0000_1111_1111_0000_0000_0000_0000b
            push ecx
            shr eax, 16
            cmp al, 10
            jb unitary
            cmp al, 100
            jb tenth
            jmp hundreed
            unitary:
                stosb
                jmp end_if
            tenth:
                mov bl, al
                mov dl, 10
                div dl
                cmp al, ah
                jne end_if
                mov al, bl
                stosb
                jmp end_if
            hundreed:
                mov bl, al
                mov dl, 10
                div dl
                mov cl, ah
                mov ax, bx
                mov dl, 100
                div dl
                cmp al, cl
                jne end_if
                mov al, bl
                stosb
            end_if:
            pop ecx
        loop start_loop
            
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
