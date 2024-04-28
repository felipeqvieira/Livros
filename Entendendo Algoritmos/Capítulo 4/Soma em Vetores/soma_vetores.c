#include <stdio.h>

int soma_vetores(int vetor[], int tam){

  if(tam == 1)
    return vetor[0];

  return vetor[tam-1] + soma_vetores(vetor, tam-1);

}

int main(){

  int vetor[5] = {1, 2, 3, 4, 5};

  int tam = 5;

  printf("%d\n",soma_vetores(vetor, tam));

  return 1;
}