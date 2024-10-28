#include "bibliotecas.h"

#ifndef PILHA_H
#define PILHA_H

typedef struct pilha PILHA;

struct pilha {
    int id;
    PILHA* proxNo;
};

void mostrar(PILHA** topo);
void empilhar(PILHA** topo);
void desempilhar(PILHA** topo);

#endif