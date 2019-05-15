.data 
charCount: .byte 0
goAgain: .asciiz ""
userInput: .asciiz ""


.text
main:
	la $a0, userInput 
	li $a1, 50
	li $v0, 8
	syscall

endofstr:
	loop:
	lb $t1, ($a0)
	beqz $t1, next #branch if end of string
	addi $a0, $a0, 1 #increment byte address
	j loop

next:
	subi $a0, $a0, 2 #line a0 on the last character of the user string	
	loopNext:
	la $a2, userInput
	lb $t2, ($a2)
	lb $t3, ($a0)
	jal testValues
	
	
testValues:
	bgt $t2, 90, lt97
	j skipa
	lt97: blt $t2, 97, nextT2
	skipa:
	bgt $t2, 122, nextT2
	bgt $t2, 57, lt65
	j skipb
	lt65: blt $t2, 65, nextT2
	skipb:
	blt $t2, 48, nextT2
	#make t2 uppercase
	blt $t2, 97, skip_nextT2
	subi $t2, $t2, 32
	j skip_nextT2
	
	nextT2:
		addi $a2, $a2, 1
		lb $t2, ($a2)
		j testValues
	
	skip_nextT2:
	bgt $t3, 90, lt97b
	lt97b: blt $t3, 97, nextT3
	bgt $t3, 122, nextT3
	bgt $t3, 57, nextT3
	blt $t3, 48, nextT3
	blt $t3, 97, eval
	subi $t3, $t3, 32
	j eval
	
	nextT3:
		subi $a0, $a0, 1
		lb $t3, ($a0)
		j skip_nextT2
	
eval:
	beq $a0, $a2, isPali
	beq $t2, $t3, equal
	j notPali
	
	equal:
		subi $a0, $a0, 1
		addi $a2, $a2, 1
		lb $t2, ($a2)
		lb $t3, ($a0)
		j testValues
	#set T2 to be capital for easier work path. 
	
isPali:
	li $s7, 1
	j exit
	
notPali:
	li $s7, -1
	j exit
	
exit:
	
	
	
	
	
	
	
	
	
	
	
	
