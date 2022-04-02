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
    
    s db 'a', 'A', 'b', 'B', '2', '%', 'x', 'M'
    l_s equ $-s
    d resb 8
    l resb 1

; our code starts here
segment code use32 class=code
    start:
        ; d contains all the upper case letters from s
        
        mov eax, d
        mov ebx, s
        sub eax, ebx
        mov [l], al
        mov ecx, eax
        mov ebx, d
        start_loop:
            mov eax, 0
            mov al, [l]
            sub eax, ecx
            add eax, s
            cmp byte[eax], byte'Z'
            ja end_if
                cmp byte[eax], byte'A'
                jb end_if
                    mov al, byte[eax]
                    mov byte[ebx], al
                    inc ebx
            end_if:
        loop start_loop
        
        mov esi, s
        mov edi, d
        mov ecx, l_s
        cld
        start_loop:
            mov al, [esi]
            inc esi
            cmp al, byte'Z'
            ja end_if
                cmp al, byte'A'
                jb end_if
                    mov [edi], al
                    inc edi
            end_if:
        loop start_loop
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
