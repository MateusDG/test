#ifndef TCELULA_H_INCLUDED
#define TCELULA_H_INCLUDED

typedef struct TCelula {
struct TCelula *direita, *esquerda, *acima, *abaixo; // ponteiros para as posicoes
int linha, coluna; // posicao na matriz
char letra; // caractere armazenado
} TCelula;

TCelula* criaCelula (char letra, int linha, int coluna); // cria uma celula

void destroiCelula (TCelula *celula); // libera a memoria da celula

int inserirLinha (TCelula *cabeca, TCelula *nova); // insere uma celula na linha

int inserirColuna (TCelula *cabeca, TCelula *nova); // insere uma celula na coluna

int celulaehCabeca (const TCelula *celula); // verifica se a celula e cabeca

#endif // TCELULA_H_INCLUDED
