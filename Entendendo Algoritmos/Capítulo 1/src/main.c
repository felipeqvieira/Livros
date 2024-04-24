#include "pesq_binaria.h"
#include "pesq_simples.h"
#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int vetor[TAM];

  srand(time(0));

  for(int i = 0; i < TAM; i++)
    vetor[i] = i;

  int valor = rand() % TAM + 1;

  printf("Valor: %d\n", valor);
  
  int indice;

  clock_t t = clock();
  if((indice = pesq_binaria(vetor, valor)) != -1)
    printf("\nBinaria: Valor encontrado! Indice: %d\n", indice);
  t = clock() - t;

  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("\nTempo da pesquisa binaria: %f\n", time_taken);

  clock_t t2 = clock();
  if((indice = pesq_simples(vetor, valor)) != -1)
    printf("\nSimples: Valor encontrado! Indice: %d\n", indice);
  t2 = clock() - t2;

  double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;

  printf("\nTempo da pesquisa simples: %f\n", time_taken2);

  return 1;

}