#include "bibliotecas.h"
#include "vetor.h"

void mostrar(VETOR* v) {
    printf("\n[");
    for (int i = 0; i < v->quantidade; i++)
    {
        printf("%d", v->dados[i]);
        if(i != v->quantidade - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}