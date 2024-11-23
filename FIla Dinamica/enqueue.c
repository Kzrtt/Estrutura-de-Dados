#include "fila.h"

void enqueue(FILA** p, FILA** u) {
    FILA* novoNo = (FILA*) malloc(sizeof(FILA));

    if(novoNo == NULL) {
        printf("Erro ao alocar na memória\n");
        return;
    }

    printf("\nInsira o id: ");
    scanf("%d", &novoNo->id);
    novoNo->proxNo = NULL;

    if(*p == NULL) {
        *p = *u = novoNo;
    } else {
        (*u)->proxNo = novoNo;
        *u = novoNo;
    }

    printf("Valor adicionado com sucesso!\n");
}