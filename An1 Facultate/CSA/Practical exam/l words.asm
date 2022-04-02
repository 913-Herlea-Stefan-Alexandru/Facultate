bits 32

global start        

extern exit, fopen, fread, fclose
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll

extern scanf, printf
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    
    input_file db "cuvinte.txt", 0
    read_mode db "r", 0
    file_descriptor dd -1
    string_format db "%s", 0
    number_format db "%d", 0
    end_line db 10, 0
    L dd 0
    words resb 100
    chosen_word resb 100
    word_len db 0
    error_message db "The number given is odd!", 0
    
    
segment code use32 class=code
    start:
        
        push dword read_mode
        push dword input_file
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0
        je finish
        
        push dword [file_descriptor]
        push dword 100
        push dword 1
        push dword words
        call [fread]
        add esp, 4*4
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        push dword L
        push dword number_format
        call [scanf]
        add esp, 4*2
        
        mov eax, [L]
        mov edx, 0
        mov ecx, 2
        div ecx
        
        cmp edx, 0
        je no_error
        
        push dword error_message
        call [printf]
        add esp, 4
        
        jmp finish
        
        no_error:
        mov esi, words
        mov edi, chosen_word
        
        repeat:
            lodsb
            
            cmp al, 0
            je check
            
            stosb
            
            cmp al, ' '
            jne no_add
            
            check:
            cmp byte [edi-1], ' '
            jne no_dec
            
            dec edi
            
            no_dec:
            sub edi, chosen_word
            mov ecx, edi
            
            cmp ecx, dword [L]
            jne empty_text
            
            pushad
            
            push dword chosen_word
            call [printf]
            add esp, 4
            
            push dword end_line
            call [printf]
            add esp, 4
            
            popad
            
            empty_text:
            mov edi, chosen_word
            mov cl, 0
            repeat2:
                cmp byte [edi], 0
                je end_repeat2
                
                mov [edi], cl
                inc edi
                jmp repeat2
            end_repeat2:
            mov edi, chosen_word
            cmp al, 0
            je end_repeat
            no_add:
            jmp repeat
        end_repeat:
        
        finish:
        
        push    dword 0
        call    [exit]
