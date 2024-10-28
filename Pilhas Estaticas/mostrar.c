#include "bibliotecas.h"

void mostrar(PILHA* pilha, int topo) {
    if(topo == -1) {
        printf("A pilha está vázia...\n");
        return;
    }

    printf("[\n");
    for (int i = topo; i >= 0; i--)
    {
        printf("    {Id: %d, ProxNo: %d}", pilha[i].id, pilha[i].proxNo);
        printf("\n");
    }
    printf("]\n");
}