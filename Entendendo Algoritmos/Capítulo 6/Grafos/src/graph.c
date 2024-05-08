#include "../lib/graph.h"
#include "../lib/queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

graph_queue *create_queue(){

  graph_queue *queue = malloc(sizeof(graph_queue));

  assert(queue);

  return queue;

}

graph_queue *create_member(int data){

  graph_queue *member = malloc(sizeof(graph_queue));

  assert(member);

  member->data = data;
  member->next = NULL;
  member->prev = NULL;

  return member;
}

void print_elem (void *ptr)
{
   graph_queue *elem = ptr ;

   if (!elem)
      return ;

   elem->prev ? printf ("%d", elem->prev->data) : printf ("*") ;
   printf ("<%d>", elem->data) ;
   elem->next ? printf ("%d", elem->next->data) : printf ("*") ;

   printf(" ");
}


graph *graph_create(int n){

  graph *g = malloc(sizeof(graph));

  assert(g);

  g->n = n;
  g->m = 0;

  g->vertices = malloc(n*sizeof(vertice));

  assert(g->vertices);

  for(int i = 0; i < n; i++){

    g->vertices[i].queue = create_queue();

  }

  return g;

}

int graph_destroy (graph *g){

  for(int i = 0; i < g->n; i++)
    queue_destroy((queue_t **)&g->vertices[i].queue);
  
  free(g->vertices);
  free(g);

  return 1;

}

int graph_add_edge(graph *g, int u, int v){

  assert(u >= 0);
  assert(u < g->n);
  assert(v >= 0);
  assert(v < g->n);

  graph_queue *member = create_member(v);

  assert(queue_append((queue_t **)g->vertices[u].queue, (queue_t *)member) == 0);

  g->m++;

  return 1;

}

int graph_vertex_count(graph *g){
  return g->n;
}

int graph_edge_count(graph *g){
  return g->m;
}

int graph_out_degree(graph *g, int source){

  assert(source >= 0);
  assert(source < g->n);

  return queue_size((queue_t *)g->vertices[source].queue);

}

int ordena_fila(graph_queue *queue){

  graph_queue *aux = queue;

  while(aux->next != queue){

    if(aux->data > aux->next->data){
      int temp = aux->data;
      aux->data = aux->next->data;
      aux->next->data = temp;
    }

    aux = aux->next;

  }

  return 1;
}