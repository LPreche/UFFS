	.data
vetor1:	.word	9, 8, 7, 6, 5, 4, 3, 2, 1
vetor2: .word	-10, 8, 11, 16, 15, -6, 22


	.text
	
main:
	la 	a0, vetor1
	li 	a1, 8
	li 	a2, 0
	jal	shift
	
	la 	a0, vetor2
	li 	a1, 5
	li 	a2, 1
	jal	shift

	li 	a7, 10   # chamada de sistema para encerrar programa
	ecall 
	
#####################################
# Implemente a função abaixo	

shift:

	ret
		
