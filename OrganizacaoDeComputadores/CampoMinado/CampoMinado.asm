		.data

matriz:		.word	1,2,3,4,5,6,7,8
		.word	8,7,6,5,4,3,2,1
		.word	1,2,3,4,5,6,7,8
		.word	8,7,6,5,4,3,2,1
		.word	1,2,3,4,5,6,7,8
		.word	8,7,6,5,4,3,2,1
		.word	1,2,3,4,5,6,7,8
		.word	8,7,6,5,4,3,2,1	
tam:		.word


msg:		.asciz  "Digite a opção correspondente ao tamanho da matriz desejada\n"
espaco:		.asciz	" "
quebra:		.asciz	"\n"
		.text
		
		
main:
	
	la	a0,msg
	li	a7,4
	ecall
	li	a7,5
	ecall
	la 	t1,tam
	sw 	a0,(t1)
	li	t1,0
	lw	t2,tam
	la	a1,matriz
	jal	mostra_campo
	
	li	a7,10
	ecall
	
mostra_campo:
	beq	t3,t2,fim
	beq	t4,t2,Avanca_coluna
	
	
	lw	a0,(a1)
	li	a7,1
	ecall
	la	a0,espaco
	li	a7,4
	ecall
	
	addi	t5,zero,4
	mul	t5,t5,t1
	add	a1,a1,t5
	
	addi	t1,t1,1
	j	mostra_campo
Avanca_coluna:
	addi	t3,t3,1	
	la	a0,quebra
	li	a7,4
	ecall
	
	j	mostra_campo
	
	
fim:
	ret
	
	
	
	
	
	
	
	
