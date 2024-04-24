#include "pesq_simples.h"
#include "define.h"
#include <stdio.h>
#include <stdlib.h>

int pesq_simples(int vetor[], int valor){

  for(int i = 0; i < TAM -1; i++){
    if(vetor[i] == valor)
      return i;
  }

  return -1;

}