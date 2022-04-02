bits 32 

global start        

extern exit, read_number, third_digit, printf
import exit msvcrt.dll
import printf msvcrt.dll


segment data use32 class=data
    format db "%d ", 0
    result resb 100
    l_result db 0

segment code use32 class=code
    start:
        mov edi, result
        repeta:
            call read_number
            push eax
            push eax
            call third_digit
            add esp, 4*1
            inc byte [l_result]
            stosb
            pop eax
            cmp eax, dword 0
        jne repeta
        
        dec byte [l_result]
        mov ecx, 0
        mov cl, [l_result]
        mov esi, result
        
        cmp ecx, dword 0
        je gata
        repeat:
            mov eax, 0
            lodsb
            pushad
            push eax
            push dword format
            call [printf]
            add esp, 4*2
            popad
        loop repeat
        
        gata:
        
        push    dword 0  
        call    [exit]    
