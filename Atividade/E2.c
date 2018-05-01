#include <stdio.h>
#include <stdlib.h>

/*

Nome do Arquivo: Q2.c

Nome do Aluno: Thiago Santos Matos

Matricula: 17/0063666

Descrição: O programa aloca dinamicamente um vetor de tipo estrutura, de tamanho
especificado pelo usuário, e recebe dados do mesmo, gravando neste
vetor, após o cadastramento dos dados o programa exibe o nome e salário
dos funcionários que recebem uma quantia maior que a média geral dos salários.

*/

typedef struct {
    char* nome;
    char* cargo;
    char departamento[31];
    float salario;
    int datadeadmissao[3];
} T_funcionario;

void scanstruct(T_funcionario* F, int N);
void printlist(T_funcionario* F, int N);
void freememory(T_funcionario* F, int N);

int main() {

    int N;

    printf("Quantidade de funcionarios: ");
    scanf("%d", &N);

    T_funcionario* F = (T_funcionario*) malloc(N * sizeof(T_funcionario));

    scanstruct(F, N);
    printlist(F, N);
    freememory(F, N);

    return 0;
}

void scanstruct(T_funcionario* F, int N) {

    int i, j, C;

    for(i = 0, j = 0; i < N; i++) {
            printf("\nQuantidade de caracteres de nome: ");
            scanf("%d", &C);
            F[i].nome = (char*) malloc((C+1) * sizeof(char));
scannome:
            printf("Nome: ");
            scanf("%s", F[i].nome);
            while(F[i].nome[j] != '\0') {
                    j++;
            }
            if(j > C) {
                    printf("\tNumero de caracteres digitados maior que o informado! Digite novamente.\n");
                    j = 0;
                    goto scannome;
            }

            j = 0;

            printf("Quantidade de caracteres de cargo: ");
            scanf("%d", &C);
            F[i].cargo = (char*) malloc((C+1) * sizeof(char));
scancargo:
            printf("Cargo: ");
            scanf("%s", F[i].cargo);
            while(F[i].cargo[j] != '\0') {
                    j++;
            }
            if(j > C) {
                    printf("\tNumero de caracteres digitados maior que o informado! Digite novamente.\n");
                    j = 0;
                    goto scancargo;
            }

            printf("Departamento: ");
            scanf("%s", F[i].departamento);

            printf("Salario: R$ ");
            scanf("%f", &F[i].salario);

            printf("Data de Admissao (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &F[i].datadeadmissao[0], &F[i].datadeadmissao[1], &F[i].datadeadmissao[2]);
    }
}

void printlist(T_funcionario* F, int N) {

    int i, M;

    for(i = 0, M = 0; i < N; i++) {
            M = M + F[i].salario;
    }

    M = M/N;

    printf("\n\nFUNCIONARIOS QUE RECEBEM SALARIO MAIOR QUE A MEDIA GERAL\n");

    for(i = 0; i < N; i++) {
            if(F[i].salario > M) {
                    printf("\n%s\t\tR$ %.2f", F[i].nome, F[i].salario);
            }
    }
}

void freememory(T_funcionario* F, int N) {

    int i;

    for(i = 0; i < N; i++) {
            free(F[i].nome);
            free(F[i].cargo);
    }
    free (F);
}

