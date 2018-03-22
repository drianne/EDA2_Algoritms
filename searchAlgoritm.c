#include<stdlib.h> // necessário para funções rand e srand

#include<stdio.h>

#include <time.h> // Usar função time para que esses valores não se repitam já que são chaves de registros

#define TAMREGISTROS 50
#define TAMINDICE 10

int comparaChaveValor(int a, int b){
  if (a > b){
    return 1;
  }
  if (a == b){
    return 0;
  }
  return -1;
}

int pesquisaIndex(int chave, int *kindex, int tamKindex){
  int i;
  for (i = 0;i < tamKindex ;i++) {
    if (comparaChaveValor(kindex[i], chave) == 1){
      return i;
    }
    if (comparaChaveValor(kindex[i], chave) == 0){
      return i *TAMINDICE;
    }
  }
  return -1;
}

int pesquisaRegistro(int *registros, int chave, int *kindex, int tamKindex){
  int i;
  int posicaoKindex = pesquisaIndex(chave, kindex, tamKindex);
  if (posicaoKindex != -1){
    for (i = ((posicaoKindex-1) * TAMINDICE); i < (posicaoKindex * TAMINDICE); i++) {
      if (comparaChaveValor(registros[i], chave) == 0){
        return i;
      }
    }
  } else{
      for (i = (tamKindex - 1)*TAMINDICE; i < TAMREGISTROS; i++) {
        if (comparaChaveValor(registros[i], chave) == 0){
          return i;
      }
    }
  }
  return -1;
}


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
  for(i=1; i < tamKindex; i++){
    kindex[i] = registros[TAMINDICE * i];
  }
  printf("\n=====================================================\n");
  for (i = 0; i < tamKindex; i++){
    printf("%d - ",kindex[i]);
  }
}

void ordenaRegistros(int *registros){
  int i, j, aux;
  for (i = 1; i < TAMREGISTROS; i++) {
    for (j = 0; j < TAMREGISTROS - 1; j++) {
      if (registros[j] > registros[j + 1]) {
        aux = registros[j];
        registros[j] = registros[j + 1];
        registros[j + 1] = aux;
      }
    }
  }
}


int main(){

  int registros[TAMREGISTROS], tamKindex;

  if(TAMREGISTROS%TAMINDICE > 0){
      tamKindex = (TAMREGISTROS/TAMINDICE) + 1;
  }else{
      tamKindex = TAMREGISTROS/TAMINDICE;
  }

  srand(time(NULL));

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

  posicao = pesquisaRegistro(registros, chave, kindex, tamKindex);

  if (posicao!= -1){
      printf("\n\nA chave informacao pesquisada esta na %dª posicao do vetor\n", posicao+1);
  }else {
      printf("A chave da informacao pesquisada nao se encontra no vetor de registros\n");
  }

  return 0;

}
