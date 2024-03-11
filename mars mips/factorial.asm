.data
	intro: .asciiz "Enter a Number: "
	is_negative: .asciiz "Number is Negative: "
	factorial_msg: .asciiz "Factorial is: "
.text
main:
	li $v0 4
	la $a0 intro
	syscall 
	
	li $v0 5
	syscall
	move $s0 $v0
	
	blt $s0 $0 negative_branch
	li $t0 1
	li $t1 1
	loop:
		addi $t0 $t0 1
		bgt $t0 $s0 result
		mul $t1 $t1 $t0	
		j loop	
	
	negative_branch:
	li $v0 4
	la $a0 is_negative
	syscall 
	j end
	
	result:
	li $v0 4
	la $a0 factorial_msg
	syscall
	li $v0 1
	move $a0 $t1
	syscall
	j end
	
	end:
	li $v0 10
	syscall