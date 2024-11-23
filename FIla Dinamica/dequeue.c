#include "fila.h"

void dequeue(FILA** p, FILA** u) {
    if(*p == NULL) {
        printf("\nA Fila já está vazia...\n");
        return;
    }

    if(*u == *p) {
        *u = NULL;
        *p = NULL;
        return;
    }

    FILA* aux = *p;
    *p = aux->proxNo;
    free(aux);

    printf("\nValor removido com sucesso!\n");
}