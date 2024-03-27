.data
	intro: .asciiz "Enter a string: "
	string_array: .space 40
	string_array_size: .word 40

.text
main:
	li $v0 4
	la $a0 intro
	syscall
	 
	li $v0 8
	la $a0 string_array
	lw $a1 string_array_size
	syscall

	li $t0 -1
	
	loop:
		addi $t0 $t0 1
		lb $t9 string_array($t0)

  		beq $t9 32 loop
 		beq $t9 10 result

		subi $t9 $t9 32
		sb $t9 string_array($t0)
		
		j loop

	result:
		li $v0 4
		la $a0 string_array
		syscall
		j end
	
	end:
		li $v0 10
		syscall