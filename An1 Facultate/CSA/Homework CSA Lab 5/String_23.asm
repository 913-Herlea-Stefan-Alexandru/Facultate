bits 32 

global start        

extern exit               
import exit msvcrt.dll    
                          

segment data use32 class=data
    ; ...
    
    s db 1, 4, 2, 4, 8, 2, 1, 1
    l_s equ $-s
    d resb 8
    ls resb 1
    ld db 0

segment code use32 class=code
    start:
        ; d contains the set of elements from a
        
        mov eax, s
        mov ecx, d
        sub ecx, eax
        mov [ls], ecx
        mov ebx, d
        start_loop1:
            push ecx
            mov eax, 0
            mov al, [ls]
            sub eax, ecx
            add eax, s
            mov ecx, 0
            mov cl, [ld]
            cmp ecx, 0
            je first_elem
                start_loop2:
                    mov edx, 0
                    mov dl, [ld]
                    sub edx, ecx
                    add edx, d
                    mov dl, byte[edx]
                    cmp byte[eax], dl
                    je end_if
                loop start_loop2
                mov al, byte[eax]
                mov byte[ebx], al
                inc byte[ld]
                inc ebx
                jmp end_if
            first_elem:
                mov al, byte[eax]
                mov byte[ebx], al
                inc byte[ld]
                inc ebx
                jmp end_if
            end_if:
            pop ecx
        loop start_loop1
        
        mov esi, s
        mov edi, d
        mov ecx, l_s
        cld
        start_loop:
            mov al, [esi]
            inc esi
            push ecx
            push edi
            mov edi, d
            mov ecx, l_s
            second_loop:
                cmp al, [edi]
                je not_good
            loop second_loop
            pop edi
            mov [edi], al
            inc edi
            jmp good
            not_good:
                pop edi
            good:
                pop ecx
        loop start_loop
    
        push    dword 0  
        call    [exit]   
