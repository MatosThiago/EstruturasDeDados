#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "listaDE.h"
#include "menu.h"
#include "fila.h"

t_data* data_create(Character* fighter_one, Character* fighter_two, int atribute) 
{
    t_data* data = (t_data*) malloc(sizeof(t_data));
    data->fighter_one = fighter_one;
    data->fighter_two = fighter_two;
    data->atribute = atribute;
    data->next = NULL;
    return data;
}

t_queue* queue_create() 
{
    t_queue* queue = (t_queue*) malloc(sizeof(t_queue));
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

void insert_data(t_queue* queue, Character* fighter_one, Character* fighter_two, int atribute) 
{
    t_data* data = data_create(fighter_one, fighter_two, atribute);
    if(queue_empty(queue)) 
        queue->first = data;
            else 
                queue->last->next = data;
    queue->last = data;
}

t_data*    remove_data(t_queue* queue) 
{
    if(queue_empty(queue))
    return NULL;

    t_data* data = queue->first;
    if(queue->first == queue->last)
        queue->last = NULL;

    queue->first = data->next;
    return data;
}

void queue_print(t_queue* queue) 
{
    if(!queue_empty(queue)) 
    {
        int i = 1;
        t_data* data = queue->first;
        while(data != NULL) 
        {
            switch(data->atribute) 
            {
                case 0:
                {
                    printf("\nROUND %d:\n\n", i);
                    i++;
                    break;
                }
                case 1:
                {
                    printf("%s (%d Agility) x %s (%d Agility)\n", data->fighter_one->name, data->fighter_one->agility, data->fighter_two->name, data->fighter_two->agility);
                    break;
                }
                case 2:
                {
                    printf("%s (%d Strenght) x %s (%d Strenght)\n", data->fighter_one->name, data->fighter_one->strenght, data->fighter_two->name, data->fighter_two->strenght);
                    break;
                }
                case 3:
                {
                    printf("%s (%d Inteligence) x %s (%d Inteligence)\n", data->fighter_one->name, data->fighter_one->intelligence, data->fighter_two->name, data->fighter_two->intelligence);
                    break;
                }   
                case 4:
                {
                printf("%s (%d Health) x %s (%d Health)\n", data->fighter_one->name, data->fighter_one->health, data->fighter_two->name, data->fighter_two->health);
                    break; 
                }
            }
        data = data->next;
        }
    }
}

int        queue_empty(t_queue* queue) {
  return (queue->first == NULL && queue->last == NULL);
}

void       queue_free(t_queue* queue) {
  if(!queue_empty(queue)) {
    t_data* data = queue->first;

    while(data != NULL) {
      queue->first = data->next;
      free(data);
      data = queue->first;
    }
    free(queue);
  }
}
