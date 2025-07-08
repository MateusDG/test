#include <stdlib.h>
#include "TCoordenadas.h"
#include "TPalavra.h"
#include "TCelula.h"

TCelula* criaCelula (char letra, int linha, int coluna){
TCelula* nova = (TCelula*)malloc(sizeof(TCelula)); // aloca memoria para nova
nova-> letra = letra; // inicializacao de parametros
nova-> linha = linha;
nova-> coluna = coluna;
nova-> direita = nova-> esquerda = nova-> acima = nova-> abaixo = NULL;
// acima, foram inicializadas as celulas, todas apontando para null ate que sejam
// iniciadas na matriz >> nao estao conectadas a ninguem da matriz ainda
return nova;
}

void destroiCelula (TCelula *celula){
if (celula == NULL) return; // se celula igual a NULL ja esta zerada
free(celula); // libera o espaco na memoria
}

int inserirLinha (TCelula *cabecaLinha, TCelula *novaCelula){
if (cabecaLinha == NULL || novaCelula == NULL) return 0; // ponteiros invalidos
TCelula *atual = cabecaLinha-> direita; // primeira celula apos a cabeca
TCelula *anterior = cabecaLinha;
// ordenada por colunas, o bloco abaixo percorre a linha ate
// achar a posicao correta
while (atual != cabecaLinha && atual-> coluna < novaCelula-> coluna){
   anterior = atual;
   atual = atual-> direita;
}
// insere celula ano meio da anterior e da atual
novaCelula-> direita = atual;
novaCelula-> esquerda = anterior;
anterior-> direita = novaCelula;
atual-> esquerda = novaCelula;
return 1; // sucesso
}

int inserirColuna(TCelula *cabecaLinha, TCelula *novaCelula){
if (cabecaLinha == NULL || novaCelula == NULL) return 0; // ponteiros invalidos
TCelula *atual = cabecaLinha-> abaixo;
TCelula *anterior = cabecaLinha;
// ordenada por linha, o bloco abaixo percorre a coluna ate
// achar a posicao correta
while (atual != cabecaLinha && atual-> linha < novaCelula-> linha){
    anterior =  atual;
    atual = atual-> abaixo;
}
// insere celula no meio da anterior e da atual
novaCelula-> abaixo = atual;
novaCelula-> acima = anterior;
anterior-> abaixo = novaCelula;
atual-> acima = novaCelula;
return 1; // sucesso
}

int celulaehCabeca (const TCelula *celula) { // verifica se e uma celula cabeca
return (celula != NULL && celula-> linha == -1 && celula-> coluna == -1);
}
