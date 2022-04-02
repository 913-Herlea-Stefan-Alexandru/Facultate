bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf         ; add printf as extern function            
import exit msvcrt.dll    
import printf msvcrt.dll    ; tell the assembler that function printf can be found in library msvcrt.dll
import scanf msvcrt.dll     ; similar for scanf

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    n dd  0       ; in this variable we'll store the value read from the keyboard
    ; char strings are of type byte
	message  db "n=", 0  ; char strings for C functions must terminate with 0(value, not char)
	format  db "%d", 0  ; %d <=> a decimal number (base 10)

; our code starts here
segment code use32 class=code
    start:
       ; will call printf(message) => will print "n="
        ; place parameters on stack
        push dword message ; ! on the stack is placed the address of the string, not its value
        call [printf]      ; call function printf for printing
        add esp, 4*1       ; free parameters on the stack; 4 = size of dword; 1 = number of parameters
                                                   
        ; will call scanf(format, n) => will read a number in variable n
        ; place parameters on stack from right to left
        push dword n       ; ! addressa of n, not value
         push dword format
        call [scanf]       ; call function scanf for reading
        add esp, 4 * 2     ; free parameters on the stack
                           ; 4 = size of a dword; 2 = no of perameters
        
        push dword [n]
        push dword format
        call [printf]
        add esp, 4 * 2
        
        ; exit(0)
        push dword 0      ; push on stack the parameter for exit
        call [exit]       ; call exit to terminate the programme