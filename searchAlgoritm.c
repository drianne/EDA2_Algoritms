#include<stdlib.h> // necessário para funções rand e srand

#include<stdio.h>

#include <time.h> // Usar função time para que esses valores não se repitam já que são chaves de registros

#define TAMREGISTROS 50
#define TAMINDICE 10

void preencheRegistros(int *registros){
  int i, j, status;
  for (i = 0; i < TAMREGISTROS; ++i) {
        //Compara o valor inserido con os outros para evitar repeticoes
       do {
          registros[i] = rand() % (TAMREGISTROS+300);
          status = 1;
          for (j = 0; (j < i) && (status == 1); ++j)
             if (registros[i] == registros[j])
                status = 0;
       } while (status == 0);
    }
}

void imprimeRegistros(int *registros){
  int i;
  for (i = 0; i < TAMREGISTROS; i++){
    printf("%d - ",registros[i]);
  }
}

void constroIndices(int *registros, int *kindex, int tamKindex){
  int i;
  for(i=1; i <  tamKindex; i++){
    kindex[i] = registros[TAMINDICE * i];
  }
  printf("\n\n=====================================================\n");
  printf("\nTabela de kindex\n");
  for (i = 0; i < tamKindex; i++){
    printf("%d - ",kindex[i]);
  }
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

    int registros[TAMREGISTROS], tamKindex;
    tamKindex = TAMREGISTROS/TAMINDICE;
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
