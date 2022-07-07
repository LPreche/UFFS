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

		.text
		
		
main:
	
	la	a0,msg
	li	a7,4
	ecall
	li	a7,5
	ecall
	la 	t1,tam
	sw 	a0,(t1)
	
	lw	t2,tam
	jal	mostra_campo
	
	
mostra_campo:
	beq	t1,t2,fim
	
	
	
	