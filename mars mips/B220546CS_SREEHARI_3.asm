.data
	intro: .asciiz "Enter a number: "
	is_negative: .asciiz "Number is negative: "
	success_message: .asciiz "Pallindrome. "
	failure_message: .asciiz "Not Pallindrome. "
.text
main:
	li $v0 4
	la $a0 intro
	syscall
	
	li $v0 5
	syscall
	
	move $s0 $v0
	
	blt $s0 $0 negative_branch
	
	move $s7 $s0                         #saving a copy of the original number in $s7
	li $t0 10
	li $s1 0                             # $s1 is used for storing reverse number
	
	loop:
		ble $s7 $0 result
		div $s7 $t0
		mflo $s7
		mfhi $t1           # $t1 contains the one's place digit
		mul $s1 $s1 $t0    # $s1 = $s1 * 10
		add $s1 $s1 $t1    # $s1 = $s1 + $t1
		j loop
		
	negative_branch:
		li $v0 4
		la $a0 is_negative
		syscall
		j end
		
	result:
		beq $s1 $s0 success_branch
		j failure_branch
	
	success_branch:
		li $v0 4
		la $a0 success_message
		syscall
		j end
	
	failure_branch:
		li $v0 4
		la $a0 failure_message
		syscall
		j end
					
	end:
		li $v0 10
		syscall