#include <stdio.h>
#include <stdlib.h>
#include "stdtask.h"

T_stack* allocstack() {
  T_stack* stack = (T_stack*) malloc(sizeof(T_stack));

  stack->top = NULL;

  return stack;
}


T_element* allocelement(float D) {
  T_element* element = (T_element*) malloc(sizeof(T_element));

  element->data = D;
  element->next = NULL;

  return element;
}


int emptystack(T_stack* stack) {
  return (stack->top == NULL);
}


void push(T_stack* stack, float D) {
  T_element* element = allocelement(D);

  if(emptystack(stack)) {
    stack->top = element;
  } else {
    element->next = stack->top;
    stack->top = element;
  }
}


float pop(T_stack* stack) {
  float aux;

  if(!emptystack(stack)) {
    T_element* element = stack->top;

    aux = element->data;

    stack->top = element->next;
    free(element);
  }

  return aux;
}


void printstack(T_stack* stack) {
  if(emptystack(stack)) {
    printf("Pilha Vazia\n");
  } else {
    T_element* now = stack->top;

    int i = 1;

    while(now != NULL) {
      printf("%d. %.2f\n", i, now->data);

      i++;
      now = now->next;
    }
  }
}


void freeelements(T_stack* stack) {
  if(!emptystack(stack)) {
    T_element* now = stack->top;

    while(now != NULL) {
      stack->top = now->next;
      free(now);
      now = stack->top;
    }
  }
  stack->top = NULL;
}


void freestack(T_stack* stack) {
  if(!emptystack(stack)) {
    T_element* now = stack->top;

    while(now != NULL) {
      stack->top = now->next;
      free(now);
      now = stack->top;
    }
  }

  free(stack);
}
