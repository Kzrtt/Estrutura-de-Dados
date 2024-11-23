#include "bibliotecas.h"

#ifndef FILA_H
#define FILA_H

typedef struct fila FILA;

struct fila {
    int id;
    FILA* proxNo;
};

void enqueue(FILA** p, FILA** u);
void dequeue(FILA** p, FILA** u);
void buscar(FILA** p);
void mostrar(FILA** p);

#endif