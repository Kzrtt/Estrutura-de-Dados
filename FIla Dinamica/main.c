#include "fila.h"

void main() {
    FILA* primeiroNo = NULL;
    FILA* ultimoNo = NULL;

    int escolha = 0;

    do
    {
        system("cls");
        printf("\nMenu: \n");
        printf("[1] Enfileirar\n");
        printf("[2] Desenfileirar\n");
        printf("[3] Buscar\n");
        printf("[4] Mostrar\n");
        printf("[5] Sair\n");
        printf("Sua Escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            enqueue(&primeiroNo, &ultimoNo);
            break;
        case 2:
            dequeue(&primeiroNo, &ultimoNo);
            break;
        case 3:
            buscar(&primeiroNo);
            break;
        case 4: 
            mostrar(&primeiroNo);
            break;
        case 5:
            break;
        default:
            printf("Opção Inválida...\n");
            break;
        }

        system("pause");

    } while (escolha != 5);

    free(primeiroNo);
    free(ultimoNo);
}