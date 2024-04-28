#include "hash.h"

#define STRING 50

void leitura(int *valor, char *produto){
  printf("\nDigite o nome do produto:\n");
  scanf("%s", produto);
  printf("\nDigite o valor do produto:\n");
  scanf("%d", valor);
}

int main(){

  int opcao = 10, valor;
  char *produto = (char *) malloc(STRING * sizeof(char));

  int *t1 = (int *) malloc(MAX * sizeof(int));
  int *t2 = (int *) malloc(MAX * sizeof(int));

  while (opcao != 0){

    printf("\n1. Insere\n2. Remove\n3. Imprimir\n0. Sair\n\n");
    scanf("%d", &opcao);

    switch (opcao){
      case 1:
        leitura(&valor, produto);
        inserir(t1, t2, valor, produto);
        break;
      case 2:
        leitura(&valor, produto);
        remover(t1, t2, valor, produto);
        break;
      case 3:
        imprimir(t1, t2);
        break;
      case 0:
        break;
      default:
        printf("\nOpção inválida!\n");
        break;
    }
    
  }

  return 1;
}