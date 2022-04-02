bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    file_name db "problem8.txt", 0
    access_mode db "r", 0
    
    file_descriptor dd -1
    len equ 100
    text times (len+1) db 0
    format db "The most frequent upper case character is: %s, appearing %d times", 0
    result times (len+1) dw 0
    len_r dd 0
    max_let db "", 0

; our code starts here
segment code use32 class=code
    start:
        ; A text file is given. Read the content of the file, determine the uppercase letter with the highest frequency and display the letter along with its frequency on the screen. The name of text file is defined in the data segment.
        
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0
        je final
        
        push dword [file_descriptor]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        mov ecx, eax
        mov esi, text
        mov ebx, 0
        
        cld
        start_loop:
            lodsb
            cmp al, 'A'
            jb not_good
                cmp al, 'Z'
                ja not_good
                    push ecx
                    mov ecx, [len_r]
                    mov edi, result
                    cmp ecx, 0
                    je add_letter
                    check_loop:
                        scasb
                        je skip_add
                        inc edi
                    loop check_loop
                    add_letter:
                        stosb
                        inc dword[len_r]
                    skip_add:
                    inc byte[edi]
                    cmp bh, byte[edi]
                    ja no_change
                        mov bx, word[edi-1]
                    no_change:
                    pop ecx
            not_good:
        loop start_loop
        
        mov [max_let], bl
        mov bl, bh
        mov bh, 0
        
        push ebx
        push dword max_let
        push dword format
        call [printf]
        add esp, 4*3
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        final:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
