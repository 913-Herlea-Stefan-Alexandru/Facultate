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
    
    a db 50
    b db 100
    c db 120
    d db 25
    e dw 1000
    x dq 40000000000
    rw resw 1
    rd resd 1

; our code starts here
segment code use32 class=code
    start:
        ; (a*b-2*c*d)/(c-e)+x/a; a,b,c,d-byte; e-word; x-qword
        
        ; signed
        
        mov al, byte[a]
        imul byte[b] ;ax=a*b
        mov cx, ax ;cx=a*b
        mov al, byte[d]
        cbw ;ax=d
        mov bx, ax ;bx=d
        mov al, 2
        imul byte[c] ;ax=2*c
        imul bx ;dx:ax=2*c*d
        mov bx, ax 
        mov ax, cx ;ax=a*b
        mov cx, dx ;cx:bx=2*c*d
        cwd ;dx:ax=a*b
        sub ax, bx
        sbb dx, cx ;dx:ax=(a*b-2*c*d)
        mov bx, ax
        mov cx, dx ;cx:bx=(a*b-2*c*d)
        mov al, byte[c]
        cbw ;ax=c
        sub ax, word[e]
        mov dx, ax ;dx=c-e
        mov ax, bx
        mov bx, dx ;bx=c-e
        mov dx, cx ;dx:ax=(a*b-2*c*d)
        idiv bx ;ax=(a*b-2*c*d)/(c-e)
        mov cx, ax ;cx=(a*b-2*c*d)/(c-e)
        mov al, byte[a]
        cbw
        cwde ;eax=a
        mov ebx, eax
        mov eax, dword[x]
        mov edx, dword[x+4] ;edx:eax=x
        idiv ebx ;eax=x/a
        mov ebx, eax ;ebx=x/a
        mov ax, cx ;ax=(a*b-2*c*d)/(c-e)
        cwde ;eax=(a*b-2*c*d)/(c-e)
        add eax, ebx ;eax=(a*b-2*c*d)/(c-e)+x/a
        
        ; unsigned
        
        mov al, byte[a]
        mul byte[b] ;ax=a*b
        mov cx, ax ;cx=a*b
        mov al, byte[d]
        mov ah, 0
        mov bx, ax ;bx=d
        mov al, 2
        mul byte[c] ;ax=2*c
        mul bx ;dx:ax=2*c*d
        mov bx, ax 
        mov ax, cx ;ax=a*b
        mov cx, dx ;cx:bx=2*c*d
        mov dx, 0
        sub ax, bx
        sbb dx, cx ;dx:ax=(a*b-2*c*d)
        mov bx, ax
        mov cx, dx ;cx:bx=(a*b-2*c*d)
        mov al, byte[c]
        mov ah, 0
        sub ax, word[e]
        mov dx, ax ;dx=c-e
        mov ax, bx
        mov bx, dx ;bx=c-e
        mov dx, cx ;dx:ax=(a*b-2*c*d)
        div bx ;ax=(a*b-2*c*d)/(c-e)
        mov cx, ax ;cx=(a*b-2*c*d)/(c-e)
        mov eax, 0
        mov al, byte[a]
        mov ebx, eax
        mov eax, dword[x]
        mov edx, dword[x+4] ;edx:eax=x
        div ebx ;eax=x/a
        mov ebx, eax ;ebx=x/a
        mov eax, 0
        mov ax, cx ;ax=(a*b-2*c*d)/(c-e)
        add eax, ebx ;eax=(a*b-2*c*d)/(c-e)+x/a
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
