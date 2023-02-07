%macro operate 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data
msg db "Sorted Array is:",10
msglen equ $-msg
arr db 05h,0Ah,75h,0D3h,12h

section .bss
result resb 15 ; 3x5 = 15

section .text
global _start
_start:
mov bl,5 ; 5 iterations for outer loop
loop_outer:mov cl,4 ; 4 iterations for inner loop
mov rsi,arr

up:mov al,byte[rsi]
cmp al,byte[rsi+1]
jbe only_inc
xchg al,byte[rsi+1]
mov byte[rsi],al

only_inc:inc rsi
dec cl
jnz up
dec bl
jnz loop_outer
operate 1,1,msg,msglen

mov rdi,arr ; unpacking
mov rsi,result
mov dl,10 ; for one number there are 2 digits

disp_loop1:
mov cl,2
mov al,[rdi]

againx:
rol al,4
mov bl,al
and al,0Fh
cmp al,09h
jbe downx
add al,07h

downx:
add al,30h
mov byte[rsi],al
mov al,bl
inc rsi
dec cl
jnz againx


mov byte[rsi],0Ah
inc rsi
inc rdi
dec dl
jnz disp_loop1
operate 1,1,result,15

operate 60,0,0,0

