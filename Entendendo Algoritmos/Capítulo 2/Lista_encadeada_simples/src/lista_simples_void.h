// Definição da estrutura do nó
typedef struct Node {
    void* data;
    struct Node* prox;
} Node;

// Definição da estrutura da lista
typedef struct {
    int tam;
    Node* inicio;
    Node* fim;
} Lista;

Lista* inicializa_lista();

Node* cria_no(void* valor);

Lista* insereInicio(Lista* l, void* valor);

Lista* removeInicio(Lista* l);

void libera_lista(Lista* l);