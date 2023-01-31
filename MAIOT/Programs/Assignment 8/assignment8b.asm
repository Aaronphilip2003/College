%macro scall 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data
Number dw 270Fh
msg db 10d, "Equivalent Hex number is:" ; 10d is newline and 13d is left-align
msglen equ $-msg

section .bss
num resb 5 ; reserved 5 bytes to store hex (need only 4 but use 1 byte as buffer)

section .text
global _start
_start:
mov ax,word[Number]
mov bx,0Ah
mov rdi,num+4

loop3:
mov dx,0 ; clear contents of d-register
div bx
cmp dl,09h
jbe down1
add dl,07h

down1:
add dl,30h
mov [rdi],dl
dec rdi
cmp ax,0 ; check if it is 0 so we can terminate
jne loop3

scall 1,1,msg,msglen
scall 1,1,num,5

exit:
mov rax,60
mov rdx,0
syscall
