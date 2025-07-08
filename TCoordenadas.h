#ifndef TCOORDENADAS_H_INCLUDED
#define TCOORDENADAS_H_INCLUDED

typedef struct {
int linha; // indice da linha
int coluna; // indice da coluna
}TCoordenada;

struct TCacaPalavras;  // Forward declaration
typedef struct TCacaPalavras TCacaPalavras;

int coordenadaCriar (TCoordenada *coordenada, int i, int j);

int coordenadaVerificar (TCoordenada coordenada, TCacaPalavras *cp);

#endif // TCOORDENADAS_H_INCLUDED
