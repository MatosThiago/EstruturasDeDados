#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

t_queue * create_queue() {
    t_queue * queue = (t_queue *) malloc(sizeof(t_queue));
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

t_element * create_element(t_node * node) {
    t_element * element = (t_element *) malloc(sizeof(t_element));
    element->data = node;
    element->next = NULL;
    return element;
}

void push(t_node * node, t_queue * queue) {
    t_element * element = create_element(node);

    if(empty_queue(queue)) {
        queue->first = element;
    } else {
        queue->last->next = element;
    }
    queue->last = element;
}

t_node * pull(t_queue * queue) {
    if(empty_queue(queue)) {
        printf("Empty Queue (Impossible Pull)\n");
    }

    t_element * first = queue->first;
    t_node * node;

    node = first->data;
    if(queue->first == queue->last) {
        queue->last = NULL;
    }
    queue->first = queue->first->next;

    free(first);
    return node;
}

int empty_queue(t_queue * queue) {
    return (queue->first == NULL && queue->last == NULL);
}

void print_queue(t_queue * queue) {
    t_element * ptr = queue->first;

    while(ptr != NULL) {
        printf("%d -> ", ptr->data->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void free_queue(t_queue * queue) {
    t_element * ptr = queue->first;

    while(ptr != NULL) {
        queue->first = ptr->next;
        free(ptr);
        ptr = queue->first;
    }
    free(queue);
}
