#ifndef __MENUZIN__
#define __MENUZIN__

/**
 * @file menu.h
 * @author Yuri Serka do Carmo Rodrigues e Thiago Santos Matos
 * @date 2 de dezembro de 2017
 * 
 * @brief descrição de todas as funções do arquivo de cabeçalho "menu.h". 
 * 
 * Tem as funções do menu principal, quando o usuário ganha uma luta, e quando ele perde.
 * */
/**
 * @brief Menu principal do jogo
 * 
 * Imprime Game of Thrones e apresenta as opções de jogar e de sair.
 * @param void.
 * @return void.
 * */
void menu(void);
/**
 * @brief Imprime "You Win"
 * 
 * irá ser chamada caso o usuário ganhe uma luta no torneio.
 * @param voce será o seu personagem.
 * @param inimigo será o seu oponente.
 * @param atributo será o atributo escolhido na luta.
 * @return void
 * */
void vitoria(Character* voce, Character* inimigo, int atributo);
/**
 * @brief Imprime "You Lose"
 * 
 * irá ser chamada caso o usuário perca uma luta no torneio.
 * @param voce será o seu personagem.
 * @param inimigo será o seu oponente.
 * @param atributo será o atributo escolhido na luta.
 * @return void
 * */
void derrota(Character* voce, Character* inimigo, int atributo);

#endif
