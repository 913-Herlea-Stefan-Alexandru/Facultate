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
    
    a dd 10
    b dd 0
    message db "Number b = ", 0
    result db "Result of a+a/b=%d", 0
    format db "%d", 0

; our code starts here
segment code use32 class=code
    start:
        ; A natural number a (a: dword, defined in the data segment) is given. Read a natural number b from the keyboard and calculate: a + a/b. Display the result of this operation. The values will be displayed in decimal format (base 10) with sign.
    
        push dword message
        call [printf]
        add esp, 4*1
        
        push dword b
        push dword format
        call [scanf]
        add esp, 4*2
        
        mov eax, [a]
        cdq
        idiv dword [b]
        add eax, [a]
        
        push eax
        push dword result
        call [printf]
        add esp, 4*2
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
