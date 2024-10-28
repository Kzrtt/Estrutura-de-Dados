#include "bibliotecas.h"

void main() {
    int topo = -1, aux = -1, escolha = 0;
    PILHA pilha[10];

    for (int i = 0; i < 10; i++)
    {
        pilha[i].id = 0;
        pilha[i].proxNo = -1;
    }

    while(1) {
        printf("\n == Menu {%d} == \n", topo);
        printf("[1] Mostrar\n");
        printf("[2] Empilhar\n");
        printf("[3] Desempilhar\n");
        printf("[4] Sair\n");
        printf("Sua Escolha: ");
        scanf("%d", &escolha);
        printf("\n");

        if(escolha == 4) {
            printf("Saindo...\n");
            break;
        }

        switch (escolha)
        {
        case 1:
            mostrar(pilha, topo);
            break;
        case 2:
            empilhar(pilha, &topo);
            break;
        case 3:
            desempilhar(pilha, &topo);
            break;
        default:
            printf("Escolha inválida...\n");
            break;
        }
    }
}