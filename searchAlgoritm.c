#include<stdlib.h>
#include<stdio.h>
#include <time.h>

#define TAMREGISTROS 100
#define TAMINDICE 10

void preencheRegistros(int *registros){
  int i, j, status;
  for (i = 0; i < TAMREGISTROS; ++i) {//Compara o valor inserido con os outros para evitar repeticoes
       do {
          registros[i] = rand() % (TAMREGISTROS+300);
          status = 1;
          for (j = 0; (j < i) && (status == 1); ++j){
             if (registros[i] == registros[j])
                status = 0;
          }
       } while (status == 0);
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

void imprimeRegistros(int *registros){
  int i;
  printf("\nREGISTROS\n");
  printf("--------------------------------------------------------------------------------------------------------------------------------------------\n" );
  for (i = 0; i < TAMREGISTROS && registros[i]!=999999999; i++){
    printf("%d - ",registros[i]);
  }
}

void constroIndices(int *registros, int *kindex, int tamKindex){
  int i;
  kindex[0] = registros[0];
  for(i=1; i < tamKindex && registros[i]!= 999999999; i++){
    kindex[i] = registros[TAMINDICE * i];
  }
}

void imprimeIndices(int *kindex, int tamKindex){
  int i;
  printf("\n\nKINDICES\n");
  printf("--------------------------------------------------------------------------------------------------------------------------------------------\n" );
  for (i = 0; i < tamKindex; i++){
    printf("%d - ",kindex[i]);
  }
}

int pesquisaIndex(int chave, int *kindex, int tamKindex){
  int i;
  for (i = 0;i < tamKindex ;i++) {
    if ((kindex[i] > chave) || (kindex[i] == chave))
      return i;
  }
  return -1;
}

int pesquisaRegistro(int *registros, int chave, int *kindex, int tamKindex){
  int i;
  int posicaoKindex = pesquisaIndex(chave, kindex, tamKindex);
  if(posicaoKindex == 0)
    return posicaoKindex;
  else if (posicaoKindex != -1){
    for (i = ((posicaoKindex-1) * TAMINDICE); i <= (posicaoKindex * TAMINDICE)  && registros[i]!= 999999999; i++) {
      if (registros[i] == chave){
        return i;
      }
    }
  } else{
      for (i = (tamKindex - 1)*TAMINDICE; i < TAMREGISTROS && registros[i]!= 999999999; i++) {
        if (registros[i] == chave){
          return i;
      }
    }
  }
  return -1;
}

void apagaRegistro(int *registros, int chave, int *kindex, int tamKindex){
  int posicao;

  posicao = pesquisaRegistro(registros,chave,kindex,tamKindex);
  if(posicao != -1){
    registros[posicao] = 999999999;
    ordenaRegistros(registros);
    constroIndices(registros, kindex, tamKindex);
    printf("\nRegistro apagado\n");
  }
  else
    printf("O registro que deseja apagar não consta na base\n");
}

int menu(){
  int op;
  printf("\n\n\n==========  MENU =============================================================================================================\n");
  printf("1 - Pesquisar Elemento \n");
  printf("2 - Ver todos os registros\n");
  printf("3 - Ver os kindexes gerados\n");
  printf("4 - Apagar Registro\n");
  printf("0 - SAIR");
  printf("\n");
  scanf("%d", &op);
  return op;
}

int main(){

  int registros[TAMREGISTROS], tamKindex, opcao;

  if(TAMREGISTROS%TAMINDICE > 0)
    tamKindex = (TAMREGISTROS/TAMINDICE) + 1;
  else
    tamKindex = TAMREGISTROS/TAMINDICE;

  srand(time(NULL));

  int kindex [tamKindex], chave,posicao;

  preencheRegistros(registros);
  ordenaRegistros(registros);
  constroIndices(registros, kindex, tamKindex);
  imprimeRegistros(registros);
  imprimeIndices(kindex, tamKindex);

  do{
    opcao = menu();
    switch (opcao) {
      case 0: printf("Encerrando ...\n");
      break;
      case 1:
        system("clear");
        printf("\n\nDigite a chave das informações que deseja procurar: ");

        scanf("%d", &chave);

        posicao = pesquisaRegistro(registros, chave, kindex, tamKindex);

        if (posicao!= -1)
          printf("\n\nA informacao pesquisada é a %dª na lista de registros\n", posicao+1);
        else
          printf("A informacao pesquisada nao se encontra no vetor de registros\n");
      break;
      case 2: imprimeRegistros(registros);
      break;
      case 3: imprimeIndices(kindex, tamKindex);
      break;
      case 4:
        printf("\nRegistro que deseja apagar: ");
        scanf("%d",&chave);
        apagaRegistro(registros, chave, kindex, tamKindex);
      break;
      default:
        printf("Opcao Inexistente\n");
    }
  }while (opcao!=0);
  return 0;

}
