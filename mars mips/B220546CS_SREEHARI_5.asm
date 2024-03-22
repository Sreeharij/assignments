.data
	intro: .asciiz "Enter a number "
	negative_message: .asciiz "Number is negative. "
	success_message: .asciiz "PERFECT NUMBER "
	failure_message: .asciiz "Not perfect Number. "
.text
main:
	li $v0 4
	la $a0 intro
	syscall
	
	li $v0 5
	syscall
	
	move $s0 $v0
	move $s1 $s0
	
	blt $s0 $0 negative_branch
	
	
	li $t0 0 #loop variable
	li $t1 2
	div $s1 $t1
	mflo $s1  #upper limit of loop
	
	li $s2 0  #register to store sum
	
	loop:	
		beq $t0 $s1 result
		
		addi $t0 $t0 1
		move $t1 $s0
		
		div $t1 $t0
		mfhi $t9  #reminder variable
		
		bne $t9 $0 loop
		add $s2 $s2 $t0
		j loop
	
	result:
		beq $s0 $s2 success
		j failure
	
	success:
		li $v0 4
		la $a0 success_message
		syscall
		j end
	
	failure:
		li $v0 4
		la $a0 failure_message
		syscall
		j end
	
	negative_branch:
		li $v0 4
		la $a0 negative_message
		syscall
		j end
	
	end:
		li $v0 10
		syscall