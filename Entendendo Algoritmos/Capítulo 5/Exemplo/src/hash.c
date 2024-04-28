#include "hash.h"

int MAX = 15;

int somaASCII(char *str) {
    int soma = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        soma += str[i]; // Adiciona o valor ASCII de cada caractere à soma
    }
    return soma;
}

int h1(int k){
  return k % m;
}

int h2(int k){
  float h2 = floor(k*0.9);
  h2 = m * (k*0.9 - h2);

  return floor(h2);
}

void inserir(int t1[], int t2[], int valor, char *str){

  int valorh1 = somaASCII(str);

  int indice = h1(valorh1);

  if(t1[indice] == -1 || t1[indice] == 999)
    t1[indice] = valor;
  else{
    t2[h2(t1[indice])] = t1[indice];
    t1[indice] = valor;
  }

}

void remover(int t1[], int t2[], int valor, char *str){

  int indice = somaASCII(str);

  int valorh1 = h1(indice);
  int valorh2 = h2(indice);

  if(t2[valorh2] == valor)
    t2[valorh2] = -1;
  else if (t1[valorh1] == valor)
    t1[valorh1] = 999;

}

void imprimir(int t1[], int t2[]){
  for(int i = 0; i < MAX; i++)
    if(t1[i] != 0 && t1[i] != -1 && t1[i] != 999)
      printf("t1[%d] = %d  ", i, t1[i]);

  printf("\n\n");

  for(int i = 0; i < MAX; i++)
    if(t2[i] != 0 && t2[i] != -1 && t2[i] != 999)
      printf("t2[%d] = %d  ", i, t2[i]);

  printf("\n\n");
}

int redimensiona(int *vetor1, int *vetor2){

  MAX = MAX * 2;

  vetor1 = (int *) realloc(vetor1, MAX * sizeof(int));

  if(vetor1 == NULL){
    printf("Erro ao alocar memória\n");
    return 0;
  }

  vetor2 = (int *) realloc(vetor1, MAX * sizeof(int));

  if(vetor2 == NULL){
    printf("Erro ao alocar memória\n");
    return 0;
  }

  return 1;
}

int fdc(int *vetor){

  int qtd = 0;

  for(int i = 0; i < MAX; i++)
    if(vetor[i] != -1 && vetor[i] != 999)
      qtd++;

  return floor(qtd/MAX);

}