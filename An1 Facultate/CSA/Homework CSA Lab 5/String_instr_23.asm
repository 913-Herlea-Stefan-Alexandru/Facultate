bits 32

global start        

extern exit             
import exit msvcrt.dll   
                         

segment data use32 class=data
    ; ...
    
    s db 1, 4, 2, 4, 8, 2, 1, 1
    l_s equ $-s
    d times l_s db -1

segment code use32 class=code
    start:
        ; A byte string S is given. Obtain in the string D the set of the elements of S.
        
        mov esi, s
        mov edi, d
        mov ecx, l_s
        cld
        start_loop:
            lodsb
            push ecx
            push edi
            mov edi, d
            mov ecx, l_s
            second_loop:
                scasb
                je not_good
            loop second_loop
            pop edi
            stosb
            jmp good
            not_good:
                pop edi
            good:
                pop ecx
        loop start_loop

        push    dword 0   
        call    [exit]     
