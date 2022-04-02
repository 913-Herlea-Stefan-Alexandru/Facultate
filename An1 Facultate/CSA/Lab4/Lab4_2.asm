;Given the words A and B, compute the word C as follows:
;- the bits 0-2 of C are the same as the bits 10-12 of B -> isolate 2 bits of B and shift them
;- the bits 3-6 of C have the value 1
;- the bits 7-10 of C are the same as the bits 1-4 of A -> isolate the bits, shift them
;- the bits 11-12 have the value 0
;- the bits 13-15 of C are the invert of the bits 9-11 of B

; We will obtain the word C by successive "isolation" of bits sequences. The isolation
; of the bits 10-12 of B is done by obtaining the unchanged values of these bits,  
; and initialising all other bits to 0. The isolation operation can be performed
; using the operator AND between the word B and the mask
; 0001110000000000. Once isolated, the sequence of bits is put on the right  position by using a rotation operation. 
; The final word is obtained by applying the operator OR between all intermediate results obtained by using isolations and rotations.

; Observation: bits are numbered from right to left

;Given the words A and B, compute the doubleword C as follows:

;the bits 0-4 of C are the same as the bits 11-15 of A
;the bits 5-11 of C have the value 1
;the bits 12-15 of C are the same as the bits 8-11 of B
;the bits 16-31 of C are the same as the bits of A

;Given the words A and B, compute the doubleword C as follows:

;the bits 0-3 of C are the same as the bits 5-8 of B
;the bits 4-8 of C are the same as the bits 0-4 of A
;the bits 9-15 of C are the same as the bits 6-12 of A
;the bits 16-31 of C are the same as the bits of B

bits 32 ;assembling for the 32 bits architecture
; the start label will be the entry point in the program
global  start 

extern  exit ; we inform the assembler that the exit symbol is foreign, i.e. it exists even if we won't be defining it
import  exit msvcrt.dll; exit is a function that ends the process, it is defined in msvcrt.dll
        ; msvcrt.dll contains exit, printf and all the other important C-runtime functions
segment  data use32 class=data ; the data segment where the variables are declared 
     a dw 0111_0111_0101_0111b
     b dw 1001_1011_1011_1110b
     c dw 0
segment  code use32 class=code ; code segment
start: 

     mov  bx, 0 ; we compute the result in bx
     
     ;the bits 0-4 of C are the same as the bits 11-15 of A
     
     mov ax, [a] ;we isolate the bits 
     and ax, 1111_1000_0000_0000b
     mov cl, 11
     shr ax, cl
     or bx, ax
     
     ;the bits 5-11 of C have the value 1
     
     or bx, 0000_1111_1110_0000b
     
     ;the bits 12-15 of C are the same as the bits 8-11 of B

     mov  ax, [b]
     and  ax, 0000_1111_0000_0000b
     mov  cl, 4
     shl  ax, cl
     or   bx, ax
     
     ;the bits 16-31 of C are the same as the bits of A
     
     mov eax, 0
     mov ax, [a]
     shl eax, 16
     or ax, bx
     
     ;-------------------------------------------------------
     
     mov bx, 0
     
     ;the bits 0-3 of C are the same as the bits 5-8 of B
     
     mov ax, [b]
     and ax, 0000_0001_1110_0000b
     mov cl, 5
     shr ax, cl
     or bx, ax
     
     ;the bits 4-8 of C are the same as the bits 0-4 of A
     
     mov ax, [a]
     and ax, 0000_0000_0001_1111b
     mov cl, 4
     shl ax, cl
     or bx, ax
     
     ;the bits 9-15 of C are the same as the bits 6-12 of A
     
     mov ax, [a]
     and ax, 0001_1111_1100_0000b
     mov cl, 3
     shl ax, cl
     or bx, ax
     
     ;the bits 16-31 of C are the same as the bits of B
     
     mov eax, 0
     mov ax, [b]
     shl eax, 16
     or ax, bx

     ;---------------------------------------------------------
     
     or   bx, 0000_0000_0111_1000b ; we force the value of bits 3-6 of the result to the value 1

     mov  ax, [a] ; we isolate bits 1-4 of A
     and  ax, 0000_0000_0001_1110b
     mov  cl, 6
     rol  ax, cl ; we rotate 6 positions to the left
     or   bx, ax ; punem bitii in rezultat

     and  bx, 1110011111111111b ; facem biti 11-12 din rezultat sa aiba valoarea 0

     mov  ax, [b]
     not  ax ; we invert the value of b
     and  ax, 0000111000000000b ; we isolate the bits 9-11 of B
     mov  cl, 4
     rol  ax, cl ; we rotate 4 positions to the left
     or   bx, ax ; punem biti in rezultat

     mov  [c], bx ; we move the result from the register to the result variable

     push dword 0 ;saves on stack the parameter of the function exit
     call [exit] ;function exit is called in order to end the execution of