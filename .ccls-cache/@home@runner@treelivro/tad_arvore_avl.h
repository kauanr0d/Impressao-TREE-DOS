
typedef struct Nodo {
  struct Nodo *direita;
  struct Nodo *esquerda;
  char PALAVRA[60];
  int altura;
} Nodo;

typedef Nodo *Tree;

void iniciar_arvore(Tree *arvore);
void inserir_ordenado(Tree *arvore, char *elemento_add);
Nodo *busca_binaria(Tree *arvore, char *chave, int percorrido);
char *obter_elemento_buscado(Nodo *no);
int altura(Tree arvore);
int fator_balanceamento(Tree arvore);
Nodo *rotacionar_esquerda(Nodo *arvore);
Nodo *rotacionar_direita(Nodo *arvore);
Nodo *rotacionar_direita_esquerda(Nodo *no);
Nodo *rotacionar_esquerda_direita(Nodo *no);
Nodo *balancear(Tree arvore);
int maior(int a, int b);

void iniciar_arvore(Tree *arvore) { *arvore = NULL; }

void inserir_ordenado(Tree *arvore, char *elemento_add) {
  if (*arvore == NULL) {
    Nodo *no = (Nodo *)malloc(sizeof(Nodo));
    no->direita = NULL;
    no->esquerda = NULL;
    strcpy(no->PALAVRA, elemento_add);
    *arvore = no;
  } else {
    if (strcmp(elemento_add, (*arvore)->PALAVRA) > 0) {
      inserir_ordenado(&((*arvore))->direita, elemento_add);
    } else if (strcmp(elemento_add, (*arvore)->PALAVRA) < 0) {
      inserir_ordenado(&((*arvore))->esquerda, elemento_add);
    }
  }
  (*arvore)->altura =
      maior(altura((*arvore)->esquerda), altura((*arvore)->direita)) + 1;
  *arvore = balancear(*arvore);
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

// RETORNAR ALTURA DO NÓ
int altura(Tree arvore) {
  if (arvore == NULL) {
    return 0;
  } else {
    return arvore->altura;
  }
}
// CALCULAR FATOR BALANCEAMENTO(F) DO NÓ
int fator_balanceamento(Tree arvore) {
  if (arvore == NULL) {
    return 0;
  } else {
    return altura(arvore->esquerda) - altura(arvore->direita);
    /*Diferença entre o nodo do filho esquerdp e o nodo do filho direito*/
  }
}
int maior(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
// F (-1<F>1) - ARVORE PRECISA SER BALANCEADA

Nodo *rotacionar_esquerda(
    Nodo *arvore) {            // caso fator de balanceamento seja maior que 1
  Nodo *aux = arvore->direita; // guardando nó em desequilibrio
  Nodo *esquerda =
      aux->esquerda; // criando local na esquerda p/ que nó seja abrigado

  // realizando rotação
  aux->esquerda = arvore; // colocando agora na esquerda elemento, a raiz passa
                          // a ser a esquerda do nó aux
  arvore->direita =
      esquerda; // sub-árvore direita passa a ser a esquerda do nó aux

  // atualizando alturas da arvore e do nodo
  arvore->altura = maior(altura(arvore->esquerda), altura(arvore->direita)) + 1;
  aux->altura = maior(altura(aux->esquerda), altura(aux->direita)) + 1;

  return aux;
}
Nodo *rotacionar_direita(Nodo *arvore) { // caso fator seja menor que -1
  Nodo *aux = arvore->esquerda;
  Nodo *direita = aux->direita;

  // realizando rotação
  aux->direita = arvore;
  arvore->esquerda = direita;

  // atualizando alturas
  arvore->altura = maior(altura(arvore->esquerda), altura(arvore->direita)) + 1;
  aux->altura = maior(altura(aux->esquerda), altura(aux->direita)) + 1;

  return aux;
}

Nodo *rotacionar_direita_esquerda(Nodo *no) {
  no->direita = rotacionar_direita(no->direita);
  return rotacionar_esquerda(no);
}
Nodo *rotacionar_esquerda_direita(Nodo *no) {
  no->esquerda = rotacionar_esquerda(no->esquerda);
  return rotacionar_direita(no);
}

Nodo *balancear(Tree arvore) {
  int fb = fator_balanceamento(arvore);

  if (fb < -1 && fator_balanceamento(arvore->direita) <= 0) {
    arvore = rotacionar_esquerda(arvore);
  } else if (fb > 1 && fator_balanceamento(arvore->esquerda) >= 0) {
    arvore = rotacionar_direita(arvore);
  } else if (fb > 1 && fator_balanceamento(arvore->esquerda) < 0) {
    arvore = rotacionar_esquerda_direita(arvore);
  } else if (fb < -1 && fator_balanceamento(arvore->direita) > 0) {
    arvore = rotacionar_direita_esquerda(arvore);
  }
  return arvore;
}
