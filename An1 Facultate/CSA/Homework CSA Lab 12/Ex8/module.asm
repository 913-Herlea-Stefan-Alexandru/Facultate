bits 32
segment code use32 public code
global base8conv

base8conv:
    mov eax, [esp + 4]
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
    ret 4
    