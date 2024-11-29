#include "fila.h"

void main() {
    int escolha = 0;
    int quantidade = 0;
    FILA* primeiro = NULL;
    FILA* ultimo = NULL;

    do
    {
        system("cls");
        printf("-- Menu --\n");
        printf("{1} Retirar Senha\n");
        printf("{2} Chamar Próximo Cliente\n");
        printf("{3} Mostrar Fila de Atendimento\n");
        printf("{4} Fechar Atendimento\n");
        printf("Sua Escolha: ");
        scanf("%d", &escolha);
        
        printf("\n");
        switch (escolha)
        {
            case 1:
                enfileirar(&primeiro, &ultimo, &quantidade);
                break;
            case 2:
                desenfileirar(&primeiro, &ultimo, &quantidade);
                break;
            case 3:
                mostrar(&primeiro);
                break;
            case 4:
                break;
            default:
                printf("Escolha Inválida...\n");
                break;
        }

        system("pause");

    } while (escolha != 4);
    

    free(primeiro);
    free(ultimo);
}