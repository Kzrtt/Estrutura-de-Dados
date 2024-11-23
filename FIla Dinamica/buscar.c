#include "fila.h"

void buscar(FILA** p) {
    int valor = 0;
    int count = 0;

    if(*p == NULL) {
        printf("\nA Fila está vázia");
        return;
    }

    printf("\nInsira o valor a ser buscado: ");
    scanf("%d", &valor);

    FILA* temp = *p;
    while (temp != NULL)
    {
        if(temp->id == valor) {
            printf("Valor: [%d] na %d° Posicao\n", temp->id, count + 1);
            return;
        }
        temp = temp->proxNo;
        count++;
    }

    printf("\nO valor [%d] não está na Fila\n", valor);
}

