#include "bibliotecas.h"

#ifndef PILHA_H
#define PILHA_H

typedef struct pilha PILHA;

struct pilha {
    int valor;
    PILHA* proxNo;
};

void mostrar(PILHA** topo) {
    char escape;
    if(*topo == NULL) {
        printf("A pilha está vázia...\n");
        return;
    }

    PILHA* temp = *topo;
    printf("\n[---------]\n");
    while(temp != NULL) {
        printf("|    %c    |\n", temp->valor);
        temp = temp->proxNo;
    }
    printf("[---------]\n");
}

void empilhar(PILHA** topo, int valor) {
    PILHA* nova = (PILHA*) malloc(sizeof(PILHA));
    if(nova == NULL) {
        printf("Erro ao Alocar a memória\n");
        return;
    }
    
    nova->valor = valor;
    nova->proxNo = *topo;
    *topo = nova; 
}

void desempilhar(PILHA** topo) {
    if(*topo == NULL) {
        printf("A pilha está vázia...\n");
        return;
    }

    PILHA* temp = *topo;
    *topo = temp->proxNo;

    free(temp);
}

#endif