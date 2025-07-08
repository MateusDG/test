#include "TCoordenadas.h"
#include "TCacaPalavras.h"
#include <stddef.h>


void coordenadaCriar (TCoordenada *coordenada, int i, int j){
    if (coordenada == NULL) return;
    coordenada->linha = i;
    coordenada->coluna = j;
}

int coordenadaVerificar(TCoordenada coordenada, TCacaPalavras *cp) {
if (coordenada.linha < 0 || coordenada.linha >= cp-> linhas) return 0; // linha invalida
if (coordenada.coluna < 0 || coordenada.coluna >= cp-> colunas) return 0; // coluna inavalida
return 1; // coordenada valida
}

