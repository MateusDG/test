#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TCoordenadas.h"
#include "TPalavra.h"

TPalavra palavraCriar (char *str) {
TPalavra palavraNova;
palavraNova.palavra = (char*)malloc(sizeof(char)*100); // aloca dinamicamente a string
if (palavraNova.palavra == NULL) exit(EXIT_FAILURE); // verifica se a alocacao foi bem sucedida
strcpy(palavraNova.palavra, str); // copia a string da origem para o destinatario
palavraNova.encontrada = 0;
coordenadaCriar(&palavraNova.inicio, -1, -1); // funcao TCoordenadas
coordenadaCriar(&palavraNova.fim, -1, -1);
return palavraNova;
}

void palavraDestruir (TPalavra *palavraNova) {
    if (palavraNova != NULL) {
        free(palavraNova->palavra); // libera string
        palavraNova->palavra = NULL; // anula o ponteiro
    }
}

void palavraImprimir (TPalavra palavra) {
if (palavra.encontrada == 1)
    printf ("%d %d %d %d %s", palavra.inicio.linha, palavra.inicio.coluna,
            palavra.fim.linha, palavra.fim.coluna, palavra.palavra); // impressao das coordenadas
else
    printf ("0 0 0 0 %s", palavra.palavra); // nao encontrou a palavra
}

int palavraMarcarEncontrada (TPalavra *palavra, TCoordenada inicio, TCoordenada fim) {
if (palavra != NULL) {
    palavra-> encontrada = 1;
    palavra-> inicio = inicio;
    palavra-> fim = fim;
  }
  return 1;
}




