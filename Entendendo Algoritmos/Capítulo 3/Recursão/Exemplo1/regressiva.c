#include <stdio.h>

int regressiva(int num){
  
  if(num < 0)
    return 1;

  printf("%d\n", num);

  return regressiva(num-1);
}

int main(){

  printf("Insira o número inicial da contagem até 0: \n");
  
  int num;

  scanf("%d", &num);

  printf("\nIniciando contagem...\n");

  regressiva(num);

  return 1;
}