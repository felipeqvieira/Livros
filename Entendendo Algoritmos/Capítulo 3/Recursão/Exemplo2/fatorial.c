#include <stdio.h>

int fatorial (int num){

  if(num == 0)
    return 1;

  return num * fatorial(num-1);

}

int main(){

  printf("Insira o número para calcular o fatorial: \n");
  
  int num;

  scanf("%d", &num);

  printf("\nCalculando...\n");

  printf("\nresultado: %d\n", fatorial(num));

  return 1;
}