#ifndef TPALAVRA_H_INCLUDED
#define TPALAVRA_H_INCLUDED
#include "TCoordenadas.h"

typedef struct {
char* palavra; // string da palavra
TCoordenada inicio; // posicao inicial
TCoordenada fim; // posicao final
int encontrada; // 0 se nao foi encontrada e 1 se foi
} TPalavra;

TPalavra palavraCriar (char *str); // cria palavra

void palavraDestruir (TPalavra *palavraNova); // libera a memoria

void palavraImprimir (TPalavra palavra); // imprime na tela as coorenadas e a palavra

int palavraMarcarEncontrada (TPalavra *palavra, TCoordenada inicio, TCoordenada fim); // marca a palavra encontrada e a armazena

#endif // TPALAVRA_H_INCLUDED
