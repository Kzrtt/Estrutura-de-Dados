#include "lista.h"

void main() {
    LISTA* primeiro = NULL;
    LISTA* ultimo = NULL; 
    int escolha = 0;

    while (1)
    {
        system("cls");
        if(primeiro == NULL) {
            printf("-- Menu -- \n");
        } else {
            printf("-- ${Primeiro -> %d} Menu ${Ultimo -> %d} -- \n", primeiro->validador, ultimo->validador);
        }
        printf("[1] Inserir Fragmento\n");
        printf("[2] Mostrar Fragmentos\n");
        printf("[3] Sair\n");
        printf("Sua Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 3) {
            printf("\nSaindo...\n");
            break;
        }   

        switch (escolha)
        {
            case 1:
                inserirFragmento(&primeiro, &ultimo);
                break;
            case 2: 
                mostrar(&primeiro);
                break;
        default:
            printf("\nOpção Inválida...\n");
            break;
        }

        system("pause");
    }
    
    free(primeiro);
    free(ultimo);
}