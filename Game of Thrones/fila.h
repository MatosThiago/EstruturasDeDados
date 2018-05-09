#ifndef __FILA_H__
#define __FILA_H__

/**
 * @file fila.h
 * @author Yuri Serka do Carmo Rodrigues e Thiago Santos Matos
 *
 * @brief descrição de todas as funções do arquivo de cabeçalho "fila.h".
 *
 * Neste arquivo estão todas as funções necessárias para a criação, liberação de memória, percorrimento,
 * inserção e remoção de uma fila
 * */
 /**
  * @brief Estrutura do tipo t_data, é nela que serão armazenados os dados que conterão informações sobre as lutas.
  *
  * possui dois ponteiros para estrutura do tipo Character, e um inteiro que representa um atributo.
  * */
typedef struct data {
  /**
   * É o campo responsável por armazenar o primeiro Character participante da luta.
   * */
  Character* fighter_one;
  /**
   * É o campo responsável por armazenar o segundo Character participante da luta.
   * */
  Character* fighter_two;
  /**
   * É o campo responsável por armazenar o atributo utilizado para decidir a luta entre o primeiro e o segundo
   * Character.
   * */
  int atribute;
  /**
   * É o campo que apontará para o proximo elemento da fila.
   * */
  struct data* next;
} t_data;
/**
 * @brief estrutura do tipo t_queue, nela ficará salva as posições do primeiro elemento e do ultimo elemento.
 *
 * Possui dois campos do tipo t_data que apontarão para o inicio e o fim da fila.
 * */
typedef struct {
  /**
   * É o campo responsável por guardar a posição do primeiro elemento da fila.
   * */
  t_data* first;
  /**
   * É o campo responsável por guardar a posição do último elemento da fila.
   * */
  t_data* last;
} t_queue;

/**
 * @brief aloca memória dinamicamente para um elemento da fila.
 *
 * Recebe dois ponteiros para Character e um inteiro e define os campos respectivamente.
 * @param fighter_one que representa o primeiro lutador.
 * @param fighter_two que representa o segundo lutador.
 * @param atribute utilizado para definir o vencedor entre o primeiro e o segundo lutador.
 * @return irá retornar o elemento alocado.
 * */
t_data*    data_create(Character* fighter_one, Character* fighter_two, int atribute);
/**
 * @brief aloca dinamicamente memória para a fila.
 *
 * Cria uma fila com o primeiro e o ultimo elemento nulos.
 * @param void.
 * @return irá retornar a fila alocada.
 * */
t_queue*   queue_create(void);
/**
 * @brief insere um elemento na primeira posição da fila.
 *
 * Atualiza o ponteiro inicio da fila para o novo elemento inserido.
 * @param queue é a fila na qual os dados serão inseridos
 * @param fighter_one que representa o primeiro lutador.
 * @param fighter_two que representa o segundo lutador.
 * @param atribute utilizado para definir o vencedor entre o primeiro e o segundo lutador.
 * @return void
 * */
void       insert_data(t_queue* queue, Character* fighter_one, Character* fighter_two, int atribute);
/**
 * @brief Remove o último elemento da fila.
 *
 * Percorre a fila e remove o último elemento, atualizando o ponteiro para o último.
 * @param queue é a fila da qual o elemento será removido.
 * @return será o elemento removido.
 * */
t_data*    remove_data(t_queue* queue);
/**
 * @brief Imprime a fila.
 *
 * Percorre a fila imprimindo as informações de cada elemento.
 * @param queue é a fila que será impressa.
 * @return void
 * */
void       queue_print(t_queue* queue);
/**
 * @brief verifica se a fila está vazia.
 *
 * Verifica se os campos inicio e fim da fila apontam para NULL, se sim irá retornar 1, caso contrário irá retornar 0.
 * @param queue é a fila que será verificada.
 * @return 1 se estiver vazia, 0 caso contrário.
 * */
int        queue_empty(t_queue* queue);
/**
 * @brief libera a memória usada pela fila.
 *
 * Percorre a fila liberando a memória utilizada pelos elementos e por fim libera a fila.
 * @param queue é a fila que será liberada.
 * @return void
 * */
void       queue_free(t_queue* queue);

#endif
