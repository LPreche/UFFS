	.data
vetor1:	.word	9, 8, 7, 6, 5, 4, 3, 2, 1
vetor2: .word	-10, 8, 11, 16, 15, -6, 22
vetor3:	.word	0, 1, 2, 3, 4, 5, 6, 7 , 8, 9

	.text
	
main:
	la 	a0, vetor1
	li 	a1, 9
	jal	ordena
	
	la 	a0, vetor2
	li 	a1, 7
	jal	ordena

	la 	a0, vetor3
	li 	a1, 10
	jal	ordena

	li 	a7, 10   # chamada de sistema para encerrar programa
	ecall 
	
#####################################
# Implemente a função abaixo	
ordena:

	ret
		