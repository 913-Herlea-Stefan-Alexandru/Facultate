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
    
    a dw 1
    b dw 2
    c db 3
    d db 5
    e dd 4
    x dq 6
    r resd 1
    r2 resb 1

; our code starts here
segment code use32 class=code
    start:
        ; 1/a+200*b-c/(d+1)+x/a-e; a,b-word; c,d-byte; e-doubleword; x-qword
        
        ; signed
        
        mov ax, 1
        mov dx, 0
        idiv word[a] ;ax=dx:ax/a -> ax=1/a
        mov bx, ax ; bx=1/a
        mov ax, 200
        imul word[b] ;dx:ax=ax*b -> dx:ax=200*b
        mov cx, bx ;cx=1/a
        mov bx, ax 
        mov ax, cx ;ax=1/a
        mov cx, dx ;cx:bx=200*b
        cwd ; dx:ax=1/a
        add ax, bx
        adc dx, cx ; dx:ax=1/a+200*b
        mov word[r], ax
        mov word[r+2], dx ; r=1/a+200*b (dw)
        mov al, byte[c]
        cbw ; ax=c
        mov bl, byte[d]
        inc bl ; bl=d+1
        idiv bl ;al=c/(d+1)
        cbw
        cwde ;eax=c/(d+1)
        mov ebx, dword[r] ;ebx=1/a+200*b
        sub ebx, eax ;ebx=1/a+200*b-c/(d+1)
        mov dword[r], ebx ;r=1/a+200*b-c/(d+1)
        mov ax, word[a]
        cwde ;eax=a
        mov ebx, eax ;ebx=a
        mov eax, dword[x]
        mov edx, dword[x+4] ;edx:eax=x
        idiv ebx ;eax=x/a
        sub eax, dword[e] ;eax=x/a-e
        add eax, dword[r] ;eax=1/a+200*b-c/(d+1)+x/a-e
        
        ; unsigned
        
        mov ax, 1
        mov dx, 0
        div word[a] ;ax=dx:ax/a -> ax=1/a
        mov bx, ax ; bx=1/a
        mov ax, 200
        mul word[b] ;dx:ax=ax*b -> dx:ax=200*b
        mov cx, bx ;cx=1/a
        mov bx, ax 
        mov ax, cx ;ax=1/a
        mov cx, dx ;cx:bx=200*b
        mov dx, 0 ; dx:ax=1/a
        add ax, bx
        adc dx, cx ; dx:ax=1/a+200*b
        mov word[r], ax
        mov word[r+2], dx ; r=1/a+200*b (dw)
        mov al, byte[c]
        mov ah, 0 ; ax=c
        mov bl, byte[d]
        inc bl ; bl=d+1
        div bl ;al=c/(d+1)
        mov [r2], al
        mov eax, 0
        mov al, [r2] ;eax=c/(d+1)
        mov ebx, dword[r] ;ebx=1/a+200*b
        sub ebx, eax ;ebx=1/a+200*b-c/(d+1)
        mov dword[r], ebx ;r=1/a+200*b-c/(d+1)
        mov eax, 0
        mov ax, word[a] ;eax=a
        mov ebx, eax ;ebx=a
        mov eax, dword[x]
        mov edx, dword[x+4] ;edx:eax=x
        div ebx ;eax=x/a
        sub eax, dword[e] ;eax=x/a-e
        add eax, dword[r] ;eax=1/a+200*b-c/(d+1)+x/a-e
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
