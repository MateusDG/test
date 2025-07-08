#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TCoordenadas.h"
#include "TCelula.h"
#include "TPalavra.h"
#include "TCacaPalavras.h"

TCacaPalavras* criarMatriz (int linhas, int colunas){
TCacaPalavras *cp = (TCacaPalavras*)malloc(sizeof(TCacaPalavras));
if (cp == NULL) return NULL; // retorna null em caso de erro com a alocacao de memoria
cp-> linhas = linhas;
cp-> colunas = colunas;
// alocao de memoria para cabecas das linhas
cp-> cabecaLinhas = (TCelula**)malloc((linhas + 2) * sizeof(TCelula*));
if (cp-> cabecaLinhas == NULL){
    free(cp);
    return NULL;
  }
// alocacao de memoria para cabecas das colunas
cp->cabecaColunas = (TCelula**)malloc((colunas + 2) * sizeof(TCelula*));
if (cp-> cabecaColunas == NULL) {
    free(cp-> cabecaLinhas);
    free(cp);
    return NULL;
  }
// inicializacao de celulas cabeca das linhas (bordas+)
for (int i = -1; i < linhas; i++){
    cp-> cabecaLinhas[i + 1] = criaCelula('\0', -1, -1); // cria a celula cabeca
// faz elas apontarem apra si mesmas
    cp-> cabecaLinhas[i + 1]-> direita = cp-> cabecaLinhas[i + 1];
    cp-> cabecaLinhas[i + 1]-> esquerda = cp-> cabecaLinhas[i + 1];
  }
// inicializacao das celulas cabeca das colunas (bordas+)
for (int j = -1; j < colunas; j++){
    cp-> cabecaColunas[j + 1] = criaCelula('\0', -1, -1); // cria celula cabeca
// faz elas apontarem para si mesmas
    cp-> cabecaColunas[j + 1]-> abaixo = cp-> cabecaColunas[j + 1];
    cp-> cabecaColunas[j + 1]-> acima = cp-> cabecaColunas[j + 1];
  }
return cp;
}

int preencherMatriz (TCacaPalavras *cp){
if (cp == NULL) return 0;

for (int i = 0; i < cp-> linhas; i++){  // percorre as linhas da matriz
    for (int j = 0; j < cp-> colunas; j++){ // percorre as colunas da matriz
        char letra;
        scanf (" %c", &letra); // pega a letra para montar o caca palavras
        TCelula *nova = criaCelula(letra, i, j);
        inserirLinha(cp-> cabecaLinhas[i + 1], nova); // soma 1 para pular as bordas
        inserirColuna(cp-> cabecaColunas[j + 1], nova);

    }
  }
return 1;
}

int buscarPalavra (TCacaPalavras *cp, TPalavra *palavra){
// verificacao inicial para que as variaveis nao sejam vazias
if (cp == NULL || palavra == NULL || palavra-> palavra == NULL) return 0;
int tamanho = strlen(palavra-> palavra); // funcao do string.h usada para medir o tamanho da string
if (tamanho == 0) return 0;
char primeiraLetra = palavra-> palavra[0];
int direcoes[8][2] = { // todas as direcoes possiveis
{0, 1},  // direita
{0, -1}, // esquerda
{1, 0},  // baixo
{-1, 0}, // cima
{1, 1},  // diagonal inf direita
{1, -1}, // diagonal inf esquerda
{-1, 1}, // diagonal sup direita
{-1, -1} // diagonal sup esquerda
};
// percorre a matriz (nesse caso nao necessita de um aninhado de for para i e j pois
// a matriz sera percorrida por meio de ponteiros e nao vetores
for (int i = 0; i < cp-> linhas; i++){
   TCelula *atual = cp-> cabecaLinhas[i + 1]-> direita; // primeira celula da linha
   while (atual != cp-> cabecaLinhas[i + 1]){ // enquanto nao voltar a cabeca...
       if (atual-> letra == primeiraLetra){
        for (int dir = 0; dir < 8; dir++){ // verifica as 8 direcoes
            int dl =  direcoes[dir][0];
            int dc = direcoes[dir][1];
            TCelula *cel = atual;
            int k;
            for (k = 1; k < tamanho; k++){ // na direcao atual, verifica letra por eltra
                TCelula *proximo = NULL; // encontra o proximo vizinho da direcao
                if (dl == 0){
                    proximo = (dc > 0) ? cel->direita : cel->esquerda; // horizontalmente
                } else if (dc == 0) {
                    proximo = (dl > 0) ? cel->abaixo : cel->acima; // verticalmente
                } else {
                    TCelula *temp = (dl > 0) ? cel->abaixo : cel->acima; // diagonalmente
                    if (temp != NULL) {
                        proximo = (dc > 0) ? temp->direita : temp->esquerda;
                    }
                }
                // verfiica se o proximo � valido
                if (proximo == NULL || proximo-> linha == -1 || proximo-> coluna == -1 || proximo-> letra != palavra->palavra[k])
                    break;
                cel = proximo;

            }
            if (k == tamanho){ // se todas as letras forem encontradas
                palavra-> encontrada = 1;
                coordenadaCriar(&palavra-> inicio, atual-> linha, atual-> coluna);
                coordenadaCriar(&palavra-> fim, cel-> linha, cel-> coluna);
                return 1;
            }
        }
      }
      atual = atual-> direita;
   }
}
return 0;
}

void liberarMatriz (TCacaPalavras *cp){
if (cp == NULL) return;
// libera as celulas normais que compoem a matriz
for (int i = 0; i < cp-> linhas; i++){
   TCelula *atual = cp-> cabecaLinhas[i + 1]-> direita; // peimeira celula da linha i
   while (atual != cp-> cabecaLinhas[i + 1]){ // enquanto nao voltar a cabeca...
        TCelula *proximo = atual-> direita; // salva a referencia para a proxima celula
        free(atual); // libera a celula atual
        atual = proximo; // atualiza atual para proxima celula
   }
 }
// libera celulas cabeca das linhas
for (int i = -1; i <= cp-> linhas; i++){
    free(cp-> cabecaLinhas[i + 1]);
 }
// libera celulas cabeca das colunas
for (int j = -1; j <= cp-> colunas; j++){
    free(cp-> cabecaColunas[j + 1]);
 }
// libera os vetores de cabecas e a estrutura principal
free(cp-> cabecaLinhas);
free(cp-> cabecaColunas);
free(cp);
}








