bits 32
global _third_digit

segment data public data use32
    
segment code public code use32 
_third_digit:
        push ebp
        mov ebp, esp  
        
        mov eax, [esp+8] ;luam parametrul de pe stiva
        mov ecx, dword 3 ;impartim la 10 de 3 ori
        mov ebx, dword 10
        repeat:
            mov edx, 0
            mov edx, dword 0
            div ebx
        loop repeat
        mov eax, edx  ;"returnam" ultimul rest obtinut de la impartirea cu 10
        
        mov esp, ebp
        pop ebp

    ret
    