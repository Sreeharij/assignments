.data:
	intro: .asciiz "Enter a number to check if it is armstrong or not: "
	is_negative: .asciiz "Number is negative. "
	is_amstromg: .asciiz "Number is armstrong. "
	not_armstrong: .asciiz "Not armstrong. "
	
.text
main:
	li $v0 4
	la $a0 intro
	syscall

	li $v0 5
	syscall 
	move $s0, $v0
	move $s4, $s0
		
	ble $s0, $0, negative_branch
	
	li $s7 10
	li $s5 1
	li $s6 0
	
	loop:
		div $s0 $s7
		mflo $s0
		mfhi $t9
		li $s5 1
		
		mul $s5 $s5 $t9
		mul $s5 $s5 $t9
		mul $s5 $s5 $t9 
		add $s6 $s6 $s5
		ble $s0 $0 result
		j loop
	
	negative_branch:
		li $v0 4
		la $a0 is_negative
		syscall
		j end
	
	result:
		beq $s6 $s4 success
		j failure
		
	success: 
		li $v0 4
		la $a0 is_amstromg
		syscall
		j end
	
	failure:
		li $v0 4
		la $a0 not_armstrong
		syscall
		j end
	
	end:
		li $v0 10
		syscall
