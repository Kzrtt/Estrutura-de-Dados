#include "bibliotecas.h"

void empilhar(PILHA* pilha, int* topo) {
    if(*topo == 9) {
        printf("A pilha está cheia!\n");
        return;
    }

    pilha[*topo + 1].proxNo = *topo;
    printf("Insira o id: ");
    scanf("%d", &pilha[*topo + 1].id);
    *topo += 1;
}