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

    a db 100
    b dw 20000
    c dd 400000000
    d dq 68719476736
    x resq 1
; our code starts here
segment code use32 class=code
    start:
        ; (b+c+d)-(a+a)
        
        mov ax, [b]
        cwde
        add eax, [c]
        mov ebx, dword[d]
        mov ecx, dword[d+4] ; ecx:edx = d
        cdq ; eax:edx = b+c
        add eax, ebx
        adc edx, ecx ; eax:edx = b+c+d
        mov ebx, eax 
        mov ecx, edx ; ecx:ebx = b+c+d
        mov al, [a]
        add al, [a] ; al = a+a
        cbw
        cwde
        cdq ; edx:eax = a+a
        sub ebx, eax
        sbb ecx, edx ; ecx:ebx = (b+c+d)-(a+a)
        
        ; a + b + c + d - (a + b)

        mov al, [a]
        cbw ; ax = a
        add ax, [b]
        cwde ; eax = a+b
        add eax, [c]
        cdq ; edx:eax = a+b+c
        add eax, dword[d]
        adc edx, dword[d+4] ; edx:eax = a+b+c+d
        mov ebx, eax
        mov ecx, edx ; ecx:ebx = a+b+c+d
        mov al, [a]
        cbw ; ax = a
        add ax, [b]
        cwde
        cdq ; edx:eax = a+b
        sub ebx, eax
        sbb ecx, edx
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
