bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    
    a db 0F1h, 0ABh
    l equ $-a
    format db "%d", 0
    s2 times l*8 db 0
    space db ' ', 0

; our code starts here
segment code use32 class=code
    start:
        
        mov esi, a
        cld
        mov ecx, l
        
        mov edi, s2
        loop1:
            push ecx
        
            lodsb
            
            base_2_conv:
                cmp al, 0
                je done_conv
                
                mov cl, 1
                shl al, cl
                jnc no_change
                mov [edi], cl
                
                no_change:
                inc edi
                
                jmp base_2_conv
                
            done_conv:
            push esi
            mov ebx, edi
            sub ebx, 8
            mov esi, ebx
            mov ecx, 8
            cld
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
            
            push dword space
            call [printf]
            add esp, 4
            
            pop esi
            pop ecx
            
        loop loop1
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
