#ifndef TCACAPALAVRAS_H_INCLUDED
#define TCACAPALAVRAS_H_INCLUDED
#include "TCelula.h"
#include "TPalavra.h"

typedef struct TCacaPalavras{
TCelula** cabecaLinhas; // ponteiro duplo para armazenar cel. cabecas de cada linha
TCelula** cabecaColunas; // ponteiro duplo para armazenar cel. cabecas de cada coluna
int linhas;
int colunas;
} TCacaPalavras;

TCacaPalavras* criarMatriz (int linhas, int colunas); // aloca e  inicializa as celulas cabecas / retorna null em caso de falha

int preencherMatriz (TCacaPalavras *cp); // retorna em caso de sucesso e 0 em caso de falha

int buscarPalavra (TCacaPalavras *cp, TPalavra *palavra); // retoma 1 se for encontrada e 0 se nao for

void liberarMatriz (TCacaPalavras *cp); // libera TODA a memoria alocada na matriz

#endif // TCACAPALAVRAS_H_INCLUDED
