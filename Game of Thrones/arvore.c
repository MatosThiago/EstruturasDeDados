#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "listaDE.h"
#include "menu.h"
#include "fila.h"

t_node* tree_create(void)
{
    int i;
    t_node* raiz = node_create();
    for(i = 0; i < 4; i++)
        preenche_a_arvore(raiz);
    return raiz;
}

t_node* preenche_a_arvore(t_node* raiz)
{
    if(raiz->left == NULL && raiz->right == NULL)
        {
            raiz->left = node_create();
            raiz->right  = node_create();
        }
            else
            {
                preenche_a_arvore(raiz->left);
                preenche_a_arvore(raiz->right);
            }
    return raiz;
}

t_node* node_create(void)
{
    t_node* Noh = (t_node *) malloc(sizeof(t_node));
    Noh->character = NULL;
    Noh->left      = NULL;
    Noh->right     = NULL;
    return Noh;
}

void tree_print_preorder(t_node* raiz)
{
    if(raiz->character != NULL)
    {
        printf("Nome: %s\n", raiz->character->name);
        printf("Casa: %s\n", raiz->character->house);
        printf("Agilidade: %d\n", raiz->character->agility);
        printf("Inteligência: %d\n", raiz->character->intelligence);
        printf("Força: %d\n", raiz->character->strenght);
        printf("Vida: %d\n", raiz->character->health);
        printf("\n");
    }
    else
    {
        tree_print_preorder(raiz->left);
        tree_print_preorder(raiz->right);
    }

}

void processamento_em_largura(t_node* raiz)
{
    t_lista* lista = aloca_lista();
    t_node* no = NULL;

    if(raiz == NULL)
        return;
    int num = 1;
    inserir_no_fim_da_lista(lista, raiz);
    while(!lista_vazia(lista))
    {
        no = remover_do_inicio_da_lista(lista);
        if(no->character != NULL)
            imprime_atributos_aleatoriamente(no->character, num - 15);
        if(no->left != NULL)
            inserir_no_fim_da_lista(lista, no->left);
        if(no->right != NULL)
            inserir_no_fim_da_lista(lista, no->right);
        num++;
    }
    libera_lista(lista);
}

void tree_free(t_node* tree)
{
    if(tree == NULL)
        return;
            else
            {
                tree_free(tree->left);
                tree_free(tree->right);
                free(tree);
            }
}

void tournament(t_node* raiz, Character* seu_personagem, t_queue* fila)
{
    int i, aux, aux_do_aux = 0;
    int atr[2] = {0, 0};
    for(i = 0; i < 4; i++)
    {
        insert_data(fila, NULL, NULL, 0);
        aux = tournament_aux(raiz, seu_personagem, fila, atr);
        if(aux != 0) {
            queue_print(fila);
            aux_do_aux++;
        }
    }
    if(aux_do_aux == 0) {
      queue_print(fila);
    }
}

int tournament_aux(t_node* raiz, Character* seu_personagem, t_queue* fila, int* atr)
{
    if(raiz == NULL || raiz->character != NULL)
        return 0;

    if(raiz->left->character != NULL && raiz->right->character != NULL)
    {
        if((raiz->left->character == seu_personagem && raiz->right->character != seu_personagem) ||
           (raiz->left->character != seu_personagem && raiz->right->character == seu_personagem))
        {
            Character* inimigo;
            if(raiz->left->character == seu_personagem)
                inimigo = raiz->right->character;
                    if(raiz->right->character == seu_personagem)
                        inimigo = raiz->left->character;
            printf("ROUND %d\n", get_node_height(raiz)-1);
            personagem_selecionado(seu_personagem);
            seu_inimigo(inimigo);
            do
            {
                printf("Selecione um atributo: ");
                scanf("%d", &atr[1]);
                if(atr[1] == atr[0])
                    printf("\tAtributo já utilizado, tente novamente\n");
            }while(atr[1] < 1 || atr[1] > 4 || atr[1] == atr[0]);
            atr[0] = atr[1];
            insert_data(fila, seu_personagem, inimigo, atr[1]);
            raiz->character = fight(seu_personagem, inimigo, atr[1]);
            printf("\nROUND %d: Resultado\n\n", get_node_height(raiz)-1);
            if(raiz->character == seu_personagem)
            {
                vitoria(seu_personagem, inimigo, atr[1]);
                getchar();
                system("clear");
                return 0;
            }
                else
                {
                    derrota(seu_personagem, inimigo, atr[1]);
                    getchar();
                    return 1;
                }
        }
        if(raiz->left->character != seu_personagem && raiz->right->character != seu_personagem)
        {
            int atri = (rand() % 4) + 1;
            insert_data(fila, raiz->left->character, raiz->right->character, atri);
            raiz->character = fight(raiz->left->character, raiz->right->character, atri);
            return 0;
        }
    }
    return (tournament_aux(raiz->left, seu_personagem, fila, atr) +
            tournament_aux(raiz->right, seu_personagem, fila, atr));
}

int get_node_height(t_node* raiz)
{
    if(raiz == NULL)
        return 0;

    int altura_esquerda = get_node_height(raiz->left);
    int altura_direita  = get_node_height(raiz->right);
    if (altura_esquerda < altura_direita)
        return altura_direita + 1;
            else
                return altura_esquerda + 1;
}
