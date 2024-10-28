#include "pilha.h"

void mostrar(PILHA** topo) {
    char escape;
    if(*topo == NULL) {
        printf("A pilha está vázia...\n");
        return;
    }

    PILHA* temp = *topo;
    printf("\n[---------]\n");
    while(temp != NULL) {
        printf("|   {%d}   |\n", temp->id);
        temp = temp->proxNo;
    }
    printf("[---------]\n");
}