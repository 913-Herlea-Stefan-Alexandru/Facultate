nasm -fobj modulAsm.asm
nasm -fobj main.asm
alink main.obj modulAsm.obj -oPE -subsys console -entry start
main