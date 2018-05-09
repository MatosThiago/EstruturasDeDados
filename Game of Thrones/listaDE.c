#include <stdlib.h>
#include <stdio.h>
#include "listaDE.h"
#include "personagem.h"

t_elemento* aloca_elemento(t_node* personagem)
{
    t_elemento* noh = (t_elemento *) malloc(sizeof(t_elemento));
    noh->anterior   = NULL;
    noh->proximo    = NULL;
    noh->personagem = personagem;
    return noh;
}

t_lista* aloca_lista(void)
{
    t_lista* lista = (t_lista *) malloc(sizeof(t_lista));
    lista->fim    = NULL;
    lista->inicio = NULL;
    return lista;
}//end aloca lista

int lista_vazia(t_lista* lista)
{
    return(lista->fim == NULL && lista->inicio == NULL);
}//end lista vazia

void inserir_no_inicio_da_lista(t_lista* lista, t_node* dado)
{
    t_elemento* novo_elemento = aloca_elemento(dado);
    if(lista_vazia(lista))
        lista->inicio = novo_elemento;
            else
            {
                novo_elemento->anterior = NULL; 
                novo_elemento->proximo = lista->inicio;
                lista->inicio->anterior = novo_elemento;
                lista->inicio = novo_elemento;
            }
    if(lista->fim == NULL)
        lista->fim = lista->inicio;
}//end inserir no inicio da lista

void inserir_no_fim_da_lista(t_lista* lista, t_node* dado)
{
    t_elemento* novo_elemento = aloca_elemento(dado);    
    if(lista_vazia(lista))
      lista->inicio = novo_elemento;
        else
        {
            novo_elemento->proximo = NULL;
            novo_elemento->anterior = lista->fim; 
            lista->fim->proximo = novo_elemento;
        }  
    lista->fim = novo_elemento;
}//end inserir no fim da lista

void inserir_na_lista(t_lista* lista, int posicao, t_node* dado)
{
    t_elemento* novo_elemento;
    if(posicao<=0)
        inserir_no_inicio_da_lista(lista, dado);
            else
            {
                int i;
                t_elemento* atual = lista->inicio;
                for(i = 0; i < (posicao-1) && atual != NULL; i++)
                    atual = atual->proximo;

                if(atual == lista->fim || atual == NULL)
                    inserir_no_fim_da_lista(lista, dado);
                        else
                        {
                            novo_elemento = aloca_elemento(dado);
                            novo_elemento->proximo = atual->proximo;
                            novo_elemento->proximo->anterior = novo_elemento; 
                            novo_elemento->anterior = atual;
                            atual->proximo = novo_elemento;                            
                        }
                    }
}//end inserir na lista

t_node* remover_do_inicio_da_lista(t_lista* lista)
{
    t_elemento* auxiliar = lista->inicio;
    t_node* dado_removido;
    if(lista_vazia(lista))
    {
        printf("lista vazia\n");
        free(auxiliar);
        exit(-1);
    }
    dado_removido = auxiliar->personagem;
    if(lista->inicio == lista->fim)
        lista->fim = NULL;
    
    lista->inicio = lista->inicio->proximo;
    free(auxiliar);
    return dado_removido;
}//end remover do inicio

t_node* remover_do_final_da_lista(t_lista* lista)
{
    t_elemento* atual = lista->fim;
    t_node* dado_removido;
    if(lista_vazia(lista))
    {
        printf("lista vazia\n");
        free(atual);
        exit(-1);
    }
    dado_removido = atual->personagem;
    lista->fim = lista->fim->anterior;
    free(atual);
    return dado_removido;
}//end remover do final da lista

t_node* remover_da_lista(t_lista* lista, int posicao)
{
    t_elemento* atual = lista->inicio;
    t_node* dado_removido;
    int i;
    if(lista_vazia(lista))
    {
        printf("lista vazia\n");
        free(atual);
        exit(-1);
    }
    if(posicao <= 0)
        remover_do_inicio_da_lista(lista);
        else
        {
            for(i = 0; i < posicao && atual != NULL; i++)
                atual = atual->proximo;

            if(atual == lista->fim || atual == NULL)
                remover_do_final_da_lista(lista);
                    else
                    {
                        dado_removido = atual->personagem;
                        atual->anterior->proximo = atual->proximo;
                        atual->proximo->anterior = atual->anterior; 
                        free(atual);
                    }
        }
    return dado_removido;
}//end remover da lista

void imprime_lista(t_lista* lista)
{
    t_elemento* atual = lista->inicio;
    if(lista_vazia(lista))
    {
        printf("A lista está vazia\n");
        return;
    }
    while(atual != NULL)
    {
        printf("%s, ", atual->personagem->character->name);
        printf("%s, ", atual->personagem->character->house);
        printf("%d, ", atual->personagem->character->agility);
        printf("%d, ", atual->personagem->character->strenght);
        printf("%d, ", atual->personagem->character->intelligence);
        printf("%d\n", atual->personagem->character->health);
        atual = atual->proximo;
    }
    printf("\n");
}//end imprime lista

void imprime_lista_inverso(t_lista* lista)
{
    t_elemento* atual = lista->fim;
    if(lista_vazia(lista))
    {
        printf("A lista está vazia\n");
        return;
    }
    while(atual != NULL)
    {
        printf("%s, ", atual->personagem->character->name);
        printf("%s, ", atual->personagem->character->house);
        printf("%d, ", atual->personagem->character->agility);
        printf("%d, ", atual->personagem->character->strenght);
        printf("%d, ", atual->personagem->character->intelligence);
        printf("%d\n", atual->personagem->character->health);
        atual = atual->anterior;
    }
    printf("\n");
}//end imprime lista na ordem inversa

int tamanho_da_lista(t_lista* lista)
{
    t_elemento* aux = lista->inicio;
    int tamanho = 0;
    while(aux != NULL)
    {  
        aux = aux->proximo;
        tamanho++;
    }
    free(aux);
    return tamanho;
}//size of lista
     
void libera_lista(t_lista* lista)
{
    t_elemento* atual = lista->inicio;
    if(!lista_vazia(lista))
    {
        while(atual != NULL)
        {
            lista->inicio = lista->inicio->proximo;
            free(atual->personagem->character->name);
            free(atual->personagem->character->house);
            free(atual->personagem->character);
            free(atual->personagem);
            free(atual);
            atual = lista->inicio;
        }
    }
    free(lista);
}//end libera lista   

Character* busca_na_lista(t_lista* lista, int option)
{
    t_elemento* atual = lista->inicio;
    Character* meu_boneco; 
    if(lista_vazia(lista))
        return NULL;
    int i = 0;
    while(i != option-1 && atual != NULL)
    {
        atual = atual->proximo;
        i++;
    }
    meu_boneco = atual->personagem->character;
    return meu_boneco;
}

t_node* lista_para_arvore(t_node* raiz, t_lista* lista) 
{
  t_elemento* aux = lista->inicio;
  lista_para_arvore_aux(raiz, lista);
  lista->inicio = aux;
  return raiz;
}

t_node* lista_para_arvore_aux(t_node* raiz, t_lista* lista) 
{
  if(raiz->left == NULL && raiz->right == NULL)
    {
        t_elemento* element = lista->inicio;
        raiz->character = element->personagem->character;
        lista->inicio = element->proximo;
    } 
        else 
        {
            lista_para_arvore_aux(raiz->left, lista);
            lista_para_arvore_aux(raiz->right, lista);
        }
  return raiz;
}
