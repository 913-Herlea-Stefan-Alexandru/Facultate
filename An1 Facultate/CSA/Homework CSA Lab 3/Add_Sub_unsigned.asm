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
        ; (a+b-d)+(a-b-d)
        
        mov eax, 0 ; eax = 00 00 00 00
        mov al, [a]
        add ax, [b] 
        mov edx, 0  ; edx:eax = a + b 
        mov ebx, dword[d]
        mov ecx, dword[d+4] ; ecx:ebx = d 
        sub eax, ebx
        sbb edx, ecx ; edx:eax = (a+b-d)
        mov dword[x], eax
        mov dword[x+4], edx ; x = (a+b-d)
        mov eax, 0
        mov al, [a]
        sub ax, [b]; ax = a-b 
        mov edx, 0 ; edx:eax = a-b 
        mov ebx, dword[d]
        mov ecx, dword[d+4] ; ecx:ebx = d 
        sub eax, ebx
        sbb edx, ecx ; edx:eax = (a-b-d)
        add eax, dword[x]
        adc edx, dword[x+4] ; edx:eax = (a+b-d)+(a-b-d)
        
        ; ((a + a) + (b + b) + (c + c)) - d
        
        mov eax, 0
        mov al, [a]
        add al, [a] ; al = (a + a)
        mov ebx, 0
        mov bx, [b]
        add bx, [b] ; bx = (b + b)
        add ax, bx ; ax = (a + a) + (b + b)
        mov ebx, [c]
        add ebx, [c] ; ebx = (c + c)
        add eax, ebx ; eax = ((a + a) + (b + b) + (c + c))
        mov edx, 0 ; edx:eax = ((a + a) + (b + b) + (c + c))
        mov ebx, dword[d]
        mov ecx, dword[d+4] ; ecx:ebx = d
        sub eax, ebx
        sbb edx, ecx ; edx:eax = ((a + a) + (b + b) + (c + c)) - d
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
