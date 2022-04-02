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
    
    s1 db 1, 3, 5, 7
    l_s equ $-s1
    s2 db 2, 6, 9, 4
    d resb l_s*2
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        mov ecx, l_s
        mov esi, s1
        mov edi, s2
        mov edx, d
        start_loop:
            mov al, byte[esi]
            mov byte[edx], al
            inc esi
            inc edx
            mov al, byte[edi]
            mov byte[edx], al
            inc edi
            inc edx
        loop start_loop
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
