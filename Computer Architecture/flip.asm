.data 

str1: .asciiz "Enter a word to flip around: "
str2: .asciiz "Your input: "

.word
.text
main:
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 8
	li $a1, 100
	syscall
	
	move $t0, $a0

	lwl $t1, ($t0)
	li $v0, 4
	la $a0, ($t1)
	syscall
	
	
	
	
