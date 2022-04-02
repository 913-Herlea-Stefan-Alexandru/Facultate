bits 32 

global start        

extern exit             
import exit msvcrt.dll    
                          

segment data use32 class=data
    ; ...
    
    s db 'a', 'A', 'b', 'B', '2', '%', 'x', 'M'
    l_s equ $-s
    d times l_s db -1

segment code use32 class=code
    start:
        ; A character string S is given. Obtain the string D that contains all capital letters of the string S.
        
        mov esi, s
        mov edi, d
        mov ecx, l_s
        cld
        start_loop:
            lodsb
            cmp al, byte'Z'
            ja end_if
                cmp al, byte'A'
                jb end_if
                    stosb
            end_if:
        loop start_loop

        push    dword 0   
        call    [exit]     
