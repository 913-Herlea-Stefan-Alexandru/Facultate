bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fprintf, fclose
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    file_name db "problem23.txt", 0
    access_mode db "w", 0
    
    file_descriptor dd -1
    n dw 0x9AD0
    end_line db 0xD, 0
    format db "%x%s", 0

; our code starts here
segment code use32 class=code
    start:
        ; A file name and a hexadecimal number (on 16 bits) are given. Create a file with the given name and write each nibble composing the hexadecimal number on a different line to file.
    
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0
        je final
        
        mov ebx, 0
        mov bx, [n]
        
        mov ecx, 4
        
        start_loop:
            mov eax, ebx
            and eax, 1111b
            pushad
            
            push dword end_line
            push eax
            push dword format
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*4
            
            popad
            shr ebx, 4
        loop start_loop

        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        final:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
