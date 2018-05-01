#include <stdio.h>
#include <stdlib.h>
#include "stdtask.h"

void calc() {
  system("clear");

  T_stack* stack = allocstack();

  char S[50];
  float F;

  system("clear");

  printf("\tCalculadora\t(para sair da calculadora pressione s)\n\n");

  printstack(stack);

  printf("\n-> ");
  scanf("%s", S);
  ctod(S);

  freebuffer();

  switch (S[0]) {
    case '+':
      if(S[1] == '!') {
        sumr(stack);
      } else {
        sum(stack);
      }
      break;
    case '-':
      if(S[1] >= '0' && S[1] <= '9') {
        F = atof(S);
        push(stack, F);
      } else {
        if(S[1] == '!') {
          subr(stack);
        } else {
          sub(stack);
        }
      }
      break;
    case '*':
      if(S[1] == '!') {
        mulr(stack);
      } else {
        mul(stack);
      }
      break;
    case '/':
      if(S[1] == '!') {
        divsr(stack);
      } else {
        divs(stack);
      }
      break;
    case 'C':
      copy(stack);
      break;
    case 'c':
      copy(stack);
      break;
    case 'S':
      break;
    case 's':
      break;
    default:
      F = atof(S);
      push(stack, F);
      break;
  }

  while(S[0] != 'S' && S[0] != 's') {
    system("clear");

    printf("\tCalculadora\t(para sair da calculadora pressione s)\n\n");

    printstack(stack);

    printf("\n-> ");
    scanf("%s", S);
    ctod(S);

    freebuffer();

    switch (S[0]) {
      case '+':
        if(S[1] == '!') {
          sumr(stack);
        } else {
          sum(stack);
        }
        break;
      case '-':
        if(S[1] >= '0' && S[1] <= '9') {
          F = atof(S);
          push(stack, F);
        } else {
          if(S[1] == '!') {
            subr(stack);
          } else {
            sub(stack);
          }
        }
        break;
      case '*':
        if(S[1] == '!') {
          mulr(stack);
        } else {
          mul(stack);
        }
        break;
      case '/':
        if(S[1] == '!') {
          divsr(stack);
        } else {
          divs(stack);
        }
        break;
      case 'C':
        copy(stack);
        break;
      case 'c':
        copy(stack);
        break;
      case 'S':
        break;
      case 's':
        break;
      default:
        F = atof(S);
        push(stack, F);
        break;
    }
  }
  printf("\n(pressione a tecla Enter para retornar ao menu)\n");
  freestack(stack);
}


void sum(T_stack* stack) {
  float F, A;

  if(emptystack(stack)) {
    printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
    getchar();
  } else {
    if(stack->top->next == NULL) {
      printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
      getchar();
    } else {
      F = pop(stack);
      A = pop(stack);
      F = F + A;
      push(stack, F);
    }
  }
}


void sumr(T_stack* stack) {
  float F, A;

  if(emptystack(stack)) {
    printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
    getchar();
  } else {
    if(stack->top->next == NULL) {
      printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
      getchar();
    } else {
      F = pop(stack);
      do {
        A = pop(stack);
        F = F + A;
      } while(!emptystack(stack));
      push(stack, F);
    }
  }
}


void sub(T_stack* stack) {
  float F, A;

  if(emptystack(stack)) {
    printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
    getchar();
  } else {
    if(stack->top->next == NULL) {
      printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
      getchar();
    } else {
      F = pop(stack);
      A = pop(stack);
      F = F - A;
      push(stack, F);
    }
  }
}


void subr(T_stack* stack) {
  float F, A;

  if(emptystack(stack)) {
    printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
    getchar();
  } else {
    if(stack->top->next == NULL) {
      printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
      getchar();
    } else {
      F = pop(stack);
      do {
        A = pop(stack);
        F = F - A;
      } while(!emptystack(stack));
      push(stack, F);
    }
  }
}


void mul(T_stack* stack) {
  float F, A;

  if(emptystack(stack)) {
    printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
    getchar();
  } else {
    if(stack->top->next == NULL) {
      printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
      getchar();
    } else {
      F = pop(stack);
      A = pop(stack);
      F = F * A;
      push(stack, F);
    }
  }
}


void mulr(T_stack* stack) {
  float F, A;

  if(emptystack(stack)) {
    printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
    getchar();
  } else {
    if(stack->top->next == NULL) {
      printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
      getchar();
    } else {
      F = pop(stack);
      do {
        A = pop(stack);
        F = F * A;
      } while(!emptystack(stack));
      push(stack, F);
    }
  }
}


void divs(T_stack* stack) {
  float F, A;

  if(emptystack(stack)) {
    printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
    getchar();
  } else {
    if(stack->top->next == NULL) {
      printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
      getchar();
    } else {
      F = pop(stack);
      A = pop(stack);
      F = F / A;
      push(stack, F);
    }
  }
}


void divsr(T_stack* stack) {
  float F, A;

  if(emptystack(stack)) {
    printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
    getchar();
  } else {
    if(stack->top->next == NULL) {
      printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
      getchar();
    } else {
      F = pop(stack);
      do {
        A = pop(stack);
        F = F / A;
      } while(!emptystack(stack));
      push(stack, F);
    }
  }
}


void copy(T_stack* stack) {
  int F, i;
  float A;

  if(emptystack(stack)) {
    printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
    getchar();
  } else {
    if(stack->top->next == NULL) {
      printf("\nQuantidade de operandos insuficiente\n\n(pressione a tecla Enter para retornar ao menu)\n");
      getchar();
    } else {
      F = (int) pop(stack);
      A = pop(stack);
      for(i = 0; i < F; i++) {
        push(stack, A);
      }
    }
  }
}


void ctod(char* S) {
  int i;

  for(i = 0; S[i] != '\0'; i++) {
    if(S[i] == ',') {
      S[i] = '.';
    }
  }
}
