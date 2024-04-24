#include <stdio.h>
#include "busca_menor.h"

int main(){

  int tam;
  
  printf("Digite o tamanho do vetor:\n");
  scanf("%d", &tam);

  int vetor[tam];

  printf("Digite os valores do vetor:\n");

  for(int i = 0; i < tam; i++)
    scanf("%d", &vetor[i]);

  ordena_vetor(vetor, tam);

}