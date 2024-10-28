#include "bibliotecas.h"

void desempilhar(PILHA* pilha, int* topo) {
    if(*topo == -1) {
        printf("A pilha está vázia...\n");
        return;
    }

    pilha[*topo].id = 0;
    pilha[*topo].proxNo = -1;
    *topo -= 1;
}