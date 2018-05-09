#ifndef __LISTA_DUPLAMENTE_ENCADEADA__
#define __LISTA_DUPLAMENTE_ENCADEADA__

/**
 * @file listaDE.h
 * @author Yuri Serka do Carmo Rodrigues e Thiago Santos Matos
 * 
 * @brief descrição de todas as funções do arquivo de cabeçalho "listaDE.h".
 * 
 * Neste arquivo estão todas as funções necessárias para a criação, liberação de memória, percorrimento,
 * busca, inserção e remoção de uma lista, além da função que transfere o conteúdo dos nós da lista para
 * os nós da árvore binária.
 * */
/**
 * @brief inclui a biblioteca "arvore.h"
 * É necessário esse include para que possa ser usado a estrutura t_node como argumento para as funções.
 * */
#include "arvore.h"
/**
 * @brief Estrutura do tipo t_elemento, é nela que serão armazenados os nós que conterão os personagens do jogo.
 * 
 * possui um campo que é um ponteiro para a estrutura do tipo t_node, ou seja, a lista armazena os nós da ávore
 * binária, possui o campo para o próximo elemento e para o anterior, pois é uma lista duplamente encadeada.
 * */
typedef struct elemento
{   
    /**
     * É o campo responsável por armazenar um nó e nesse nó terá um personagem.
     * */
    t_node* personagem;
    /**
     * É o campo que apontará para o proximo elemento da lista.
     * */
    struct elemento* proximo;
    /**
     * É o campo que apontará para o  elemento anterior da lista.
     * */
    struct elemento* anterior;
}t_elemento;

/**
 * @brief estrutura do tipo t_lista, nela ficará salva as posições do primeiro elemento e do ultimo elemento.
 * 
 * Possui dois campos do tipo t_elemento que apontarão para o inicio e o fim da lista.
 * */
typedef struct lista
{
    /**
     * É o campo responsável por guardar a posição do primeiro elemento da lista.
     * */
    t_elemento* inicio;
    /**
     * É o campo responsável por guardar a posição do último elemento da lista.
     * */
    t_elemento* fim;
}t_lista;

/**
 * @brief aloca memória dinamicamente para um elemento da lista.
 * 
 * Recebe um nó da árvore e define o campo personagem da struct elemento como ele.
 * @param será o nó que será posto na lista.
 * @return irá retornar o elemento alocado.
 * */
t_elemento* aloca_elemento(t_node* personagem);
/**
 * @brief aloca dinamicamente memória para a lista
 * 
 * Cria uma lista com o primeiro e o ultimo elemento NULL's.
 * @param void.
 * @return irá retornar a lista alocada.
 * */
t_lista*    aloca_lista(void);
/**
 * @brief verifica se a lista está vazia.
 * 
 * Verifica se os campos inicio e fim da lista valem NULL, se sim irá retornar 1, caso contrário irá retornar 0.
 * @param é a lista que será verificada.
 * @return 1 se estiver vazia, 0 caso contrário.
 * */
int         lista_vazia(t_lista* lista);
/**
 * @brief insere um elemento na primeira posição da lista.
 * 
 * Atualiza o ponteiro inicio da lista para o novo elemento inserido.
 * @param lista é a lista na qual o elemento será inserido.
 * @param dado é o nó que será inserido na lista.
 * @return void
 * */
void        inserir_no_inicio_da_lista(t_lista* lista, t_node* dado);
/**
 * @brief insere um elemento na ultima posição da lista.
 * 
 * Atualiza o ponteiro fim da lista para o novo elemento inserido.
 * @param lista é a lista na qual o elemento será inserido.
 * @param dado é o nó que será inserido na lista.
 * @return void
 * */
void        inserir_no_fim_da_lista(t_lista* lista, t_node* dado);
/**
 * @brief insere um elemento em qualquer posição da lista.
 * 
 * Para de percorrer a lista uma posição antes da desejada e faz as ligações dos ponteiros proximo e anterior
 * de modo que o novo elemento inserido seja conectado à lista.
 * @param lista é a lista na qual o elemento será inserido. 
 * @param posicao é a posição em que o novo elemento será inserido.
 * @param dado é o nó que será inserido na lista.
 * @return void
 * */
void        inserir_na_lista(t_lista* lista, int posicao, t_node* dado);
/**
 * @brief Remove um elemento do inicio da lista.
 * 
 * Atualiza o ponteiro inicio da lista para o proximo elemento do primeiro da lista.
 * @param lista é a lista da qual o elemento será removido.
 * @return será o nó removido.
 * */
t_node*     remover_do_inicio_da_lista(t_lista* lista);
/**
 * @brief Remove um elemento do final da lista.
 * 
 * Atualiza o ponteiro do final da lista para o elemento anterior do ultimo da lista.
 * @param lista é alista da qual o elemento será removido.
 * @return será o nó removido.
 * */
t_node*     remover_do_final_da_lista(t_lista* lista);
/**
 * @brief Remove um elemento da lista dada a posição em que ele se encontra.
 * 
 * Percorre a lista até achar a posição e faz as ligações dos ponteiros para garantir que a lista ainda esteja
 * conectada após a remoção do elemento.
 * @param lista é a lista da qual o elemento será removido.
 * @param posicao é a posição da qual deseja-se retirar o nó.
 * @return será o nó removido.
 * */
t_node*     remover_da_lista(t_lista* lista, int posicao);
/**
 * @brief Calcula quantos elementos tem na lista.
 * 
 * Percorre a lista inteira e retorna o seu tamanho.
 * @param lista é a lista que deseja-se calcular o tamanho.
 * @return será o tamanho da lista.
 * */
int         tamanho_da_lista(t_lista* lista);
/**
 * @brief Imprime a lista da esquerda para a direita.
 * 
 * Esta função irá imprimir todos os atributos dos personagens que pertencerão aos nós da lista.
 * @param lista é a lista que será impressa.
 * @return void
 * */
void        imprime_lista(t_lista* lista);
/**
 * @brief Imprime a lista da direita para a esquerda.
 * 
 * Esta função irá imprimir todos os atributos dos personagens que pertencerão aos nós da lista.
 * @param lista é a lista que será impressa.
 * @return void
 * */
void        imprime_lista_inverso(t_lista* lista);
/**
 * @brief libera toda a memória usada pela lista.
 * 
 * Irá liberar primeiramente a memória alocada para o nome do personagem, depois para a casa, depois o personagem,
 * depois o nó que o personagem estava e no fim libera a lista.
 * @param lista é a lista que será liberada.
 * @return void
 * */
void        libera_lista(t_lista* lista);
/**
 * @brief Procura na lista um personagem dada uma posição.
 * 
 * Percorre a lista até uma certa posição e retorna o personagem dela.
 * @param lista é alista na qual o personagem será procurado.
 * @param option é a posição do personagem que deseja-se buscar.
 * @return será o personagem da posição escolhida.
 * */
Character*  busca_na_lista(t_lista* lista, int option);
/**
 * @brief insere na árvore os elementos que estão presentes na lista.
 * 
 * É uma função recursiva indireta, pois chama a função lista_para_arvore_aux que é recursiva e é nela em que
 * os personagens são realmente passados da lista para os nós folhas da árvore.
 * @param raiz será a raiz da árvore binária que deseja-se preencher com os personagens.
 * @param lista será a lista de onde os personagens serão pegos para serem passados.
 * @return será o nó da raiz.
 * */
t_node*     lista_para_arvore(t_node* raiz, t_lista* lista);
/**
 * @brief insere na árvore os elementos que estão presentes na lista recursivamente.
 * 
 * Insere os personagens em largura apenas nos nós folhas, isso faz com que os elementos sejam passados 
 * na mesma ordem em que se encontram na lista. Depois atualiza o inicio da lista, pois a função é recursiva.
 * @param raiz será a raiz da árvore binária que deseja-se preencher com os personagens.
 * @param lista será a lista de onde os personagens serão pegos para serem passados.
 * @return será o nó da raiz.
 * */
t_node*     lista_para_arvore_aux(t_node* raiz, t_lista* lista);

#endif
