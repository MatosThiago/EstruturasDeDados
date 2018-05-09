#ifndef __PERSO__H_
#define __PERSO__H_
/**
 * @file personagem.h
 * @author Yuri Serka do Carmo Rodrigues e Thiago Santos Matos
 * @date 2 de dezembro de 2017
 *
 * @brief descrição de todas as funções do arquivo de cabeçalho "personagem.h".
 *
 * Neste arquivo estão todas as funções necessárias para a criação, liberação de memória, seleção,
 * luta e impressão aleatória dos atributos de um personagem.
 * os nós da árvore binária.
 * */
/**
 * @brief Estrutura do tipo Character, é nela que os dados de um personagem serão armazenados
 *
 * Possui dois campos char* que são para o nome e a casa, e quatro campos int que são para a agilidade, força,
 * inteligência e vida do personagem.
 * */
typedef struct
{
    /**
     * É o campo responsável por armazenar o nome do character.
     * */
    char* name;
    /**
     * É o campo responsável por armazenar a casa do character.
     * */
    char* house;
    /**
     * É o campo responsável por armazenar a agilidade do character.
     * */
    int  agility;
    /**
     * É o campo responsável por armazenar a força do character.
     * */
    int  strenght;
    /**
     * É o campo responsável por armazenar a inteligência do character.
     * */
    int  intelligence;
    /**
     * É o campo responsável por armazenar a vida do character.
     * */
    int  health;
}Character;

/**
 * @brief Aloca memória dinamicamente para um personagem.
 *
 * Cria um personagem de acordo com os parâmetros passados, mas sua casa e nome são passados por cópia utilizando
 * a função strcpy(char* destino, char* fonte) e também são alocados dinamicamente.
 * @param _name será o nome.
 * @param _house será a casa.
 * @param _agility será a agilidade.
 * @param _srenght será a força.
 * @param _intelligence será a inteligência.
 * @param _health será a vida.
 * @return será o personagem criado.
 * */
Character*  character_create(char* _name, char* _house, int _agility, int _strenght, int _intelligence, int _health);
/**
 * @brief imprime as características do personagem escolhido.
 *
 * Imprime todos os dados do seu personagem.
 * @param personagem será o personagem que o jogador escolher.
 * @return void
 * */
void        personagem_selecionado(Character* personagem);
/**
 * @brief responsável por fazer possível a seleção de um personagem da árvore.
 *
 * Primeiramente esta função irá ler do arquivo "personagens.txt" o nome, casa, agilidade, força, inteligência e vida
 * respectivamente e criar um personagem chamando a função character_create(), depois esse personagem é atribuido
 * a um nó e este nó será inserido aleátoriamente na lista dos personagens lidos.
 *
 * Depois de ler o arquivo todo e guardar todos os personagens na lista, é executado um for que retira 16 personagens e
 * armazena-os em outra lista, esses personagens serão inseridos nos nós folha da árvore pela função lista_para_arvore().
 *  Depois o usuário digita qual personagem ele quer, e então é feita uma busca_na_lista() e depois chama-se a função
 * personagem_selecionado() para imprimir os atributos do personagem escolhido.
 * @param void.
 * @return void.
 * */
void  selecao_de_personagem(void);
/**
 * @brief libera toda a memória utilizada por um personagem
 *
 * libera a memória alocada para o nome e para a casa e depois libera a ocupada pelo resto todo.
 * @param personagem será o personagem que deve ser liberado.
 * @return void.
 * */
void        character_free(Character* personagem);
/**
 * @brief imprime os atributos de forma aleátoria.
 *
 * faz um switch com argumento rand(), isso garante que toda vez que entrar nessa função ele irá gerar um novo
 * número, que será usado para determinar qual atributo imprimir.
 * @param boneco é o personagem que terá seus atributos impressos.
 * @param numero é o número do personagem.
 * @return void.
 * */
void        imprime_atributos_aleatoriamente(Character* boneco, int numero);
/**
 * @brief realiza a luta entre dois personagens da árvore.
 *
 * A luta é caracterizada pela escolha de um atributo e a comparação deste, as lutas sempre ocorrem entre os
 * personagens de mesmo nó pai, portanto o vencedor assumirá a posição do nó pai.
 * @param fighter_one primeiro personagem.
 * @param fighter_two segundo personagem.
 * @param atribute será o atributo escolhido.
 * @return será o personagem vencedor da luta.
 * */
Character*  fight(Character* fighter_one, Character* fighter_two, int atribute);
/**
 * @brief imprime o nome e a casa do inimigo do personagem escolhido.
 *
 * Imprime o nome e a casa do inimigo do personagem escolhido.
 * @param inimigo aponta para o inimigo do personagem escolhido.
 * @return void
 * */
void        seu_inimigo(Character* inimigo);

void inserir_no_txt(void);

#endif
