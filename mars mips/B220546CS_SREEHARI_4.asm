.data
	intro: .asciiz "Enter a number: "
	negative_message: .asciiz "Number is negative "
	result_message: .asciiz "Decimal Equivalent: "
.text
main:
	li $v0 4
	la $a0 intro
	syscall
	
	li $v0 5
	syscall
	
	move $s0 $v0
	blt $s0 $0 negative_branch
	
	li $t0 1 	# $t0 represents 2 raised to different powers
	li $s1 0        # $s1 is the result variable
	
	li $t5 10   	# for dividing number by 10
	loop:
		ble $s0 $0 result
		
		andi $t1 $s0 1    # $t1 = 1 if right most bit is 1, else $t1 = 0
		mul $t1 $t1 $t0   # $t1 = $t1 * $t0   where $t0 is the corresponding
		
		add $s1 $s1 $t1
		
		div $s0 $t5
		mflo $s0
		sll $t0 $t0 1
		
		j loop
	
	negative_branch:
		li $v0 4
		la $a0 negative_message
		syscall 
		j end
		
	result:
		li $v0 4
		la $a0 result_message
		syscall
		
		li $v0 1
		move $a0 $s1
		syscall
		j end
		
	end:
		li $v0 10
		syscall