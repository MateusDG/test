#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TCoordenadas.h"
#include "TCelula.h"
#include "TPalavra.h"
#include "TCacaPalavras.h"

int main(){
int linhas, colunas, numPalavras;
printf ("Insira as dimensoes da matriz\n"); // ler dimensoes da matriz
if (scanf("%d %d", &linhas, &colunas) != 2){ // matriz com apenas linhas e colunas
    printf ("Erro! Dimensoes invalidas!\n"); // saida caso insira algo invalido
    return 1;
}
while (getchar() != '\n'); // limpa o buffer
// criar matriz do caca palavras
TCacaPalavras *cp = criarMatriz(linhas, colunas);
if (cp == NULL) {
    printf ("Erro! Nao foi possivel criar a matriz do caca palavras!\n");
    return 1;
}
printf ("Preencha sua matriz com letras minusculas:\n");
// preencher a matriz com letras
if (!preencherMatriz(cp)){
    printf ("Erro! Nao foi possivel preeceher a matriz!\n");
    liberarMatriz(cp);
    return 1;
}
printf ("Insira a quantidade de palavras:\n");
// ler o numero de palavras
if (scanf("%d", &numPalavras) != 1){
    printf ("Erro! Nao foi possivel ler o numero de palavras!\n");
    liberarMatriz(cp);
    return 1;
}
while (getchar() != '\n'); // limpa o buffer novamente
// criar e processar cada palavra
for (int i = 0; i < numPalavras; i++){
    char palavraString[100];
    // ler as palavras sem espacamentos
    if (scanf("%99s", palavraString) != 1){
        printf ("Erro! Nao foi possivel ler a palavra!\n");
        liberarMatriz(cp);
        return 1;
    }
while (getchar() != '\n'); // limpa o buffer apos ler cada palavra
// criar estrutura da palavra
TPalavra palavra = palavraCriar(palavraString);

// buscar a palavra na matriz
if (buscarPalavra(cp, &palavra)){
    // se encontrou a palavra, imprime as coordenadas
    printf ("%d %d %d %d %s\n", palavra.inicio.linha, palavra.inicio.coluna,
            palavra.fim.linha, palavra.fim.coluna, palavra.palavra);
} else // se nao encontrou, imprimir as coorenadas default
    printf ("0 0 0 0 %s\n", palavra.palavra);
// liberar memoria da palavra
palavraDestruir(&palavra);
}
// liberar toda a estrutura da matriz
liberarMatriz(cp);
return 0;
}





















