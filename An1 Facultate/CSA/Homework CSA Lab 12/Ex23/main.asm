bits 32
global start

import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll
extern scanf, printf, exit

extern strconv

segment data use32
    
    alphabet db "OPQRSTUVWXYZABCDEFGHIJKLMN", 0
    s1 times 100 db 0xFF
    result_string times 100 db 0xFF
    read_format db "%s", 0
    print_format db "The result string is: %s", 0
    
segment code use32 public code
start:
    push dword s1
    push dword read_format
    call [scanf]
    add esp, 2*4
    
    push result_string
    push s1
    push alphabet
    call strconv
    
    push dword result_string
    push dword print_format
    call [printf]
    add esp, 2*4
    
	push 0
	call [exit]