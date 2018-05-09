#include "personagem.h"
#include "listaDE.h"
#include "arvore.h"
#include "fila.h"
#include "menu.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdio_ext.h>

Character* character_create(char* _name, char* _house, int _agility, int _strenght, int _intelligence, int _health)
{
    Character* boneco = (Character *) malloc(sizeof(Character));
    
    boneco->name  = (char *) malloc(100 * sizeof(char));
    boneco->house = (char *) malloc(50 * sizeof(char));
    strcpy(boneco->name, _name);
    strcpy(boneco->house, _house);
    boneco->agility      = _agility;
    boneco->strenght     = _strenght;
    boneco->intelligence = _intelligence;
    boneco->health       = _health;
    return boneco;
}

void imprime_atributos_aleatoriamente(Character* boneco, int numero)
{
    switch(rand() % 4)
    {
        case 0:
        {
            printf("Personagem %d:\n", numero);
            printf("Agilidade: %d   ", boneco->agility);
            printf("Força: ??   ");
            printf("inteligência: ??    ");  
            printf("Vida: ??\n\n");
            break;
        }
        case 1:
        {
            printf("Personagem %d:\n", numero);
            printf("Agilidade: ??   ");
            printf("Força: ??   ");
            printf("inteligência: %d    ", boneco->intelligence);
            printf("Vida: ??\n\n");
            break;
        }
        case 2:
        {
            printf("Personagem %d:\n", numero);
            printf("Agilidade: ??   ");
            printf("Força: %d   ", boneco->strenght);
            printf("inteligência: ??    ");
            printf("Vida: ??\n\n");
            break;
        }
        case 3:
        {
            printf("Personagem %d:\n", numero);
            printf("Agilidade: ??   ");
            printf("Força: ??   ");
            printf("inteligência: ??    ");
            printf("Vida: %d\n\n", boneco->health);
            break;
        }
    }
}

void personagem_selecionado(Character* escolhido)
{
    printf("Seu personagem: %s da Casa %s\n", escolhido->name, escolhido->house);
    printf("1) Agility     : %d\n", escolhido->agility);
    printf("2) Strenght    : %d\n", escolhido->strenght);
    printf("3) Inteligence : %d\n", escolhido->intelligence);
    printf("4) Health      : %d\n", escolhido->health);
}

void seu_inimigo(Character* inimigo)
{
    printf("\nO adversário: %s da Casa %s\n\n", inimigo->name, inimigo->house);
}

void selecao_de_personagem(void)
{
    FILE* arquivo = fopen("personagens.txt", "r");
    printf("\t\nSelecione o seu personagem: \n");
    char nome[100], casa[100];
    int agilidade, inteligencia, forca, vida;
    t_lista* lista = aloca_lista();
    t_lista* lista_dos_sorteados = aloca_lista();
    t_queue* fila = queue_create();
    t_node* raiz = tree_create();
    int i;
    Character* personagem;
    while(!feof(arquivo))
    {
        fscanf(arquivo, "%[^,],s",  nome); 
        fscanf(arquivo, " %[^,],s", casa);
        fscanf(arquivo, " %d,",  &agilidade); 
        fscanf(arquivo, " %d,",  &forca); 
        fscanf(arquivo, " %d,",  &inteligencia);
        fscanf(arquivo, " %d\n", &vida);
        t_node* no_com_o_personagem = node_create();
        personagem = character_create(nome, casa, agilidade, forca, inteligencia, vida);
        no_com_o_personagem->character = personagem;
        inserir_na_lista(lista, rand() % 16, no_com_o_personagem);
    }
    for(i = 0; i < 16; i++)
        inserir_na_lista(lista_dos_sorteados, i, remover_do_inicio_da_lista(lista));
    raiz = lista_para_arvore(raiz, lista_dos_sorteados);
    processamento_em_largura(raiz);
    libera_lista(lista);
    int opt;
    do
    {
        printf("\tOpção: ");
        scanf("%d", &opt);
    }while(opt <= 0 || opt > 16);
    printf("\n");
    Character* p = busca_na_lista(lista_dos_sorteados, opt);
    system("clear");
    tournament(raiz, p, fila);
    printf("\nRei do Trono de Ferro: \n\n");
    tree_print_preorder(raiz);
    libera_lista(lista_dos_sorteados);
    tree_free(raiz);
    queue_free(fila);
    fclose(arquivo);
    printf("Pressione ENTER para voltar ao menu\n");
    getchar();
    menu();
}

Character* fight(Character* fighter_one, Character* fighter_two, int atribute)
{
    Character* vencedor;
    switch(atribute)
    {
        case 1://agilidade
        {
            if(fighter_one->agility >= fighter_two->agility)
                vencedor = fighter_one;
                    else
                        vencedor = fighter_two;
            break;
        }
        case 2://força
        {
            if(fighter_one->strenght >= fighter_two->strenght)
                vencedor = fighter_one;
                    else
                        vencedor = fighter_two;
            break;
        }
        case 3://inteligencia
        {
            if(fighter_one->intelligence >= fighter_two->intelligence)
                vencedor = fighter_one;
                    else
                        vencedor = fighter_two;
            break;
        }
        case 4://vida
        {
            if(fighter_one->health >= fighter_two->health)
                vencedor = fighter_one;
                    else
                        vencedor = fighter_two;
            break;
        }
    }
    return vencedor;
}

void character_free(Character* personagem)
{
    free(personagem->name);
    free(personagem->house);
    free(personagem);
}

void inserir_no_txt(void)
{
    system("clear");
    __fpurge(stdin);
    FILE* arq = fopen("personagens.txt", "a");
    char nome[100], casa[50];
    printf("Digite o nome do personagem que deseja inserir: ");
    scanf("%[^\n]s", nome);
    fprintf(arq, "%s, ", nome);
    __fpurge(stdin);
    printf("Digite a casa do personagem que deseja inserir: ");    
    scanf("%[^\n]s", casa);
    fprintf(arq, "%s, ", casa); 
    __fpurge(stdin);   
    fprintf(arq, "%d, %d, %d, %d\n", rand()%100, rand()%100, rand()%100, rand()%100);
    __fpurge(stdin);
    fclose(arq);
    printf("Pressione ENTER para voltar ao menu\n");
    getchar();
    menu();
}