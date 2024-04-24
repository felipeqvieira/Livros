#include <stdio.h>

void ordena_vetor(int vetor[], int tam){

  int ordenado[tam];
  int menor_valor;
  int menor_indice;

  // CUSTO N
  for(int i = 0; i < tam; i++){

    menor_valor = vetor[i];

    // CUSTO N
    for(int j = i; j < tam; j++){

      if(vetor[j] < menor_valor){
        menor_valor = vetor[j];
        menor_indice = j;
      }

    }

    ordenado[i] = menor_valor;
    vetor[menor_indice] = vetor[i];
    printf("Ordenado[%d] = %d\n", i, ordenado[i]);
    
  }

  // CUSTO FINAL = O(N*N) = O(N²)

}