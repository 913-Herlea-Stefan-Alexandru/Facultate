bits 32
global start        

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

extern base8conv

segment data use32 class=data
    
    number dd 32
    format db "Number %d in base 8: %d; in ascii: %c %s", 0
    end_line db 0xA

segment code use32 class=code
start:
    mov ecx, 126-32+1
    repeat:
        push dword [number]
        call base8conv
        
        pushad
        
        push end_line
        push dword [number]
        push eax
        push dword [number]
        push format
        call [printf]
        add esp, 5*4
        
        popad
        
        inc dword [number]
    loop repeat

    push    dword 0
    call    [exit]
