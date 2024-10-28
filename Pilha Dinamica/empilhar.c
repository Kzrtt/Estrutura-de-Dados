#include "pilha.h"

void empilhar(PILHA** topo) {
    PILHA* nova = (PILHA*) malloc(sizeof(PILHA));
    if(nova == NULL) {
        printf("Erro ao Alocar a memória\n");
        return;
    }
    
    printf("Insira o id: ");
    scanf("%d", &nova->id);
    nova->proxNo = *topo;
    *topo = nova; 
}