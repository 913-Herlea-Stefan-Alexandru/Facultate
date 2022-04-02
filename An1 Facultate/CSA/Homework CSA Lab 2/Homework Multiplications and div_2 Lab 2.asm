bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    a db 8
    b db 6
    c db 4
    d db 2
    e dw 5
    f dw 3
    g dw 14
    h dw 26

; our code starts here
segment code use32 class=code
    start:
        ; 2*(a+b)-e
        
        mov al, [a]
        add al, [b]
        mov cl, 2
        mul cl
        sub ax, [e]
        
        ; [(a+b)*2]/(a+d)

        mov al, [a]
        add al, [b]
        mov cl, 2
        mul cl
        mov bl, [a]
        add bl, [d]
        div bl
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
