#include "bibliotecas.h"
#include "pilha.h"

void main() {
    PILHA* topo = NULL;
    int valor;

    printf("Insira o valor decimal: ");
    scanf("%d", &valor);

    while (1)
    {
        if(valor != 1) {
            empilhar(&topo, valor % 2);
        } else {
            empilhar(&topo, 1);
            break;
        }
        valor = valor / 2;
    }
    
    printf("O valor binário é: ");
    while (topo != NULL)
    {
        printf("%d", topo->valor);
        desempilhar(&topo);
    }
}