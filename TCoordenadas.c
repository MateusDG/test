#include "TCoordenadas.h"
#include "TCacaPalavras.h"

int coordenadaCriar (TCoordenada *coordenada, int i, int j){
coordenada->linha = i;
coordenada->coluna = j;
return coordenada;
}

int coordenadaVerificar(TCoordenada coordenada, TCacaPalavras *cp) {
if (coordenada.linha < 0 || coordenada.linha >= cp-> linhas) return 0; // linha invalida
if (coordenada.coluna < 0 || coordenada.coluna >= cp-> colunas) return 0; // coluna inavalida
return 1; // coordenada valida
}

