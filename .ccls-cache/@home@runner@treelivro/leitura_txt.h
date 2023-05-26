#include <string.h>
#define MAX_LINHA 256
#define MAX_PALAVRA 60
int leitura_txt(char *nome_arquivo, Tree *arv);

int leitura_txt(char *nome_arquivo, Tree *arv) {

  FILE *arquivo_txt = fopen(nome_arquivo, "r");
  char palavra_lida[MAX_PALAVRA];
  char linha_inteira[MAX_LINHA];
  char *token;
  int total_linhas = 0;
  int total_palavras = 0;

  while (!feof(arquivo_txt)) {
    fgets(linha_inteira, MAX_LINHA, arquivo_txt);
    token = strtok(linha_inteira," \"''.,;:?!-+[]()/*#%$_\n"); //delimitando o caracteres a serem removidos
    while (token != NULL) { // pegar a string maior linha_inteira e dividir em  strings menores 
      if (strlen(palavra_lida) > 0) {
        strcpy(palavra_lida, token);
        inserir_ordenado(arv, palavra_lida);
        total_palavras++;
      }
      token = strtok(NULL, " \"''.,;:?!-+[]()/*#%$_\n"); // removo os tokens a
                                                       // cada iteração do laço
    }
    total_linhas++;
  }
  printf("total linhas:%d\n", total_linhas);
  printf("total de palavras lidas:%d\n", total_palavras);
  fclose(arquivo_txt);
  return 1;
}