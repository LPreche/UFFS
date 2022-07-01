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
	addi	t0,zero,4
	add	a2,zero,zero
	j	percorre

percorre:
	addi	a2,a2,1
	add	t1,zero,a2
	add	t4,zero,a2
	bne	a2,a1,verifica
	ret
	
verifica:
	
	bne	t1,zero,localiza
	j	percorre
	
	
localiza:
	addi	t1,t1,-1
	mul	t2,t0,t1
	mul	t3,t0,t4
	add	a3,a0,t3
	add	a4,a0,t2
	lw	t5,(a3)
	lw	t6,(a4)
	bge	t6,t5,troca
	
	j	percorre
	
	
troca:	
	sw	t5,(a4)
	sw	t6,(a3)
	addi	t4,t4,-1
	j	verifica
	
	
	
	
	
	
	
