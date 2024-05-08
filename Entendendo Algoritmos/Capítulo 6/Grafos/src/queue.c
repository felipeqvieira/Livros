#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int queue_size(queue_t *queue) {
    
    //queue == NULL
    if (!queue || queue->next == NULL) return 0;

    int contador = 1;
    queue_t *aux = queue;

    //percorre a queue
    while(aux->next != queue){
        contador++;
        aux = aux->next;
    }

    return contador;
}

void queue_print (char *name, queue_t *queue, void print_elem (void*) ){

  printf("%s: [", name);

  // verifica queue
  if (!queue){
    printf("]\n");
    return;
  }

  queue_t *aux = queue;

  // percore queue
  while (aux->next != queue){
    print_elem(aux);
    aux = aux->next;
  }

  print_elem(aux);

  printf("]\n");

}

int queue_append (queue_t **queue, queue_t *elem){

  // verifica fila, elemento e se o elemento esta em outra fila
  if (!queue || !elem || elem->next != NULL || elem->prev != NULL)
     return -1;
  

  // verifica se a fila esta vazia
  if (queue_size(*queue) == 0){
    *queue = elem;
    elem->next = elem;
    elem->prev = elem;
    printf("Fila vazia!\n");
    return 0;
  }

  queue_t *aux = *queue;

  // percorre a fila
  while (aux->next != *queue){
    printf("Aux->next != queue\n");
    aux = aux->next;
  }

  // insere elemento
  aux->next = elem;
  elem->prev = aux;
  elem->next = *queue;
  (*queue)->prev = elem;

  return 0;

}

int queue_remove(queue_t **queue, queue_t *elem) {
  
  // verifica queue e elemento
  if (! queue || ! *queue || ! elem ) 
    return -1;

  queue_t *aux = *queue;

  //caso 1: remoção do primeiro elemento
  if (aux == elem) {
    // caso 1.1 = elemento sozinho na fila
    if (aux->next == aux) {
      *queue = NULL;
      aux->next = NULL;
      aux->prev = NULL;
      free(aux);
      return 0;
    }
    //caso 1.2 = fila com mais de um elemento
    queue_t *ultimo = aux->prev;
    *queue = aux->next;
    aux->next = NULL;
    aux->prev = NULL;
    ultimo->next = *queue;
    (*queue)->prev = ultimo;
    aux = elem;
    free(aux);
    return 0;
  }

  // caso 2 = não é o primeiro elemento
  while (aux->next != *queue) {
    // encontra elemento
    if (aux->next == elem) {
      //caso 2.1 = remoção do ultimo elemento
      if (elem->next == *queue) { 
        aux->next = *queue;
        (*queue)->prev = aux;
        elem->next = NULL;
        elem->prev = NULL;
        aux = elem;
      } else {
        // caso 2.2 = remoção de elemento no meio da fila
        aux->next = elem->next;
        elem->next->prev = aux;
        elem->next = NULL;
        elem->prev = NULL;
        aux = elem;
      }

      free(aux);
      return 0;
    }
    aux = aux->next;
  }

  return -1;
}

int queue_destroy(queue_t **queue) {
  
  // verifica queue
  if (!queue || !*queue) 
    return -1;

  queue_t *aux = *queue;

  // percorre a fila
  while (aux->next != *queue) {
    queue_t *temp = aux;
    aux = aux->next;
    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
  }

  // libera o último elemento
  aux->next = NULL;
  aux->prev = NULL;
  free(aux);

  *queue = NULL;

  return 0;
}