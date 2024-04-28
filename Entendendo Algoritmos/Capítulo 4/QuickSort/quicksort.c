#include <stdio.h>

int partition(int *A, int p, int r){

  int x = A[r];

  int i = p-1;

  for (int j = p; j <= r-1; j++){

    if(A[j] <= x){
      
      i++;

      int aux = A[i];

      A[i] = A[j];

      A[j] = aux;
    }

  }

  int aux = A[i+1];
  A[i+1] = A[r];
  A[r] = aux;

  return i + 1;

}

void quickSort(int *A, int p, int r){

  if (p >= r)
    return;

  int q = partition(A, p, r);
  quickSort(A, p, q-1);
  quickSort(A, q+1, r);

}

int main(){

  int vetor[] = {5, 3, 6, 10, 2, 40, 1, 2, 100};

  quickSort(vetor, 0, 8);

  for(int i = 0; i < 9; i++)
    printf("v[%d] = %d\n", i, vetor[i]);
  
  return  1;
}