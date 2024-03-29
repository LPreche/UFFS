#Aluno: Luiz Paulo Reche      Matricula:2021101059	
		
		.data

campo:		.space	576
interface:	.space	576

tamanho:	.word	0
enderecoRA:	.word	0
salva_S0:	.word	0
salva_ra:	.word	0
salva_ra1:	.word	0
linha:		.word	0
coluna:		.word	0


msg:		.asciz  "  Campo Minado\n1- Campo de 8x8\n2- Campo de 10x10\n3- Campo de 12x12\nSua Opção: "
menu_jogar:	.asciz	"\nJogadas\nA- Abrir posição\nB -Adicionar/Retirar Bandeira\nC -   Sair\nSua opção:  "
msg_abre_pos:	.asciz	"Para abrir uma posição digite a linha e a coluna respectivamente:\n"
msg_linha:	.asciz	"Linha: \n"
msg_coluna:	.asciz	"Coluna: \n"
espaco:		.asciz	" "
quebra:		.asciz	"\n"
op_invalida:	.asciz	"Opcão invalida, Digite Novamente:	"
traco:		.asciz	"-"
op:		.asciz
		
		.text
		
main:
	la	a0,msg
	li	a7,4
	ecall
	
	#seleciona tamanho do campo
	jal	seleciona_tamanho
	la	t1,tamanho
	sw	a0,(t1)
	
	#inicia campo
	la	a0,campo
	lw	a1,tamanho
	jal	inicia_campo
	
	#mostrar campo
	la	a1,campo	#passa endere�o do campo em a1 pois a0 ser� utilizado posteriormente como argumento da chamada de fun��o
	lw	a2,tamanho
	li	t0,0
	li	t1,0
	addi	t2,a2,1
	jal	mostra_campo
	
	#Chama Função Insere bomba
	la	a0,campo
	addi	a1,zero,12	
	jal 	INSERE_BOMBA	
	##########################
	
	li	t0,0
	li	t1,0
	#mostrar campo
	la	a1,campo	#passa endere�o do campo em a1 pois a0 ser� utilizado posteriormente como argumento da chamada de fun��o
	lw	a2,tamanho
	addi	t2,a2,1
	jal	mostra_campo
	##########################
	#iniciando jogo
	la	a0,campo
	lw	a1,tamanho
	jal	jogar

	
	#Fim do programa
	j	encerra_programa
	
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
	mv	a0,a1
	ret 
	
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
	li	t3,9
	mv	a0,t0
	li	a7,1
	ecall
	la	a0,espaco
	li	a7,4
	ecall
	addi	t0,t0,1
	addi	t1,t1,1
	bgt	t0,t3,zera_t0
	bne	t1,t2,mostra_campo
	
	la	a0,quebra
	li	a7,4
	ecall 
	
	li	t0,1
	li	t1,0
	li	t2,0
	
	mv	a0,t0
	li	a7,1
	ecall
	
	la	a0,espaco
	li	a7,4
	ecall
mostra_campo2:
	lw	a0,(a1)
	beq	a0,zero,mostra_traco
	li	a7,1
	ecall
	
	la	a0,espaco
	li	a7,4
	ecall
	
	addi	t1,t1,1
	addi	a1,a1,4
	bne	t1,a2,mostra_campo2
	
	
	li	t1,0
	addi	t2,t2,1
	beq	t2,a2,fim
	
	la	a0,quebra
	li	a7,4
	ecall
	
	beq	t0,t3,zera_t0_2
	addi	t0,t0,1
	
	mv	a0,t0
	li	a7,1
	ecall
		
	la	a0,espaco
	li	a7,4
	ecall

	bne	t2,a2,mostra_campo2

	ret

mostra_traco:
	la	a0,traco
	li	a7,4
	ecall
	
	la	a0,espaco
	li	a7,4
	ecall
	addi	t1,t1,1
	addi	a1,a1,4
	bne	t1,a2,mostra_campo2
	
	li	t1,0
	addi	t2,t2,1
	
	la	a0,quebra
	li	a7,4
	ecall
	
	beq	t2,a2,fim
	beq	t0,t3,zera_t0_2
	
	addi	a0,t0,1
	li	a7,1
	ecall
	la	a0,espaco
	li	a7,4
	ecall
	
	addi	t0,t0,1
		
	bne	t2,a2,mostra_campo2

	j	fim
	
zera_t0:
	li	t0,0
	j	mostra_campo
	
zera_t0_2:
	li	t0,0
	mv	a0,t0
	li	a7,1
	ecall
		
	la	a0,espaco
	li	a7,4
	ecall
	j	mostra_campo2
fim:
	ret
	
INSERE_BOMBA:
		la	t0, salva_S0
		sw  	s0, 0 (t0)		# salva conteudo de s0 na memoria
		la	t0, salva_ra
		sw  	ra, 0 (t0)		# salva conteudo de ra na memoria
		
		add 	t0, zero, a0		# salva a0 em t0 - endereço da matriz campo
		add 	t1, zero, a1		# salva a1 em t1 - quantidade de linhas 

QTD_BOMBAS:
		addi 	t2, zero, 15 		# seta para 15 bombas	
		add 	t3, zero, zero 	# inicia contador de bombas com 0
		addi 	a7, zero, 30 		# ecall 30 pega o tempo do sistema em milisegundos (usado como semente
		ecall 				
		add 	a1, zero, a0		# coloca a semente em a1
INICIO_LACO:
		beq 	t2, t3, FIM_LACO
		add 	a0, zero, t1 		# carrega limite para %	(resto da divisão)
		jal 	PSEUDO_RAND
		add 	t4, zero, a0		# pega linha sorteada e coloca em t4
		add 	a0, zero, t1 		# carrega limite para % (resto da divisão)
   		jal 	PSEUDO_RAND
		add 	t5, zero, a0		# pega coluna sorteada e coloca em t5

###############################################################################
# imprime valores na tela (para debug somente) - retirar comentarios para ver
#	
#		li	a7, 4		# mostra texto "Posicao: "
#		la	a0, posicao
#		ecall
#		
#		li	a7, 1		
#		add 	a0, zero, t3 	# imprime quantidade ja sorteada
#		ecall		
#
#		li	a7, 4		# imrpime :
#		la	a0, dois_pontos
#		ecall
#
#		li	a7, 1
#		add 	a0, zero, t4 	# imprime a linha sorteada	
#		ecall
#		
#		li	a7, 4		# imrpime espaço
#		la	a0, espaco
#		ecall	
#			
#		li	a7, 1
#		add 	a0, zero, t5 	# imprime coluna sorteada
#		ecall
#		
##########################################################################	

LE_POSICAO:	
		mul  	t4, t4, t1
		add  	t4, t4, t5  		# calcula (L * tam) + C
		add  	t4, t4, t4  		# multiplica por 2
		add  	t4, t4, t4  		# multiplica por 4
		add  	t4, t4, t0  		# calcula Base + deslocamento
		lw   	t5, 0(t4)   		# Le posicao de memoria LxC
VERIFICA_BOMBA:		
		addi 	t6, zero, 9		# se posição sorteada já possui bomba
		beq  	t5, t6, PULA_ATRIB	# pula atribuição 
		sw   	t6, 0(t4)		# senão coloca 9 (bomba) na posição
		addi 	t3, t3, 1		# incrementa quantidade de bombas sorteadas
PULA_ATRIB:
		j	INICIO_LACO

FIM_LACO:					# recupera registradores salvos
		la	t0, salva_S0
		lw  	s0, 0(t0)		# recupera conteudo de s0 da memória
		la	t0, salva_ra
		lw  	ra, 0(t0)		# recupera conteudo de ra da memória		
		jr 	ra			# retorna para funcao que fez a chamada
		
##################################################################
# PSEUDO_RAND
# função que gera um número pseudo-randomico que será
# usado para obter a posição da linha e coluna na matriz
# entrada: a0 valor máximo do resultado menos 1 
#             (exemplo: a0 = 8 resultado entre 0 e 7)
#          a1 para o número pseudo randomico 
# saida: a0 valor pseudo randomico gerado
#################################################################
#int rand1(int lim, int semente) {
#  static long a = semente; 
#  a = (a * 125) % 2796203; 
#  return (|a % lim|); 
# }  

PSEUDO_RAND:
		addi t6, zero, 125  		# carrega constante t6 = 125
		lui  t5, 682			# carrega constante t5 = 2796203
		addi t5, t5, 1697 		# 
		addi t5, t5, 1034 		# 	
		mul  a1, a1, t6			# a = a * 125
		rem  a1, a1, t5			# a = a % 2796203
		rem  a0, a1, a0			# a % lim
		bge  a0, zero, EH_POSITIVO  	# testa se valor eh positivo
		addi s2, zero, -1           	# caso não 
		mul  a0, a0, s2		    	# transforma em positivo
EH_POSITIVO:	
		ret				# retorna em a0 o valor obtido
	

jogar:
	mv	s0,a0
	mv	s1,a1
escolhe_jogada:
	la	a0,menu_jogar
	li	a7,4
	ecall
	jal	s2,seleciona_opcao
	
	lbu	t0,(a0)
	li	t1,65
	mv	s0,a0
	mv	s1,a1
	beq	t0,t1,abrir_posicao
	
	li	t1,66
	mv	s0,a0
	mv	s1,a1
	beq	t0,t1,bandeiras
	
	li	t1,83
	beq	t0,t1,encerra_programa
	j	escolhe_jogada
	
seleciona_opcao:
	li	a7,8
	ecall
	lbu	t0,(a0)
	li	t1,65
	beq	t0,t1,opcao_valida
	li	t0,66
	beq	t0,t1,opcao_valida
	li	t0,83
	beq	t0,t1,opcao_valida
	
	la	a0,op_invalida
	li	a7,4
	ecall
	j	seleciona_opcao

opcao_valida:
	jr	s2

abrir_posicao:
	jal	s0,le_posicao_abre
	j	escolhe_jogada
	
bandeiras:
	jal	s0,le_posicao_bandeira
	j	escolhe_jogada
	
le_posicao_abre:
	la	a0,msg_abre_pos
	li	a7,4
	ecall
	la	a0,msg_linha
	li	a7,4
	ecall
	li	a7,5
	ecall
	la	t1,linha
	sw	a0,(t1)
	
	la	a0,msg_coluna
	li	a7,4
	ecall
	li	a7,5
	ecall
	la	t1,coluna
	sw	a0,(t1)
	
	jr	s0
	
le_posicao_bandeira:
	la	a0,msg_abre_pos
	li	a7,4
	ecall
	la	a0,msg_linha
	li	a7,4
	ecall
	li	a7,5
	ecall
	la	t1,linha
	sw	a0,(t1)
	
	la	a0,msg_coluna
	li	a7,4
	ecall
	li	a7,5
	ecall
	la	t1,coluna
	sw	a0,(t1)
	
	jr	s0
encerra_programa:
	li	a7,10
	ecall
	
	

	

	
	
	
	
	
	
	
	
	
