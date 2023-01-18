%macro rw 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro



section .data
Num_Array db 11h,12h,13h,14h,15h

msg db "Result of array addition is:",10
msgLen equ $-msg

section .bss
Result resw 1
temp resw 2
temp1 resb 1

section .text

global _start

_start:

mov rsi,Num_Array
mov ax,00h ; initializing to 0
mov bx,0h ; initializing to 0
mov cx,5 ; initializing counter to 5 to decrement it later

up2: mov bl,byte[rsi] ; loading content of rsi to the bl register
add ax,bx ; adding contents of b register to accumulator which is initially 0
jnc skip ; go to the skip label if there is no carry
inc ah ; if there is a carry then increment the accumulator

skip: inc rsi ; go to the next number in the array
dec cx ; decrement the counter
jnz up2 ; loop back to the up2 label

mov word[Result],ax
