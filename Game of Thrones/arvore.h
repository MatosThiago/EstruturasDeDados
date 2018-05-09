#ifndef __ARVORE__
#define __ARVORE__

/**
 * @file arvore.h
 * @author Yuri Serka do Carmo Rodrigues e Thiago Santos Matos
 * @date 1 de dezembro de 2017
 *
 * @brief descrição de todas as funções do arquivo de cabeçalho "arvore.h".
 *
 * Neste arquivo estão as funções necessárias para para criar, percorrer e liberar memória de uma árvore binária.
 * */
/**
 * @brief inclui a biblioteca "personagem.h"
 * É necessário esse include para que possa ser usado a estrutura Character como argumento para as funções.
 * */
#include "personagem.h"
#include "fila.h"
/**
 * @brief Estrutura do tipo node, é nela que serão armazenados os personagens do jogo.
 *
 * A estrutura possui o campo para character que é do tipo Character e
 * dois campos que são do próprio tipo node que aponta para esquerda e para a direita.
 * */
typedef struct node
{
    /**
     * É o campo responsável por armazenar as características do personagem alocado no nó.
     * */
    Character*  character;
    /**
     * É o campo que apontará para o nó da esquerda do nó atual.
     * */
    struct node* left;
    /**
     * É o campo que apontará para o nó da direita do nó atual.
     * */
    struct node* right;
}t_node;

/**
 * @brief Cria a árvore que será usada no jogo.
 *
 * Essa função é indiretamente recursiva, pois em seu escopo é chamada a função preenche_a_arvore(t_node* raiz),
 * que é recursiva. Ela irá criar os 4 níveis da árvore binária completa.
 * @param void
 * @return irá apontar para o nó raiz da árvore, no caso para o nó "vencedor".
 * */
t_node* tree_create(void);
/**
 * @brief Completa cada nível da árvore binária.
 *
 * É uma função recursiva que irá criar nós enquanto o nível não estiver totalmente preenchido.
 * @param raiz irá ser a raiz da árvore passada.
 * @return a própria raiz da árvore.
 * */
t_node* preenche_a_arvore(t_node* raiz);
/**
 * @brief aloca memória dinamicamente para um nó da árvore.
 *
 * Define todos os paramêtros de um nó como NULL.
 * @param void
 * @return irá retornar o nó criado.
 * */
t_node* node_create(void);
/**
 * @brief percorre a árvore binária em pré ordem
 *
 * O percorrimento em pré ordem é caracterizado por: primeiramente a raiz é impressa, depois chama-se
 * recursivamente a raiz da esquerda e depois a raiz da direita.
 * @param raiz é o nó raiz da árvore binária.
 * @return void
 * */
void    tree_print_preorder(t_node* raiz);
/**
 * @brief percorre a árvore binária em largura.
 *
 * O percorrimento em largura é caracterizado por: primeiramente o nó raiz é inserido no fim da lista, depois
 * enquanto a lista não estiver vazia, então será impresso os dados dos personagens de forma aleatória e os nós filhos
 * do nó impresso serão inseridos no fim da lista também.
 * @param raiz é a raiz da árvore binária
 * @return void
 * */
void    processamento_em_largura(t_node* raiz);
/**
 * @brief libera toda a memória alocada para os nós.
 *
 * É uma função recursiva que irá percorrer a árvore e liberar a memória de cada nó.
 * @param raiz é a raiz da árvore binária.
 * @return void
 * */
void    tree_free(t_node* raiz);
/**
 * @brief realiza as batalhas entre os personagens do torneio.
 *
 * É uma função recursiva indireta, pois chama a função tournament_aux que é recursiva e é nela em que
 * as batalhas ocorrem de fato.
 * @param raiz será a raiz da árvore binária que será utilizada.
 * @param p aponta para o personagem escolhido pelo usuário.
 * @param fila será utilizada para armazenar informações sobre as lutas.
 * @return void
 * */
void tournament(t_node* raiz, Character* p, t_queue* fila);
/**
 * @brief realiza as batalhas entre os personagens do torneio.
 *
 * Realiza as batalhas do torneio e armazena informações sobre elas de forma recursiva.
 * @param raiz será a raiz da árvore binária que será utilizada.
 * @param p aponta para o personagem escolhido pelo usuário.
 * @param fila será utilizada para armazenar informações sobre as lutas.
 * @param atr é utilizado para verificar se atributo escolhido pelo usuário é o mesmo da rodada passada.
 * @return void
 * */
int tournament_aux(t_node* raiz, Character* p, t_queue* fila, int* atr);
/**
 * @brief retorna a altura da árvore.
 *
 * Realiza as batalhas do torneio e armazena informações sobre elas de forma recursiva.
 * @param raiz será a raiz da árvore binária que será utilizada.
 * @return altura da árvore.
 * */
int get_node_height(t_node* raiz);

#endif
