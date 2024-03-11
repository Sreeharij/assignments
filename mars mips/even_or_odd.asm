.data
	odd: .asciiz "Number is ODD"
	even: .asciiz "Number is EVEN"
	intro: .asciiz "Enter a number: "
	is_negative: .asciiz "Number is negative"
.text
main:
	li $v0, 4
	la $a0, intro
	syscall
	
	li $v0, 5 
	syscall
	move $t1, $v0
	blt $t1, $0 negative_branch

	li $t0, 2 
	div $t1, $t0
	mfhi $t2 
	
	li $t3, 1 
	beq $t2, $t3 odd_branch
	li $v0, 4
	la $a0, even
	syscall
	j end
		
	odd_branch:
	li $v0, 4
	la $a0, odd
	syscall 
	j end
	
	negative_branch:
	li $v0, 4
	la $a0, is_negative
	syscall
	j end
	  
	end:
	li $v0 10
	syscall 
