		.data

matriz:		.word	1,1,1,1,1,1,1,1
		.word	1,1,1,1,1,1,1,1
		.word	1,1,1,1,1,1,1,1
		.word	1,1,1,1,1,1,1,1
		.word	1,1,1,1,1,1,1,1
		.word	1,1,1,1,1,1,1,1
		.word	1,1,1,1,1,1,1,1
		.word	1,1,1,1,1,1,1,1	
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
	jal	inicia_campo
	jal	mostra_campo
	
	li	a7,10
	ecall
	
	
	
inicia_campo:
	beq	t1,t2,fim
	
mostra_campo:
	beq	t3,t2,fim
	beq	t1,t2,Avanca_coluna

	lw	a0,(a1)
	li	a7,1
	ecall
	la	a0,espaco
	li	a7,4
	ecall
	
	addi	t1,t1,1
	
	addi	a1,a1,4
	
	j	mostra_campo
Avanca_coluna:
	li	t1,0
	addi	t3,t3,1	
	la	a0,quebra
	li	a7,4
	ecall
	
	j	mostra_campo
	


fim:
	ret
	
	
	
	
	
	
	
	
