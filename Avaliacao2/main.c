#include "fila.h"

void main() {
    FILA* primeiro = NULL;
    FILA* ultimo = NULL; 
    int escolha = 0;

    while (1)
    {
        system("cls");
        printf("-- Menu --\n");
        printf("[1] Inserir Missão\n");
        printf("[2] Enviar Missão\n");
        printf("[3] Mostrar Missões\n");
        printf("[4] Adiantar Missão\n");
        printf("[5] Organizar Missões\n");
        printf("[6] Sair\n");
        printf("Sua Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 6) {
            printf("\nSaindo...\n");
            break;
        }   

        switch (escolha)
        {
            case 1:
                inserir(&primeiro, &ultimo);
                break;
            case 2: 
                enviarMissao(&primeiro, &ultimo);
                break;
            case 3:
                mostrar(&primeiro);
                break;
            case 4: {
                int pos = 0;

                printf("\nQual Missão deseja adiantar: ");
                scanf("%d", &pos);

                adiantarMissao(&primeiro, &ultimo, pos);
                break;
            }
            case 5:
                reorganizar(&primeiro, &ultimo);
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