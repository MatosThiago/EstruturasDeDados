#include <stdio.h>
#include <stdlib.h>

/*

Nome do Arquivo: Q4.c

Nome do Aluno: Thiago Santos Matos

Matricula: 17/0063666

Descrição: O programa lê um valor inteiro do arquivo "n.bin" e aloca dinamicamente
um vetor do tamanho do inteiro lido, em seguiga o programa lê o arquivo "data.bin"
e salva o conteúdo do arquivo no vetor anteriomente criado, após isso ele exibe
o conteúdo do vetor.

*/

typedef struct {
    char nome[101];
    char cargo[101];
    char departamento[31];
    float salario;
    int datadeadmissao[3];
} T_funcionario;

void scanbin(T_funcionario* F, int N);
void printvet(T_funcionario* F, int N);

int main() {

    int N;

        FILE* file = fopen("n.bin", "rb");

        fread(&N, sizeof(int), 1, file);

        fclose(file);

    T_funcionario* F = (T_funcionario*) malloc(N * sizeof(T_funcionario));

    scanbin(F, N);
    printvet(F, N);

    free (F);
    return 0;
}

void scanbin(T_funcionario* F, int N) {

    FILE* file = fopen("data.bin", "rb");

    fread(F, sizeof(T_funcionario), N, file);

    fclose(file);
}

void printvet(T_funcionario* F, int N) {

    int i;

    for(i = 0; i < N; i++) {
            printf("\n%s\t", F[i].nome);
            printf("%s\t", F[i].cargo);
            printf("%s\t", F[i].departamento);
            printf("%f\t", F[i].salario);
            printf("%i/%i/%i\n", F[i].datadeadmissao[0], F[i].datadeadmissao[1], F[i].datadeadmissao[2]);
    }
}

