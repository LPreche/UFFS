		.data

campo:		.space	576
tamanho:	.word	0
enderecoRA:	.word	0

msg:		.asciz  "  Campo Minado\n1- Campo de 8x8\n2- Campo de 10x10\n3- Campo de 12x12\nSua Opï¿½ï¿½o: "
espaco:		.asciz	" "
quebra:		.asciz	"\n"
op_invalida:	.asciz	"Opï¿½ï¿½o invalida, Digite Novamente:	"
traco:		.asciz	"-"

		.text
		
main:
	la	a0,msg
	li	a7,4
	ecall
	
	#seleciona tamanho do campo
	jal	seleciona_tamanho
	la	t1,tamanho
	sw	a1,(t1)
	
	#Inicia Campo
	la	a0,campo
	li	t1,0		#Inicia linha
	li	t2,0		#Inicia coluna		
	jal	inicia_campo
	
<<<<<<< HEAD
	#mostrar campo
	la	a1,campo
	lw	a2,tamanho
	li	t1,0
	addi	t2,a2,1
=======
	#mostrar campo inicial
	la	a2,campo	#passa endereço do campo em a2 pois na função há chamadas de sistema, os quais utilizam a0 como argumento de função
	li	t1,0		#Inicia linha
	li	t2,0		#Inicia coluna
>>>>>>> b584f2ca95cfed6dffd1945056bcace489f311fc
	jal	mostra_campo
	
	#Fim do programa
	li	a7,10
	ecall
	
seleciona_tamanho:
	li	a7,5
	ecall
	add	t1,zero,a0
	
	li	t2,1
	li	a1,8
	beq	t1,t2,retorna_tamanho
	
	li	t2,2
	li	a1,10
	beq	t1,t2,retorna_tamanho
	
	li	t2,3
	li	a1,12
	beq	t1,t2,retorna_tamanho
	
	la	a0,op_invalida
	li	a7,4
	ecall
	
	j	seleciona_tamanho
retorna_tamanho:
	ret #retornando tamanho em a1
	
inicia_campo:
	sw	zero,(a0)
	addi	a0,a0,4
	addi	t1,t1,1	
	bne	t1,a1,inicia_campo
	li	t1,0
	addi	t2,t2,1
	bne	t2,a1,inicia_campo
	
	ret
	
mostra_campo:
<<<<<<< HEAD
	mv	a0,t1
	li	a7,1
	ecall
	
	la	a0,espaco
	li	a7,4
	ecall
	
	addi	t1,t1,1
	bne	t1,a2,mostra_campo
	
	la	a0,quebra
	li	a7,4
	ecall

	li	t1,0
	li	t2,0
mostra_campo2:	
	lw	a0,(a1)
	beq	a0,zero,mostra_traco
=======
	la	t3,enderecoRA
	sw	ra,(t3)
	li	t3,0
	jal	mostra_indices_linha
	lw	s0,(a2)
	beq	s0,zero,mostra_traco
	mv	a0,s0
	ret
	
mostra_indices_linha:

	mv	a0,t3
>>>>>>> b584f2ca95cfed6dffd1945056bcace489f311fc
	li	a7,1
	ecall
	
	la	a0,espaco
	li	a7,4
	ecall
<<<<<<< HEAD
	addi	a1,a1,4
	bne	t1,a2,mostra_campo2
	
	li	t1,0
	addi	t2,t2,1
=======
	
	addi	t3,t3,1
	bne	t3,a1,mostra_indices_linha
>>>>>>> b584f2ca95cfed6dffd1945056bcace489f311fc
	
	la	a0,quebra
	li	a7,4
	ecall
	
<<<<<<< HEAD
	
	bne	t2,a2,mostra_campo2
	
=======
>>>>>>> b584f2ca95cfed6dffd1945056bcace489f311fc
	ret

mostra_traco:
	la	a0,traco
	li	a7,4
	ecall
	
	la	a0,espaco
	li	a7,4
	ecall
	addi	a1,a1,4
	bne	t1,a2,mostra_campo2
	
	li	t1,0
	addi	t2,t2,1
	bne	t2,a2,mostra_campo2
	
	ret

	

	
	
	

	
	
	

	

	
	
	
	
	
	
	
	
	
