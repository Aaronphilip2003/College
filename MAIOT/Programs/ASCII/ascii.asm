mov al,0
mov rdi,num
mov cl,02

up1:mov b1,byte[num]
cmp bl,39h
jbe down1
sub b1,07h

down1:sub b1,30h
rol al,4
add al,bl
inc rdi
dec cx
jnz up1
