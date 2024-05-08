typedef struct graph_queue{

  struct graph_queue *next;
  struct graph_queue *prev;

  int data;

}graph_queue;

typedef struct vertice{

  graph_queue *queue;

}vertice;

typedef struct graph{

  int n;
  int m;

  vertice *vertices;
  
}graph;



graph_queue *create_queue();

graph_queue *create_member(int data);

void print_elem (void *ptr);

/* create a new graph with n vertices labeled 0..n-1 and no edges */
graph *graph_create(int n);

/* free all space used by graph */
int graph_destroy(graph *g);

/* add an edge to an existing graph */
/* doing this more than once may have unpredictable results */
int graph_add_edge(graph *g, int source, int sink);

/* return the number of vertices/edges in the graph */
int graph_vertex_count(graph *g);
int graph_edge_count(graph *g);

/* return the out-degree of a vertex */
int graph_out_degree(graph *g, int source);

/* return 1 if edge (source, sink) exists), 0 otherwise */
int graph_has_edge(graph *g, int source, int sink);

int ordena_fila(graph_queue *queue);

//void print_elem (void *ptr);

/* invoke f on all edges (u,v) with source u */
/* supplying data as final parameter to f */
/* no particular order is guaranteed 
void graph_foreach(Graph g, int source,
        void (*f)(Graph g, int source, int sink, void *data),
        void *data);
*/

