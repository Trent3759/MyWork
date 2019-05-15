.data
arrayA: .space 64

.text
addi $s1, $zero, 16
la, $s2, arrayA
li $a1, 100
li $v0, 42
la, $s3, arrayA #for sum function

loop:
	syscall
	sw $a0, 0($s2)
	addi $s2, $s2, 4
	addi $s1, $s1, -1
	beqz $s1, sum
	j loop
sum: 
	#results in $v0
	#use $a0 and $a1 for storage 
	addi $s1, $zero, 8 #set counter for sum itterations. 
	addi $v0, $zero, 0
	loopsum: 
		lw, $a0, ($s3)
		lw, $a1, 4($s3)
		add, $t0, $a0, $a1
		add, $v0, $v0, $t0
		addi $s1, $s1, -1
		addi $s3, $s3, 8
		beqz $s1, endsum
		j loopsum
	endsum: 
		add, $t0, $zero, $v0
		li, $v0, 1
		jal main
main: 
	add, $a0, $zero, $t0
	syscall

			
exit:


