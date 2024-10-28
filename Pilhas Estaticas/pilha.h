#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int id;
    int proxNo;
} PILHA;

void mostrar(PILHA* pilha, int topo);
void empilhar(PILHA* pilha, int* topo);
void desempilhar(PILHA* pilha, int* topo);

#endif