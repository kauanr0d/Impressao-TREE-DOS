#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tad_tree.h"
#include "leitura_txt.h"

Tree arv;

void imprimir_DOS(Tree arv, int nivel){
  if(arv!=NULL){
    int aux_nivel = 0;
    while(aux_nivel<=nivel){
      printf("| ");
      aux_nivel++;
    }
    if(nivel>0)
      printf("↳");
    
    printf("%s\n", arv->PALAVRA);
   sleep(1);
    imprimir_DOS(arv->esquerda, nivel+1);
    imprimir_DOS(arv->direita, nivel+1);
  }
}

int main(void) {
  int nivel = 0;
  leitura_txt("tale.txt",&arv);
  imprimir_DOS(arv,nivel);
  return 0;
}