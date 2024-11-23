#include "fila.h"

void mostrar(FILA** p) {
    if(*p == NULL) {
        printf("\nA Fila está vázia...\n");
        return;
    }

    FILA* temp = *p;
    printf("\nFila: ");
    while (temp != NULL)
    {
        printf("[%d]", temp->id);
        temp = temp->proxNo;
    }
    printf("\n");
}