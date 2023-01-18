%macro write 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro read 2
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro



section .data
msg db "Enter your name",10
msgLen equ $-msg

clg db "Enter your college",10
clgLen equ $-clg

roll db "Enter your roll no.",10
rollLen equ $-roll

msg3 db "Your name is: "
msg3Len equ $-msg3

msg4 db "Your college is: "
msg4Len equ $-msg4

msg5 db "Your Roll no. is: "
msg5Len equ $-msg5


section .bss
nameVar resb 20
clgVar resb 20
rollVar resb 20

section .text

global _start

_start:

write msg,msgLen
read nameVar,20

write clg,clgLen
read clgVar,20

write roll,rollLen
read rollVar,20

write msg3,msg3Len
write nameVar,20

write msg4,msg4Len
write clgVar,20

write msg5,msg5Len
write rollVar,20


mov rax,60
mov rdi,0
syscall
