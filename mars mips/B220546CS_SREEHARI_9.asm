.data
	intro: .asciiz "Enter value of n to find the nth fibonacci number: "
	is_negative: .asciiz "Number is Negative. " 
	fibonacci_msg: .ascii "Fibonacci Number is: "
	
.text
main:
	li $v0 4
	la $a0 intro
	syscall
	
	li $v0 5
	syscall
	move $s0 $v0
	blt $s0 $0 negative_branch
	beq $s0 1 base1
	beq $s0 2 base2
	
	li $t0 0
	li $t1 1
	li $t9 2
	
	loop:
		addi $t9 $t9 1
		bgt $t9 $s0 result	
		add $s1 $t0 $t1 
		move $t0 $t1
		move $t1 $s1
		j loop 
		
	base1:
		li $s1 0
		j result
	
	base2:
		li $s1 1
		j result
		
	negative_branch:
	li $v0 4
	la $a0 is_negative
	syscall
	j end

	result:
	li $v0 4 
	la $a0 fibonacci_msg
	syscall
	li $v0 1
	move $a0 $s1
	syscall
	j end

	end:
	li $v0 10
	syscall