#include "bibliotecas.h"
#include "pilha.h"

void main() {
    PILHA* topo = NULL;
    char expressao[100];

    printf("Insira a expressão matemática: ");
    scanf("%[^\n]", &expressao);

    for (int i = 0; i < 100; i++)
    {
        if(expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            empilhar(&topo, expressao[i]);
        }

        if(expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            if((topo->valor) == '(' && expressao[i] == ')') {
                desempilhar(&topo);
            } else if((topo->valor) == '[' && expressao[i] == ']') {
                desempilhar(&topo);
            } else if((topo->valor) == '{' && expressao[i] == '}') {
                desempilhar(&topo);
            }
        }
    }
    
    if(topo == NULL) {
        printf("A expressão está correta!!");
    } else {
        printf("A expressão está incorreta!!");
        mostrar(&topo);
    }
}