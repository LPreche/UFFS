		.data

matriz:		.space	576
tamanho:	.word


msg:		.asciz  "  Campo Minado\n1- Campo de 8x8\n2- Campo de 10x10\n3- Campo de 12x12\nSua Opção: "
espaco:		.asciz	" "
quebra:		.asciz	"\n"
op_invalida:	.asciz	"Opção invalida, Digite Novamente:	"
traco:		.asciz	"-"

		.text
		
main:
	la	a0,msg
	li	a7,4
	ecall
	
	#seleciona tamanho do campo
	jal	seleciona_tamanho
	
	#Inicia Campo
	la	a0,matriz
	la	a1,tamanho
	li	t1,0#linha
	li	t2,0#coluna		
	jal	inicia_campo
	
	
	#Fin do programa
	li	a7,10
	ecall
	
seleciona_tamanho:
	li	a7,5
	ecall
	add	t1,zero,a0
	
	li	t2,1
	li	a1,8
	beq	t1,t2,grava_tamanho
	
	li	t2,2
	li	a1,10
	beq	t1,t2,grava_tamanho
	
	li	t2,3
	li	a1,12
	beq	t1,t2,grava_tamanho
	
	la	a0,op_invalida
	li	a7,4
	ecall
	
	j	seleciona_tamanho
	
grava_tamanho:
	la	t1,tamanho
	sw	a1,(t1)
	ret
	
inicia_campo:
	mv	a0,t1
	
	
	
	ret

	
	
	

	

	
	
	
	
	
	
	
	
	
