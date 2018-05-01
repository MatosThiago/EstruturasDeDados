#include <stdio.h>
#include <stdlib.h>
#include "stdtask.h"

int main() {
  system("clear");

  char O;

  printf("\tMenu\n\n1. Resolucao da Expressao\n2. Calculadora\n3. Sair\n");

  printf("\nSelecione a Opcao: ");
  O = getchar();

  freebuffer();

  if(O == '1') {
    resofex();
  } else {
    if(O == '2') {
      calc();
    } else {
      if(O == '3') {
        system("clear");
        exit(0);
      } else {
        printf("\nOpcao Invalida\n\n(pressione a tecla Enter para retornar ao menu)\n");
      }
    }
  }

  while(O != '3') {
    getchar();
    system("clear");

    printf("\tMenu\n\n1. Resolucao da Expressao\n2. Calculadora\n3. Sair\n");

    printf("\nSelecione a Opcao: ");
    O = getchar();

    freebuffer();

    if(O == '1') {
      resofex();
    } else {
      if(O == '2') {
        calc();
      } else {
        if(O == '3') {
          system("clear");
          exit(0);
        } else {
          printf("\nOpcao Invalida\n\n(pressione a tecla Enter para retornar ao menu)\n");
        }
      }
    }
  }

  return 0;
}
