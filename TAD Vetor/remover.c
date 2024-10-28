#include "bibliotecas.h"
#include "vetor.h"

void remover(VETOR* v, int valor) {
    int indice = buscar(v, valor);

    if(indice == -1) {
        printf("Valor não encontrado...\n");
        return;
    }

    for (int i = indice; i < v->quantidade; i++)
    {
        v->dados[i] = v->dados[i + 1];
    }
    v->quantidade--;
    printf("vetor[%d] = %d\n", indice, valor);
    printf("Valor removido!\n");   
}