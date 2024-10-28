#include "pilha.h"

void main() {
    int escolha = 0;
    PILHA* pilha = NULL;

    while(1) {
        system("cls");
        printf("\n == Menu == \n");
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
            mostrar(&pilha);
            break;
        case 2:
            empilhar(&pilha);
            break;
        case 3:
            desempilhar(&pilha);
            break;
        default:
            printf("Escolha inválida...\n");
            break;
        }

        system("pause");
    }
}