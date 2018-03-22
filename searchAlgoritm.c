#include<stdlib.h> // necessário para funções rand e srand
#include<stdio.h>
#include <time.h> // Usar função time para que esses valores não se repitam já que são chaves de registros

#define SIZE 100
#define TAMINDICE 30

void preencheRegistros(int *registros){
  int i;
  for (i = 0; i < SIZE; i++)
  {
    registros[i] = rand() % 100;
  }
}

void imprimeRegistros(int *registros){
  int i;
  for (i = 0; i < SIZE; i++)
  {
    printf("%d - ",registros[i]);
  }
}

void constroIndices(int *registros, int *kindex, int tamKindex){
}

int pesquisar(int chave, int *kindex, int *registros, int tamKindex){
  int i;
  printf("\n========== > Ainda não implementado <===============\n");
  // Procurando na tabela de índices
 return -1;
}

void ordenaRegistros(int *registros){
  printf("\n========== > Ainda não está ordenando registros <===============\n\n");
}

int main(){

    int registros[SIZE], tamKindex;
    tamKindex = SIZE/TAMINDICE;
    int kindex [tamKindex], chave,posicao;

   //Preenchendo o vetor de registros com números aleatórios
   preencheRegistros(registros);

   //Ordenar registros
   ordenaRegistros(registros);

   // Só pra testar a impressão
    imprimeRegistros(registros);

    //Constroi tabela de indices
    kindex[0] = registros[0];

    constroIndices(registros, kindex, tamKindex);

    printf("\n\nDigite a chave das informações que deseja procurar: ");
    scanf("%d", &chave);

    posicao = pesquisar(chave, kindex, registros, tamKindex);

    if (posicao!= -1)
      printf("\n\nA informação procurada encontra-se na posicao : %d\n", posicao);
    else
      printf("\n\nNão encontrado\n");

return 0;
}
