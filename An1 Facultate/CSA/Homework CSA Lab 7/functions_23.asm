bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll    ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import scanf msvcrt.dll 

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    a db 0
    message db "Number a = ", 0
    format db "%x", 0
    result1 db "Unsigned decimal = %d    ", 0
    result2 db "Signed decimal = %d", 0

; our code starts here
segment code use32 class=code
    start:
        ; Read a hexadecimal number with 2 digits from the keyboard. Display the number in base 10, in both interpretations: as an unsigned number and as an signed number (on 8 bits).
        
        push dword message
        call [printf]
        add esp, 4*1
        
        push dword a
        push dword format
        call [scanf]
        add esp, 4*2
        
        mov eax, 0
        mov al, [a]
        
        push eax
        push dword result1
        call [printf]
        add esp, 4*2

        mov eax, 0
        mov al, [a]
        cbw
        cwde
        
        std
        push eax
        push dword result2
        call [printf]
        add esp, 4*2
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
