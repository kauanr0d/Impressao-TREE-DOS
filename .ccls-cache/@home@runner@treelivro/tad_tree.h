#include <string.h>
typedef struct Nodo {
  struct Nodo *direita;
  struct Nodo *esquerda;
  char PALAVRA[60];
} Nodo;

typedef Nodo *Tree;

void iniciar_arvore(Tree *arvore);
void inserir_ordenado(Tree *arvore, char* elemento_add);
Nodo *busca_binaria(Tree *arvore, char* chave, int percorrido);
char* obter_elemento_buscado(Nodo *no);

void iniciar_arvore(Tree *arvore) { *arvore = NULL; }

void inserir_ordenado(Tree *arvore, char* elemento_add) {
  if (*arvore == NULL) {
    Nodo *no = (Nodo *)malloc(sizeof(Nodo));
    no->direita = NULL;
    no->esquerda = NULL;
    strcpy(no->PALAVRA,elemento_add);
    *arvore = no;
  } else {
    if (strcmp(elemento_add,(*arvore)->PALAVRA)>0) {
      inserir_ordenado(&((*arvore))->direita, elemento_add);
    } else if (strcmp(elemento_add,(*arvore)->PALAVRA)<0) {
      inserir_ordenado(&((*arvore))->esquerda, elemento_add);
    }
  }

}

Nodo *busca_binaria(Tree *arvore, char* chave, int percorrido) {
  if (strcmp(chave,(*arvore)->PALAVRA)==0) {
    return *arvore;
  } else {
    if (strcmp(chave,(*arvore)->PALAVRA)>0) {
      ++percorrido;
      printf("Iteração:%d\n",percorrido);
      return busca_binaria(&((*arvore))->direita, chave,percorrido);
    } else if (strcmp(chave,(*arvore)->PALAVRA)<0) {
      ++percorrido;
      printf("Iteração:%d\n",percorrido);
      return busca_binaria(&((*arvore))->esquerda, chave,percorrido);
    }
  }
  return NULL;
}
char* obter_elemento_buscado(Nodo *no) {
  if (no == NULL) {
    return NULL;
  } else {
    return no->PALAVRA;
  }
}

