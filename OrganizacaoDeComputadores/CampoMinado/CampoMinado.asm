		.data

matriz:		.word
tam:		.word
msg:		.asciz

		.text
		
		
main:
	
	la	a0,msg
	li	a7,4
	ecall
	
	li	a7,5
	ecall
	la 	t1,tam
	sw 	a0,(t1)
	