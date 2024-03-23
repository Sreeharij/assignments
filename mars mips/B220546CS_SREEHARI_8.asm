.data
	arr: .space 40
	arr_length: .word 40
	intro_msg: .asciiz "Enter an array of 10 elements. "
	element_msg: .asciiz "Enter element to be found. "
	success_msg: .asciiz "Element found at index: "
	failure_msg: .asciiz "Not found. "
.text
main:
	li $v0 4
	la $a0 intro_msg
	syscall
	
	li $t0 0 #index variable

	li $t9 10
	
	la $s0 arr
	
	for_loop:
		beq $t0 $t9 accept_element
		sll $t1 $t0 2
		add $t1 $t1 $s0
		
		li $v0 5
		syscall
		
		sw $v0 0($t1)		
		
		addi $t0 $t0 1
		j for_loop
		
	accept_element:
		li $v0 4
		la $a0 element_msg
		syscall 
		
		li $v0 5
		syscall
		move $s1 $v0   # $s1 is the element to be found
		li $t0 0
		j search
		
	search:
		beq $t0 $t9 failure
		sll $t1 $t0 2
		add $t1 $t1 $s0
		
		lw $t2 0($t1)
		beq $t2 $s1 success
		addi $t0 $t0 1
		j search
		
	success:
		li $v0 4
		la $a0 success_msg
		syscall
		
		li $v0 1
		move $a0 $t0
		syscall 
		j end
	
	failure:
		li $v0 4
		la $a0 failure_msg
		syscall 
		j end
	end:
		li $v0 10
		syscall