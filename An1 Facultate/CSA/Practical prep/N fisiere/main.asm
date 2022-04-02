bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fread, fprintf, fclose               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    
    input_file db "input.txt", 0
    output_file db "output-i.txt", 0
    write_mode db "w", 0
    read_mode db "r", 0
    file_descriptor dd -1
    array db "abcdefgh", 0
    picked_string resb 8
    n db 0
    

; our code starts here
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
        push dword 1
        push dword 1
        push dword n
        call [fread]
        add esp, 4*4
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        mov al, [n]
        sub al, 30h
        mov [n], al
        
        mov ecx, [n]
        
        repeat:
            push ecx
            
            mov esi, array
            mov edi, picked_string
            
            mov al, cl
            add al, 2Fh
            mov [output_file+7], al
            
            repeat2:
                movsb
            loop repeat2
            
            push dword write_mode
            push dword output_file
            call [fopen]
            add esp, 4*2
            
            push dword picked_string
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*2
            
            push dword [file_descriptor]
            call [fclose]
            add esp, 4
            
            mov edi, picked_string
            mov al, 0
            
            repeat3:
                cmp byte [edi], 0
                je exit_repeat3
                
                mov [edi], al
                inc edi
                jmp repeat3
            exit_repeat3:
            
            pop ecx
        loop repeat
        
        finish:
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
