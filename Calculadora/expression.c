#include <stdio.h>
#include <stdlib.h>
#include "stdtask.h"

void resofex() {
  system("clear");

  T_stack* stack = allocstack();

  int N;
  float R;
  char IE[200];

  printf("\tResolucao da Expressao\n\nDigite a Expressao: ");
  scanf("%[^\n]s", IE);

  N = 0;

  while(IE[N] != '\0') {
    N++;
  }

  if(!validexpression(stack, IE)) {
    printf("\n\tExpressao Invalida\n\n(pressione a tecla Enter para retornar ao menu)\n");
  } else {
    float PE[100] = {};
    int SP[50] = {};

    printf("\n\tExpressao Valida\n");

    ctod(IE);
    convertexpression(stack, IE, PE, SP, N);
    printexpression(PE, SP);
    R = calcexpression(stack, PE, SP);
    printf("\nResultado: %.2f\n", R);
    printf("\n(pressione a tecla Enter para retornar ao menu)\n");
  }
  freebuffer();
  freestack(stack);
}


int validexpression(T_stack* stack, char* IE) {
  char C;

  int i = 0, V = 1;

  while(IE[i] != '\0') {

    if(IE[i] == '(' ||
       IE[i] == '[' ||
       IE[i] == '{') {
         push(stack, (int) IE[i]);
       }

    if(IE[i] == ')' ||
       IE[i] == ']' ||
       IE[i] == '}') {
         if(emptystack(stack)) {
           V = 0;
         } else {
           C = (char) pop(stack);

           switch(IE[i]) {
             case ')':
                if(C != '(')
                  V = 0;
                break;
             case ']':
                if(C != '[')
                  V = 0;
                break;
             case '}':
                if(C != '{')
                  V = 0;
                break;
           }
         }
       }
       i++;
  }

  if(!emptystack(stack)) {
    V = 0;
  }

  return V;
}


void convertexpression(T_stack* stack, char* IE, float* PE, int* SP, int N) {
  freeelements(stack);

  float C, A;
  char O;

  int i, j, k, P;

  for(i = 0, j = 0, k = 1; IE[i] != '\0' && i < N; i++) {
    if(j == 0 && emptystack(stack)) {
      switch(IE[i]) {
        case ' ':
          break;
        case '{':
          C = (float) IE[i];
          push(stack, C);
          break;
        case '[':
          C = (float) IE[i];
          push(stack, C);
          break;
        case '(':
          C = (float) IE[i];
          push(stack, C);
          break;
        default:
          C = atof(&IE[i]);
          PE[j] = C;
          j++;
          while(IE[i] >= '0' && IE[i] <= '9') {
            i++;
            if(IE[i] == '.') {
              i++;
            }
          }
          i--;
          break;
        }
      } else {
        switch(IE[i]) {
          case ' ':
            break;
          case '{':
            C = (float) IE[i];
            push(stack, C);
            break;
          case '[':
            C = (float) IE[i];
            push(stack, C);
            break;
          case '(':
            C = (float) IE[i];
            push(stack, C);
            break;
          case '}':
            O = (char) pop(stack);
            while(O != '{') {
              C = (float) O;
              PE[j] = C;
              SP[k] = j;
              j++;
              k++;
              O = (char) pop(stack);
            }
            break;
          case ']':
            O = (char) pop(stack);
            while(O != '[') {
              C = (float) O;
              PE[j] = C;
              SP[k] = j;
              j++;
              k++;
              O = (char) pop(stack);
            }
            break;
          case ')':
            O = (char) pop(stack);
            while(O != '(') {
              C = (float) O;
              PE[j] = C;
              SP[k] = j;
              j++;
              k++;
              O = (char) pop(stack);
            }
            break;
          case '*':
          case '/':
            if(emptystack(stack)) {
              C = (float) IE[i];
              push(stack, C);
            } else {
              P = 1;
              while(!emptystack(stack) && P) {
                C = (float) IE[i];
                O = (char) pop(stack);
                switch (O) {
                  case '*':
                  case '/':
                    PE[j] = (float) O;
                    SP[k] = j;
                    j++;
                    k++;
                    break;
                  case '+':
                    P = 0;
                  case '-':
                    P = 0;
                  default:
                    A = (float) O;
                    push(stack, A);
                    P = 0;
                    break;
                  }
              }
              push(stack, C);
            }
            break;
          case '+':
          case '-':
            if(emptystack(stack)) {
              C = (float) IE[i];
              push(stack, C);
            } else {
              P = 1;
              while(!emptystack(stack) && P) {
                C = (float) IE[i];
                O = (char) pop(stack);
                switch (O) {
                  case '*':
                  case '/':
                  case '+':
                  case '-':
                    PE[j] = (float) O;
                    SP[k] = j;
                    j++;
                    k++;
                    break;
                  default:
                    A = (float) O;
                    push(stack, A);
                    P = 0;
                    break;
                }
              }
              push(stack, C);
            }
            break;
          default:
            C = atof(&IE[i]);
            PE[j] = C;
            j++;
            while(IE[i] >= '0' && IE[i] <= '9') {
              i++;
              if(IE[i] == '.') {
                i++;
              }
            }
            i--;
            break;
        }
      }
  }

  while(!emptystack(stack)) {
    PE[j] = pop(stack);
    SP[k] = j;
    j++;
    k++;
  }

  SP[0] = j;
}


void printexpression(float* PE, int* SP) {
  char O;
  int i, j;

  printf("\nForma Posfixa: ");

  for(i = 0, j = 1; i < SP[0]; i++) {
    if(i == SP[j]) {
      O = (char) PE[i];
      printf(" %c ", O);
      j++;
    } else {
      printf(" %.2f ", PE[i]);
    }
  }

  printf("\n");
}


float calcexpression(T_stack* stack, float* PE, int* SP) {
  freeelements(stack);

  float A, B, R;
  char O;
  int i, j;

  for(i = 0, j = 1; i < SP[0]; i++) {
    if(i == SP[j]) {
      O = (char) PE[i];
      B = pop(stack);
      A = pop(stack);
      switch (O) {
        case '*':
          R = A * B;
          push(stack, R);
          break;
        case '/':
          R = A / B;
          push(stack, R);
          break;
        case '+':
          R = A + B;
          push(stack, R);
          break;
        case '-':
          R = A - B;
          push(stack, R);
          break;
      }
      j++;
    } else {
      push(stack, PE[i]);
    }
  }
  R = pop(stack);
  return R;
}


void freebuffer() {
  char C;

  while((C = getchar()) != '\n' && C != EOF);
}
