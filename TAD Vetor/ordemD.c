#include "bibliotecas.h"
#include "vetor.h"

void ordemD(VETOR* v) {
    for (int i = 0; i < v->quantidade; i++)
    {
        for(int j = i + 1; j < v->quantidade; j++) {
            if(v->dados[i] <= v->dados[j]) {
                int temp = v->dados[j];
                v->dados[j] = v->dados[i];
                v->dados[i] = temp;
            }
        }
    }
    
    printf("O vetor foi ordenado!\n");
    mostrar(v);
}