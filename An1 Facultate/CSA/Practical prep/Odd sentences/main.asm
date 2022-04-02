bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fread, fprintf, fclose             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    
    file_in db "in.txt", 0
    file_out db "out.txt", 0
    file_descriptor dd -1
    read_access db "r", 0
    write_access db "a", 0
    sentences resb 100
    text resb 100
    
; our code starts here
segment code use32 class=code
    start:
        
        push dword read_access
        push dword file_in
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0
        je finish
        
        push dword [file_descriptor]
        push dword 100
        push dword 1
        push dword sentences
        call [fread]
        add esp, 4*4
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        mov ebx, 1
        
        mov esi, sentences
        mov edi, text
        
        repeat:
            lodsb
            
            cmp al, 0
            je break
            
            stosb
            
            cmp al, '!'
            jne no_add
            
            mov eax, ebx
            mov edx, 0
            mov ecx, 2
            div ecx
            
            cmp edx, 0
            je empty_text
            
            push dword write_access
            push dword file_out
            call [fopen]
            add esp, 4*2
             
            mov [file_descriptor], eax
            
            cmp eax, 0
            je finish
            
            push dword text
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*2
            
            push dword [file_descriptor]
            call [fclose]
            add esp, 4
            
            empty_text:
            mov edi, text
            mov al, 0
            repeat2:
                cmp byte [edi], 0
                je exit_repeat2
                
                mov [edi], al
                inc edi
                jmp repeat2
            exit_repeat2:
            mov edi, text
            inc ebx
            no_add:
            jmp repeat
            
        break:
        
        finish:
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
