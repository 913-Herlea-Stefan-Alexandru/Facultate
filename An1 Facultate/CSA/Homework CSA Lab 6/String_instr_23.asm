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
    
    s db 2, 4, 2, 5, 2, 2, 4, 4
    l_s equ $-s
    res times l_s dw -1
    l_d db 0

; our code starts here
segment code use32 class=code
    start:
        ; Being given a string of bytes, build a string of words which contains in the low bytes of the words the set of distinct characters from the given string and in the high byte of a word it contains the number of occurrences of the low byte of the word in the given byte string.
        
        mov esi, s
        mov ecx, l_s
        mov edi, res
        cld
        start_loop:
            lodsb
            push ecx
            push edi
            mov ecx, [l_d]
            mov edi, res
            jecxz add_element
            check_loop:
                scasb
                je no_add
                inc edi
            loop check_loop
            add_element:
                inc byte[l_d]
                mov bl, 0
                mov ecx, l_s
                push esi
                mov esi, s
                mov ah, 0
                count_loop:
                    cmp al, [esi]
                    jne not_good
                        inc ah
                    not_good:
                    inc esi
                loop count_loop
                pop esi
                stosw
                pop edx
                jmp end_loop
            no_add:
            pop edi
            end_loop:
            pop ecx
        loop start_loop

        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
