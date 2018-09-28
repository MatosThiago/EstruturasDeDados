#ifndef _QUEUE_
#define _QUEUE_

#include "tree.h"

typedef struct element {
    t_node * data;
    struct element * next;
} t_element;

typedef struct queue {
    t_element * first;
    t_element * last;
} t_queue;

t_queue * create_queue();
t_element * create_element(t_node * node);
void push(t_node * node, t_queue * queue);
t_node * pull(t_queue * queue);

int empty_queue(t_queue * queue);
void print_queue(t_queue * queue);
void free_queue(t_queue * queue);

#endif