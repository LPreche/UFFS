#Aluno: Luiz Paulo Reche		Matricula: 2021101059
				.data

campo:		.space	576 #aloca espaco para 12x12 posicoes. Campo 
interface:	.space	576 #aloca espaco para 12x12 posicoes. Campo interface do jogador


tamanho:	.word	0
enderecoRA:	.word	0
salva_S0:	.word	0
salva_ra:	.word	0
salva_ra1:	.word	0
linha:		.word	0
coluna:		.word	0


msg:		.asciz  "\n  Campo Minado\n1- Campo de 8x8\n2- Campo de 10x10\n3- Campo de 12x12\nSua Opcao: "
menu_jogar:	.asciz	" \nJogadas\n(A)- Abrir posicao\n(B)- Adicionar/Retirar Bandeira\n(C)-   Sair\nSua opcao:  "
msg_abre_pos:	.asciz	"\nPara abrir uma posição digite a linha e a coluna respectivamente:\n"
msg_bandeira:	.asciz	"\nPara Adicionar uma bandeira Digite a linha e a coluna respectivamente:\nObs:Para remover bandeira, digite a posicao da bandeira.\n"
msg_posicaoinv:	.asciz	"\nPosicao invalida, favor repita a jogada em outra posicao!\n\n"
msg_linha:	.asciz	"\nLinha: \n"
msg_coluna:	.asciz	"\nColuna: \n"
msg_FimDoJogo:	.asciz	"\nbomba explodiu!\n\nFim de jogo!\n"
espaco:		.asciz	" "
quebra:		.asciz	"\n"
op_invalida:	.asciz	"Opcao invalida, Digite Novamente:	"
traco:		.asciz	"-"
Bandeira:	.asciz	"F"
op:		.asciz
		
		.text
		
main:
	la	a0,msg
	li	a7,4
	ecall
	
	#seleciona tamanho do campo
	jal	seleciona_tamanho#Retorna tamanho em a0
	la	t1,tamanho
	sw	a0,(t1)
	
	#Inicia Campo
	la	a0,campo	#Passa endereco do campo em a0
	jal	zera_temporarios	
	jal	inicia_campo	
	
	#Inicia Campo inteface
	la	a0,interface	#Passa endereco do campo interface em a0
	jal	zera_temporarios		
	jal	inicia_interface
	
	#Chama Funcao Insere bomba
	la	a0,campo
	addi	a1,zero,12	
	jal 	INSERE_BOMBA	
	
	##########################

	#chama Funcao para calcular bombas
	jal	zera_temporarios
	la	a0,campo
	lw	a1,tamanho
	jal	calcula_bombas
	
	la	a0,quebra
	li	a7,4
	ecall
	
	la	a0,quebra
	li	a7,4
	ecall
	
	#iniciando jogo
	li	t0,0
	li	t1,0
	la	a0,campo
	lw	a1,tamanho
	jal	jogar

	
	#Fim do programa
	j	encerra_programa
	
zera_temporarios:
	li	t0,0
	li	t1,0
	li	t2,0
	li	t3,0
	li	t4,0
	li	t5,0
	li	t6,0
	ret
	
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
	
inicia_campo: #inicia campo com atributos zerados

	sw	zero,(a0)
	addi	a0,a0,4
	addi	t1,t1,1	

	bne	t1,a1,inicia_campo
	li	t1,0
	addi	t2,t2,1
	bne	t2,a1,inicia_campo
	ret

	
inicia_interface: #inicia o campo interface com a inteiro 11, onde representaria o -
	li	t6,11
	sw	t6,(a0)
	addi	a0,a0,4
	addi	t1,t1,1	
	bne	t1,a1,inicia_interface	
	li	t1,0
	addi	t2,t2,1
	bne	t2,a1,inicia_interface
	ret

	
mostra_campo:#funcao para mostrar campo de ocntrole
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
	
zera_t0:#funcao para zerar os indices quando valor ultrapassar 9
	li	t0,0
	j	mostra_campo
	
zera_t0_2:#funcao para zerar os indices quando valor ultrapassar 9
	li	t0,0
	mv	a0,t0
	li	a7,1
	ecall
		
	la	a0,espaco
	li	a7,4
	ecall
	j	mostra_campo2
	
mostra_interface:#funcao para mostrar o campo do usuario
	li	t3,9
	mv	a0,t0
	li	a7,1
	ecall
	la	a0,espaco
	li	a7,4
	ecall
	addi	t0,t0,1
	addi	t1,t1,1
	bgt	t0,t3,zeraT0Interface
	bne	t1,t2,mostra_interface
	
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
mostra_interface2:
	li	t6,11
	lw	a0,(a1)
	beq	a0,t6,mostra_traco
	li	t6,10
	beq	a0,t6,mostra_bandeira
	
	li	a7,1
	ecall
	
	la	a0,espaco
	li	a7,4
	ecall
	
	addi	t1,t1,1
	addi	a1,a1,4
	bne	t1,a2,mostra_interface2
	
	
	li	t1,0
	addi	t2,t2,1
	beq	t2,a2,fim
	
	la	a0,quebra
	li	a7,4
	ecall
	
	beq	t0,t3,zeraT0Interface2
	addi	t0,t0,1
	
	mv	a0,t0
	li	a7,1
	ecall
		
	la	a0,espaco
	li	a7,4
	ecall

	bne	t2,a2,mostra_interface2

	ret
zeraT0Interface:#funcao para zerar os indices quando valor ultrapassar 9
	li	t0,0
	j	mostra_interface
	
zeraT0Interface2:#funcao para zerar os indices quando valor ultrapassar 9
	li	t0,0
	mv	a0,t0
	li	a7,1
	ecall
		
	la	a0,espaco
	li	a7,4
	ecall
	j	mostra_interface2	
	
mostra_traco:#se na posicao houver o valor 11, vai mostrar -
	la	a0,traco
	li	a7,4
	ecall

	j mostra_caracter

mostra_bandeira:#se na posicao houver o valor 10, vai mostrar F
	la	a0,Bandeira
	li	a7,4
	ecall
		
mostra_caracter:#chama restante da funcao
	la	a0,espaco
	li	a7,4
	ecall
	addi	t1,t1,1
	addi	a1,a1,4
	bne	t1,a2,mostra_interface2
	
	li	t1,0
	addi	t2,t2,1
	
	la	a0,quebra
	li	a7,4
	ecall
	
	beq	t2,a2,fim
	beq	t0,t3,zeraT0Interface2
	
	addi	a0,t0,1
	li	a7,1
	ecall
	la	a0,espaco
	li	a7,4
	ecall
	
	addi	t0,t0,1
		
	bne	t2,a2,mostra_interface2

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
	

calcula_bombas:
	lw	t5,(a0)	
	jal	s0,verificacao
	addi	t1,t1,1
	addi	a0,a0,4
	
	bne	t1,a1,calcula_bombas
	li	t1,0
	addi	t0,t0,1
	bne	t0,a1,calcula_bombas
	ret
	
verificacao:
	li	t6,9
	beq	t5,t6,fim_verificacao
	beq	t1,zero,verifica_abaixo
	
verifica_esquerda1:
	beq	t0,zero,verifica_esquerda2
	addi	t3,t0,-1
	addi	t4,t1,-1
	jal	s1,verifica_bomba

verifica_esquerda2:
	add	t3,t0,zero
	addi	t4,t1,-1
	jal	s1,verifica_bomba
	
verifica_esquerda3:
	addi	t6,a1,-1
	beq	t0,t6,verifica_abaixo
	addi	t3,t0,1
	addi	t4,t1,-1
	jal	s1,verifica_bomba
	
verifica_abaixo:
	addi	t6,a1,-1
	beq	t0,t6,verifica_direita
	addi	t3,t0,1
	add	t4,t1,zero
	jal	s1,verifica_bomba
	
verifica_direita:
	addi	t6,a1,-1
	beq	t1,t6,verifica_acima

verifica_direita3:
	addi	t6,a1,-1
	beq	t0,t6,verifica_direita2
	addi	t3,t0,1
	addi	t4,t1,1
	jal	s1,verifica_bomba

verifica_direita2:
	add	t3,t0,zero
	addi	t4,t1,1
	jal	s1,verifica_bomba
	
verifica_direita1:
	beq	t0,zero,verifica_acima
	addi	t3,t0,-1
	addi	t4,t1,1
	jal	s1,verifica_bomba

verifica_acima:
	beq	t0,zero,fim_verificacao
	addi	t3,t0,-1
	add	t4,t1,zero
	jal	s1,verifica_bomba
	
fim_verificacao:
	jr	s0

verifica_bomba:
	li	t6,9
	la	a2,campo
	li	t2,4
	mul	t2,t2,a1
	mul	t3,t3,t2
	li	t2,4
	mul	t4,t4,t2
	add	t3,t3,t4
	add	a2,a2,t3
	lw	t4,(a2)
	bne	t4,t6,fim_verifica_bomba
tem_bomba:
	addi	t5,t5,1
	sw	t5,(a0)
	
fim_verifica_bomba:
	jr	s1
	
	
jogar:
	
	#mostrar campo interface a cada fim de jogada
	mv	s1,a1
	la	a1,interface	#passa endereco do campo em a1 pois a0 sera utilizado posteriormente como argumento da chamada de fun��o.
	lw	a2,tamanho	#passa tamanho do campo em a2
	jal	zera_temporarios
	addi	t2,a2,1		
	jal	mostra_interface
	mv	a1,s1
	##############################################
	
	la	a0,quebra
	li	a7,4
	ecall
	la	a0,quebra
	li	a7,4
	ecall
	
	mv	s0,a0

	la	a0,menu_jogar
	li	a7,4
	ecall
	
escolhe_jogada:

	jal	s2,seleciona_opcao
	
	lbu	t0,(a0)
	li	t1,65
	beq	t0,t1,abrir_posicao
	
	li	t1,66
	beq	t0,t1,bandeira
	
	li	t1,67
	beq	t0,t1,encerra_programa
	j	escolhe_jogada
	
seleciona_opcao:
	la	a0,op
	li	a7,8
	ecall
	
	lbu	t0,(a0)
	
	li	t1,65
	beq	t0,t1,opcao_valida
	li	t1,66
	beq	t0,t1,opcao_valida
	li	t1,67
	beq	t0,t1,opcao_valida
	
	la	a0,op_invalida
	li	a7,4
	ecall
	j	seleciona_opcao

opcao_valida:
	jr	s2

abrir_posicao:
	la	a0,msg_abre_pos
	li	a7,4
	ecall
	
	li	t4,1
	
	la	a0,msg_linha
	li	a7,4
	ecall
	jal	s0,le_posicao_linha
	
	la	a0,msg_coluna
	li	a7,4
	ecall
	jal	s0,le_posicao_coluna
	
	lw	t0,linha
	lw	t1,coluna
	addi	t0,t0,-1
	addi	t1,t1,-1
	
	li	t2,4
	mul	t2,t2,a1
	mul	t0,t0,t2
	li	t2,4
	
	mul	t1,t1,t2
	add	t0,t0,t1
	
	la	a2,campo
	la	a3,interface
	add	a2,a2,t0
	add	a3,a3,t0
	
	lw	t5,(a2)
	li	t6,10
	beq	t5,t6,posicao_invalida
	li	t6,9
	beq	t5,t6,perdeu
	sw	t5,(a3)
	
	lw	t0,linha
	lw	t1,coluna
	addi	t0,t0,-1
	addi	t1,t1,-1
	
	jal	s0,abre_entorno
	
	j	jogar

abre_entorno:
	beq	t1,zero,abre_abaixo

abre_esquerda:
	beq	t0,zero,abre_esquerda1
	addi	t3,t0,-1
	addi	t4,t1,-1
	jal	s1,abre_pos_entorno

abre_esquerda1:
	add	t3,t0,zero
	addi	t4,t1,-1
	jal	s1,abre_pos_entorno			

abre_esquerda2:
	addi	t6,a1,-1
	beq	t0,t6,abre_abaixo
	addi	t3,t0,1
	addi	t4,t1,-1
	jal	s1,abre_pos_entorno

abre_abaixo:
	addi	t6,a1,-1
	beq	t0,t6,abre_direita_entorno
	addi	t3,t0,1
	add	t4,t1,zero
	jal	s1,abre_pos_entorno

abre_direita_entorno:
	addi	t6,a1,-1
	beq	t1,t6,abre_acima
abre_direita2:
	addi	t6,a1,-1
	beq	t0,t6,abre_direita1
	addi	t3,t0,1
	addi	t4,t1,1
	jal	s1,abre_pos_entorno
abre_direita1:
	add	t3,t0,zero
	addi	t4,t1,1
	jal	s1,abre_pos_entorno
	
abre_direita:
	beq	t0,zero,abre_acima
	addi	t3,t0,-1
	addi	t4,t1,1
	jal	s1,abre_pos_entorno
abre_acima:
	beq	t0,zero,fim_abre_entorno
	addi	t3,t0,-1
	add	t4,t1,zero
	jal	s1,abre_pos_entorno

fim_abre_entorno:
	jr	s0
	
abre_pos_entorno:
	li	t6,9
	
	la	a2,campo
	la	a3,interface
	li	t2,4
	mul	t2,t2,a1
	mul	t3,t3,t2
	li	t2,4
	mul	t4,t4,t2
	add	t3,t3,t4
	
	add	a2,a2,t3
	add	a3,a3,t3
	lw	t5,(a2)
	beq	t5,t6,fim_abre_pos_entorno
	sw	t5,(a3)
fim_abre_pos_entorno:
	jr	s1
	
bandeira:
	la	a0,msg_bandeira
	li	a7,4
	ecall
	li	t4,1
	la	a0,msg_linha
	li	a7,4
	ecall
	jal	s0,le_posicao_linha
	
	la	a0,msg_coluna
	li	a7,4
	ecall
	jal	s0,le_posicao_coluna
	
	lw	t0,linha
	lw	t1,coluna
	addi	t0,t0,-1
	addi	t1,t1,-1

	li	t2,4
	mul	t2,t2,a1
	mul	t0,t0,t2
	li	t2,4
	mul	t1,t1,t2
	add	t0,t0,t1
	
	la	t1,campo
	la	t2,interface
	add	t1,t1,t0
	add	t2,t2,t0
	
	li	t6,10
	lw	t5,(t1)
	beq	t5,t6,remove_bandeira
	sw	t6,(t1)
	sw	t6,(t2)
	j	jogar
	
remove_bandeira:
	sw	zero,(t1)
	sw	zero,(t2)
	j	jogar
	
le_posicao_linha:

	li	a7,5
	ecall
	
	blt	a0,t4,posicao_invalida_linha
	bgt	a0,a1,posicao_invalida_linha
	la	t1,linha
	sw	a0,(t1)

	jr	s0
		
le_posicao_coluna:
	li	a7,5
	ecall
	
	blt	a0,t4,posicao_invalida_linha
	bgt	a0,a1,posicao_invalida_linha
	la	t1,coluna
	sw	a0,(t1)
	
	jr	s0

posicao_invalida_linha:
	la	a0,op_invalida
	li	a7,4
	ecall
	j	le_posicao_linha

posicao_invalida_coluna:
	la	a0,op_invalida
	li	a7,4
	ecall
	j	le_posicao_coluna
posicao_invalida:
	la	a0,msg_posicaoinv
	li	a7,4
	ecall
	
	j	abrir_posicao
	
perdeu:
	la	a0,msg_FimDoJogo
	li	a7,4
	ecall
encerra_programa:
	#mostrar campo interface a cada fim de jogada
	mv	s1,a1
	la	a1,campo	#passa endereco do campo em a1 pois a0 sera utilizado posteriormente como argumento da chamada de fun��o.
	lw	a2,tamanho	#passa tamanho do campo em a2
	jal	zera_temporarios
	addi	t2,a2,1		
	jal	mostra_campo
	mv	a1,s1
	##############################################
	li	a7,10
	ecall
	
	

	

	
	
	
	
	
	
	
	
	
