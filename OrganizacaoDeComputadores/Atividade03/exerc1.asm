	.data
vetor1:	.word	9, 8, 7, 6, 5, 4, 3, 2, 1
vetor2: .word	-10, 8, 11, 16, 15, -6, 22


	.text
	
main:
	addi t0,t0,4
	la 	a0, vetor1
	li 	a1, 8
	li 	a2, 0
	jal	swap
	
	la 	a0, vetor2
	li 	a1, 5
	li 	a2, 1
	jal	swap

	li 	a7, 10   # chamada de sistema para encerrar programa
	ecall 
	
#####################################
# Implemente a função abaixo	
swap:

	mul t1,t0,a1
	add a3,a0,t1
	lw t1,(a3)
	
	mul t2,t0,a2
	add a4,a0,t2
	lw t2,(a4)
	
	sw t1,(a4)
	sw t2,(a3)
	
	ret
		
