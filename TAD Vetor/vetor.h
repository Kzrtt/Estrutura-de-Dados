#ifndef VETOR_H
#define VETOR_H

typedef struct {
    int* dados;
    int tamanho;
    int quantidade;
} VETOR;

void inserir(VETOR* v, int valor);
void mostrar(VETOR* v);
int buscar(VETOR* v, int valor);
void remover(VETOR* v, int valor);
void ordemC(VETOR* v);
void ordemD(VETOR* v);

#endif