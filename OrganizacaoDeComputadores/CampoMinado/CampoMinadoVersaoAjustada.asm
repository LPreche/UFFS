		.data

matriz:		.word
tam:		.word


msg:		.asciz  "Digite a opção correspondente ao tamanho da matriz desejada (1)8x8 (2)10x10 (3)12x12\nSua Opção:	"
espaco:		.asciz	" "
quebra:		.asciz	"\n"
op_invalida:	.asciz	"Opção invalida, Digite Novamente:	"
traco:		.asciz	"-"

		.text
		
main:
	#Inicio - Seleção de tamanho
	la	a0,msg
	li	a7,4
	ecall
	jal	seleciona_tamanho
	#Fim - seleção de tamanho
	
	
seleciona_tamanho:
	li	a7,5
	ecall
	s
	li	t1,1
	li	a1,8
	
	li	t1,2
	li	a1,10
	
	li	t1,3
	li	a1,12
	
	la	a0,op_invalida
	li	a7,4
	ecall
	j	seleciona_tamanho
	
	
	
	
	
	
	
	
	
	