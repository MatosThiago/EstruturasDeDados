O programa foi compilado e executado no SO Ubuntu Linux versões 16.04 e 17.10.

As versões do compilador utilizadas foram:
	gcc (Ubuntu 5.4.0-6ubuntu1) 5.4.0
	gcc (Ubuntu 7.2.0-8ubuntu3) 7.2.0

As bibliotecas utilizadas foram:
	Bibliotecas padrão:
	stdio.h - contém as funções padrão de entrada e saída
	stdlib.h - contém as funções necessárias utilizadas para alocação dinâmica de memória

	Bibliotecas criadas pelo programador:
	stdtask.h - contém as declarações das funções implementadas nos arquivos "stack.c" "expression.c" e "calculator.c"

Instruções de compilação:
	Primeiro os arquivos "stack.c" "expression.c" e "calculator.c" devem ser compilados com o parâmetro -c afim de 
	gerar os arquivos objetos necessários para compilação do arquivo "main.c".

	Sendo assim os arquivos devem ser compilados via terminal da seguinte forma:

	1. gcc -c stack.c		(gerando o arquivo stack.o)
	2. gcc -c expression.c		(gerando o arquivo expression.o)
	3. gcc -c calculator.c		(gerando o arquivo calculator.o)
	4. gcc -o main main.c stack.o expression.o calculator.o		(gerando o arquivo main)

	Após isso o arquivo "main" deve ser executado via terminal da seguinte forma:

	./main