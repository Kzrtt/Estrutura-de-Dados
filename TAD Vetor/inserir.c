#include "bibliotecas.h"
#include "vetor.h"

void inserir(VETOR* v, int valor) {
    if(v->quantidade >= v->tamanho) {
        printf("Vetor está cheio...\n");
        return;
    } 

    v->dados[v->quantidade] = valor;
    v->quantidade++;
    printf("Valor inserido!\n");
}