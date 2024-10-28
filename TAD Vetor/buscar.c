#include "bibliotecas.h"
#include "vetor.h"

int buscar(VETOR* v, int valor) {
    if(v == NULL || v->dados == NULL) {
        return -1;
    }

    for (int i = 0; i < v->quantidade; i++)
    {
        if(v->dados[i] == valor) {
            return i;
        }
    }
    
    return -1;
}