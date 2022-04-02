bits 32
segment code use32 public code
global _base8conv

_base8conv:
        push ebp
        mov ebp, esp
        
        mov eax, [esp + 8]
        mov edx, 0
        mov ebx, 0
        push ecx
        mov ecx, 1
        do:
            push ecx
            mov ecx, 8
            div ecx
            pop ecx
            push eax
            mov eax, edx
            mul ecx
            add ebx, eax
            mov eax, ecx
            mov ecx, 10
            mul ecx
            mov ecx, eax
            pop eax
            mov edx, 0
            cmp eax, dword 0
            jne do
        pop ecx
        mov eax, ebx
        
        mov esp, ebp
        pop ebp
        
    ret