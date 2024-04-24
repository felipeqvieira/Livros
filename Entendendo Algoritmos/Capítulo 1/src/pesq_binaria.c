#include "pesq_binaria.h"
#include "define.h"
#include <stdio.h>
#include <stdlib.h>

int pesq_binaria(int vetor[], int valor){

  int inicio = 0;
  int fim = TAM-1;

  while (inicio <= fim){

    int meio = (inicio + fim)/2;

    if (vetor[meio] == valor)
      return meio;
    else if (valor > vetor[meio])
      inicio = meio+1;
    else 
      fim = meio-1;
  
  }
  
  return -1;
}

int pesq_binaria_rec(int vetor[], int inicio, int fim, int valor){

  if (inicio > fim)
    return -1;

  int meio = (inicio + fim)/2;

  if(vetor[meio] == valor)
    return meio;
  else if (vetor[meio] < valor)
    return pesq_binaria_rec(vetor, inicio, meio, valor);
  else
    return pesq_binaria_rec(vetor, meio, fim, valor);

}