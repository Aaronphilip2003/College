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
Result resw 1 ; 2bytes=16bit=1word
temp resw 2
temp1 resb 1

section .text

global _start

_start: ; label - indicates that execution of code starts from this label

mov rsi,Num_Array
mov ax,00h ; initializing to 0
mov bx,0h ; initializing to 0
mov cx,5 ; initializing counter to 5 to decrement it later

up2: mov bl,byte[rsi] ; loading content of rsi to the bl register, []- called as mem addressing mode indicates value at that address
add ax,bx ; adding contents of b register to accumulator which is initially 0
jnc skip ; go to the skip label if there is no carry
inc ah ; if there is a carry then increment the accumulator

skip: inc rsi ; go to the next number in the array
dec cx ; decrement the counter
jnz up2 ; loop back to the up2 label

mov word[Result],ax
mov bp,4
up: rol ax,4
mov bx,ax
and ax,0Fh
cmp al,09
jbe down
add al,07h

down: add al,30h
mov byte[temp],al
rw 1,1,temp,1
mov ax,bx
dec bp
jnz up
rw 60,0,0,0 ; if we dont write this termination code we will get a segmentation fault error

; ans of the addition above is 5F
; to print any value on the screen we need its ascii value
; 5F- 35,46 (ASCII values of 5 and F respectively)	 ( 35 = 30+5) so we need to add 30
; 0-9 ASCII values are 30-39H (we need to add 30 to get ASCII value)
; A-F ASCII values are 41-46H (we need to add 37 to get ASCII value)
; we will first need to separate the 5 and separate the F (5F)
; this is done using masking (AND the number)
; andding any number with 0 will give 0 and annding any number with F(value is 1) will give the number itself
; rotate for higher digit
