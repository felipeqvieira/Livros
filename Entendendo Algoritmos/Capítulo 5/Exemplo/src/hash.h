#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define m 11

extern int MAX;

/* calculo de h1 que resulta no lugar da tabela de t1 */
int h1 (int k);

/* calculo de h2 que resulta no lugar da tabela de t2 */
int h2(int k);

/* funcao de inserir elemento nas tabelas */
void inserir(int t1[], int t2[], int valor, char *str);

/* funcao para remover elemento das tabelas */
void remover(int t1[], int t2[], int valor, char *str);

/* funcao que calcula os menores valores */
int valor_minimo(int v[]);

/* funcao para imprimir as tabelas */
void imprimir(int t1[], int t2[]);

/* Faz a soma dos caracteres e retorna o valor */
int somaASCII(char *str);

/* Dobra o tamanho do vetor quando necessário */
int redimensiona(int *vetor1, int *vetor2);

/* Fator de carga */
int fdc(int *vetor);