	.data
value:	.word	7

	.text
	
main:   		
	la t0, value
	lw a0, 0 (t0)
    jal fibonacci

	li  a7, 1
    nop
    nop
    nop
	ecall

	li  a7, 10
    nop
    nop
    nop
	ecall



####################################
# recebe 1 valor N e retorna o N-esimo fibonacci 
#   entrada: a0
#   saida: a0
####################################	
	
fibonacci:
	addi t1, zero, 1 #fib1
	addi t2, zero, 1 #fib2
	addi t3, zero, 2
	bgt  a0, t3, calcula
	add  s0, zero, t1
	ret 
calcula: 
	beq  t3, a0, terminou
	add  t4, t1, t2 #soma
	add  t1, zero, t2
	add  t2, zero, t4
	addi t3, t3, 1
	j    calcula
terminou:
	add a0, zero, t4
	ret