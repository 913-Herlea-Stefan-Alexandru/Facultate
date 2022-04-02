bits 32                         
segment code use32 public code
global strconv

strconv:
        
           
        mov ebx, [esp + 4]
        mov esi, [esp + 8]
        mov edi, [esp + 12]
        
        mov ecx, 0
        
        mov eax, 0
        lodsb
        cmp al, 0xFF
        je end_do
        do:
            inc ecx
            sub al, 0x61
            mov al, [ebx+eax]
            stosb
            mov eax, 0
            lodsb
            cmp ecx, dword 100
            je end_do
            cmp al, byte 0xFF
            jne do
        end_do:
        
        mov al, 0
        mov [esi], al
        mov [edi], al
        
    ret