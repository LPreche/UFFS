	.data
vetor1:	.word	9, 8, 7, 6, 5, 4, 3, 2, 1
vetor2: .word	-10, 8, 11, 16, 15, -6, 22


	.text
	
main:
	addi 	t0,t0,4
	la 	a0, vetor1
	li 	a1, 8
	li 	a2, 0
	mul	t1,t0,a1
	add	a3,a0,t1
	jal	shift
	
	la 	a0, vetor2
	li 	a1, 5
	li 	a2, 1
	mul	t1,t0,a1
	add	a3,a0,t1
	jal	shift
	
	li 	a7, 10   # chamada de sistema para encerrar programa
	ecall 
	
#####################################
# Implemente a função abaixo	l=m


shift:

	bne	a1,a2,troca
	
	ret
		
troca:
	addi	a4,a3,-4
	lw	t1,(a3)
	lw	t2,(a4)
	
	sw	t1,(a4)
	sw	t2,(a3)
	
	addi	a3,a3,-4
	addi	a1,a1,-1
	
	j shift
	
	
