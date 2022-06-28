	.data
vetor1:	.word	9, 8, 7, 6, 5, 4, 3, 2, 1
vetor2: .word	-10, 8, 11, 16, 15, -6, 22


	.text
	
main:
	addi	t0,t0,4
	la 	a0, vetor1
	li 	a1, 8
	li 	a2, 0
	mul	a3,a0,t0
	mul	a4,a0,t0
	jal	shift
	
	la 	a0, vetor2
	li 	a1, 5
	li 	a2, 1
	addi 	a3,a0,4
	jal	shift
	
	li 	a7, 10   # chamada de sistema para encerrar programa
	ecall 
	
#####################################
# Implemente a função abaixo	l=m


shift:
	bne a3,a4,troca
	
	ret
		
troca:
	lw t1,(a3)
	lw t2,(a4)
	
	sw t1,(a3)
	sw t2,(a2)
	
	