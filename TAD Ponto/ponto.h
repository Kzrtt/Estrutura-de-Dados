#ifndef PONTO_H
#define PONTO_H

typedef struct {
    int x;
    int y;
} PONTO;

void ponto();
void validarIndice(int indice);
PONTO* criarPonto();
void exibirPonto(PONTO** pontos, int indice);
void editarPonto(PONTO** pontos, int indice);
void liberarPonto(PONTO** pontos, int indice);
void calcularDistancia(PONTO** pontos, int indiceUm, int indiceDois);
void imprimirPontos(PONTO** pontos);

#endif