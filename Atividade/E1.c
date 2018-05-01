#include <stdio.h>
#include <stdlib.h>

/*

Nome do Arquivo: Q1.c

Nome do Aluno: Thiago Santos Matos

Matricula: 17/0063666

Descrição: O programa aloca dinamicamente um vetor de tipo estrutura, de tamanho
especificado pelo usuário, e recebe dados do mesmo, gravando neste
vetor, após o cadastramento dos dados o programa permite a busca de uma profissão
através de seu código.

*/

typedef struct {
    int* code;
    char* profession;
} T_job;

void scanstruct(T_job* J, int N);
void searchcode(T_job* J, int N, int CD);
void freememory(T_job* J, int N);

int main() {

    int N;

    printf("CADASTRAR PROFISSOES\n\n");

    printf("Quantidade de profissoes a serem cadastradas: ");
    scanf("%d", &N);

    T_job* J = (T_job*) malloc(N * sizeof(T_job));

    scanstruct(J, N);

    int CD;

    printf("\n\nBUSCAR PROFISSAO\n\n");
    printf("Codigo: ");
    scanf("%d", &CD);

    searchcode(J, N, CD);
    freememory(J, N);

    return 0;
}

void scanstruct(T_job* J, int N) {

    int i, j, C;

    for(i = 0, j = 0; i < N; i++) {
            printf("\nQuantidade de caracteres da profissao: ");
            scanf("%d", &C);

            J[i].code = (int*) malloc(sizeof(int));
            J[i].profession = (char*) malloc((C+1) * sizeof(char));

            printf("Codigo: ");
            scanf("%d", J[i].code);
scanprofissao:
            printf("Profissao: ");
            scanf("%s", J[i].profession);

            while(J[i].profession[j] != '\0') {
                    j++;
            }
            if(j > C) {
                    printf("Quantidade de caracteres digitados maior do que o informado. Digite novamente.\n");
                    j = 0;
                    goto scanprofissao;
            }
    }
}

void searchcode(T_job* J, int N, int CD) {

    int i = 0;

    while(*J[i].code != CD) {
            i++;
            if(i == N) {
                    break;
            }
    }

    if(i == N) {
            printf("O codigo da profissao digitado nao pertence a nenhuma profissao cadastrada\n");
    } else {
        printf("Profissao: %s", J[i].profession);
    }
}

void freememory(T_job* J, int N) {

    int i;

    for(i = 0; i < N; i++) {
            free(J[i].code);
            free(J[i].profession);
    }

    free(J);
}

