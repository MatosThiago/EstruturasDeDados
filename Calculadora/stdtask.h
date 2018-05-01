#ifndef __STDTASK_H__
#define __STDTASK_H__

/**
  * @file stdtask.h
  * @author Thiago Santos Matos
  * @date 25 de outubro de 2017
  *
  * @brief Este arquivo contém as declarações de todas as funções implementadas
  *
  * Todas as funções implementadas nos arquivos "stack.c", "expression.c" e
  * "calculator.c" estão declaradas neste arquivo.
  **/


/**
  * @brief Estrutura de tipo elemento
  *
  * Nesta estrutura é armazenado um dado no formato float e um ponteiro para o
  * próximo elemento.
  **/
typedef struct element {
  float data; /* dado armazenado na estrutura elemento */
  struct element* next; /* ponteiro para o próximo elemento */
} T_element;
/**
  * @brief  Estrutura de tipo pilha
  *
  * Nesta estrutura é armazenado o endereço do elemento que está no topo
  * da pilha.
  **/
typedef struct stack {
  T_element* top; /* ponteiro para o elemento no topo da pilha */
} T_stack;


/**
  * @brief Aloca de forma dinâmica uma estrutura de tipo pilha
  *
  * Aloca de forma dinâmica uma estrutura de tipo pilha e configura o ponteiro
  * para o elemento no todo da pilha como NULL.
  *
  * @param void: não recebe nenhum parâmetro
  * @return T_stack*: ponteiro para a estrutura de tipo pilha alocada
  **/
T_stack* allocstack();
/**
  * @brief Aloca de forma dinâmica uma estrutura de tipo elemento
  *
  * Aloca de forma dinâmica uma estrutura de tipo elemento e configura o dado
  * armazenado nela como D, e o ponteiro para o próximo como NULL.
  *
  * @param float D: dado à ser armazenado na estrutura de tipo elemento
  * @return T_element*: ponteiro para a estrutura de tipo elemento alocada
  **/
T_element* allocelement(float D);
/**
  * @brief Verifica se a pilha está vazia
  *
  * Retorna 1 se o topo da pilha aponta para NULL e 0 caso contrário.
  *
  * @param T_stack* stack: estrutura de tipo pilha que será verificada
  * @return int: identifica se a pilha está vazia
  **/
int emptystack(T_stack* stack);
/**
  * @brief Empilha um elemto na pilha
  *
  * Executa a função allocelement, configura o ponteiro para o próximo do
  * elemento alocado como o elemento no topo da pilha e aponta o topo da pilha
  * para o elemento alocado.
  *
  * @param T_stack* stack: estrutura de tipo pilha na qual o elemento será empilhado
  * @param float D: dado que será armazenado na estrutura de tipo elemento
  * @return void: não retorna nenhum valor
  **/
void push(T_stack* stack, float D);
/**
  * @brief Remove um elemento da pilha
  *
  * Retira o elemento que está no topo da pilha, apontando o topo da pilha para
  * o próximo elemento, e retorna o dado armazenado no elemento retirado.
  *
  * @param T_stack* stack: pilha da qual o elemento será retirado
  * @return float: dado armazenado no elemento retirado
  **/
float pop(T_stack* stack);
/**
  * @brief Exibe a pilha
  *
  * Exibe todods os dados armazenados nos elementos da pilha.
  *
  * @param T_stack* stack: pilha à ser exibida
  * @return void: não retorna nenhum valor
  **/
void printstack(T_stack* stack);
/**
  * @brief Libera os elementos da pilha
  *
  * Libera apenas os elementos da pilha, mantendo a estrutura de pilha
  * previamente alocada.
  *
  * @param T_stack* stack: pilha da qual os elementos serão liberados
  * @return void: não retorna nenhum valor
  **/
void freeelements(T_stack* stack);
/**
  * @brief Libera a pilha e seus elementos
  *
  * Libera os elementos da pilha e a pilha.
  *
  * @param T_stack* stack: pilha que será liberada
  * @return void: não retorna nenhum valor
  **/
void freestack(T_stack* stack);


/**
  * @brief Recebe e soluciona a expressão
  *
  * Recebe a expressão do usuário e executa as funções necessárias para
  * solucionar a expressão.
  *
  * @param void: não recebe nenhum argumento
  * @return void: não retorna nenhum valor
  **/
void resofex();
/**
  * @brief Valida a expressão
  *
  * Analisa os delimitadores da expressão e retorna 1 se a expressão é valida
  * e 0 se é invalida.
  *
  * @param T_stack* stack: pilha na qual os delimitadores são empilhados
  * @param char* IE: armazena a expressão recebida do usuário
  * @return int: identifica se a expressão é válida
  **/
int validexpression(T_stack* stack, char* IE);
/**
  * @brief Converte a expressão de infica para pósfixa
  *
  * Recebe a expressão na forma infixa (que está no vetor IE) e converte para forma
  * pósfixa (armazenando no vetor PE).
  *
  * @param T_stack* stack: pilha na qual os operadores são empilhados
  * @param char* IE: armazena a expressão infixa recebida do usuário
  * @param float* PE: armazena a expressão na forma pósfixa
  * @param int* SP: o primeiro elemento do vetor SP armazena a quantidade de
  * elementos no vetor PE e a partir do segundo elemento armazena as
  * posições no vetor PE cujo os elementos devem ser tratados como operadores
  * @param int N: quantidade de caracteres recebidos pelo usuário
  * @return void: não retorna nenhum valor
  **/
void convertexpression(T_stack* stack, char* IE, float* PE, int* SP, int N);
/**
  * @brief Exibe a expressao na forma pósfixa
  *
  * Exibe a expressao na forma pósfixa armazenada no vetor PE com auxílio do vetor SP,
  * que indica as posições no vetor PE que devem ser tratadas como operadores.
  *
  * @param float* PE: armazena a na forma expressão pósfixa
  * @param int* SP: o primeiro elemento do vetor SP armazena a quantidade de
  * elementos no vetor PE e a partir do segundo elemento armazena as
  * posições no vetor PE cujo os elementos devem ser tratados como operadores
  * @return void: não retorna nenhum valor
  **/
void printexpression(float* PE, int* SP);
/**
  * @brief Resolve a expressão
  *
  * Recebe a expressão na forma pósfixa armazenada no vetor PE, e com auxílio
  * do vetor SP, que indica as posições no vetor PE que devem ser tratadas como operadores
  * realiza as operações necessárias afim de solucionar a expressão, retornando o
  * resultado.
  *
  * @param T_stack* stack: pilha onde os operandos são empilhados
  * @param float* PE: armazena a expressão na forma pósfixa
  * @param int* SP: o primeiro elemento do vetor SP armazena a quantidade de
  * elementos no vetor PE e a partir do segundo elemento armazena as
  * posições no vetor PE cujo os elementos devem ser tratados como operadores
  * @return float: resultado obtido a partir da resolução da expressão pósfixa
  **/
float calcexpression(T_stack* stack, float* PE, int* SP);
/**
  * @brief Limpa o buffer
  *
  * Executa a limpeza do buffer do teclado.
  *
  * @param void: não recebe nenhum argumento
  * @return void: não retorna nenhum valor
  **/
void freebuffer();


/**
  * @brief Recebe operandos e operadores
  *
  * Recebe os operandos e operadores do usuário e executa as funções necessárias para
  * solucionar as operações.
  *
  * @param void: não recebe nenhum argumento
  * @return void: não retorna nenhum valor
  **/
void calc();
/**
  * @brief Soma os 2 primeiros dados da pilha
  *
  * Desempilha o primeiro e o segundo elemento da pilha, realiza a operação de soma entre eles
  * e empilha o resultado da operação na pilha.
  *
  * @param T_stack* stack: pilha na qual operandos e operadores são empilhados
  * @return void: não retorna nenhum valor
  **/
void sum(T_stack* stack);
/**
  * @brief Soma todos os dados da pilha
  *
  * Desempilha o primeiro e o segundo elemento da pilha, realiza a operação de soma entre eles
  * e empilha o resultado da operação na pilha, enqunto a pilha não estiver vazia.
  *
  * @param T_stack* stack: pilha na qual operandos e operadores são empilhados
  * @return void: não retorna nenhum valor
  **/
void sumr(T_stack* stack);
/**
  * @brief Subtrai os 2 primeiros dados da pilha
  *
  * Desempilha o primeiro e o segundo elemento da pilha, realiza a operação de subtração entre eles
  * e empilha o resultado da operação na pilha.
  *
  * @param T_stack* stack: pilha na qual operandos e operadores são empilhados
  * @return void: não retorna nenhum valor
  **/
void sub(T_stack* stack);
/**
  * @brief Subtrai todos os dados da pilha
  *
  * Desempilha o primeiro e o segundo elemento da pilha, realiza a operação de subtração entre eles
  * e empilha o resultado da operação na pilha, enqunto a pilha não estiver vazia.
  *
  * @param T_stack* stack: pilha na qual operandos e operadores são empilhados
  * @return void: não retorna nenhum valor
  **/
void subr(T_stack* stack);
/**
  * @brief Multiplica os 2 primeiros dados da pilha
  *
  * Desempilha o primeiro e o segundo elemento da pilha, realiza a operação de multiplicação entre eles
  * e empilha o resultado da operação na pilha.
  *
  * @param T_stack* stack: pilha na qual operandos e operadores são empilhados
  * @return void: não retorna nenhum valor
  **/
void mul(T_stack* stack);
/**
  * @brief Multiplica todos os dados da pilha
  *
  * Desempilha o primeiro e o segundo elemento da pilha, realiza a operação de multiplicação entre eles
  * e empilha o resultado da operação na pilha, enqunto a pilha não estiver vazia.
  *
  * @param T_stack* stack: pilha na qual operandos e operadores são empilhados
  * @return void: não retorna nenhum valor
  **/
void mulr(T_stack* stack);
/**
  * @brief Divide os 2 primeiros dados da pilha
  *
  * Desempilha o primeiro e o segundo elemento da pilha, realiza a operação de divisão entre eles
  * e empilha o resultado da operação na pilha.
  *
  * @param T_stack* stack: pilha na qual operandos e operadores são empilhados
  * @return void: não retorna nenhum valor
  **/
void divs(T_stack* stack);
/**
  * @brief Divide todos os dados da pilha
  *
  * Desempilha o primeiro e o segundo elemento da pilha, realiza a operação de divisão entre eles
  * e empilha o resultado da operação na pilha, enqunto a pilha não estiver vazia.
  *
  * @param T_stack* stack: pilha na qual operandos e operadores são empilhados
  * @return void: não retorna nenhum valor
  **/
void divsr(T_stack* stack);
/**
  * @brief Copia o primeiro elemento da pilha
  *
  * Desempilha o primeiro e o segundo elemento da pilha, o número armazenado no primeiro
  * elemento desempilhado dirá quantas vezes o segundo elemento deverá ser repetidamente empilhado.
  *
  * @param T_stack* stack: pilha na qual operandos e operadores são empilhados
  * @return void: não retorna nenhum valor
  **/
void copy(T_stack* stack);
/**
  * @brief Transforma vírgula em ponto
  *
  * Percorre a string recebida do usário transformando todos os caracteres ',' em '.'.
  *
  * @param char* S: armazena uma string recebida do usuário
  * @return void: não retorna nenhum valor
  **/
void ctod(char* S);


#endif
