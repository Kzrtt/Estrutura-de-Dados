#include "pilha.h"

void desempilhar(PILHA** topo) {
    if(*topo == NULL) {
        printf("A pilha está vázia...\n");
        return;
    }

    PILHA* temp = *topo;
    *topo = temp->proxNo;

    free(temp);
}