#include "lista.h"

void main() {
    int quantidade = 0;
    LISTA* primeiro = NULL;
    LISTA* ultimo = NULL;

    int escolha = 0;

    do
    {
        system("cls");
        if(primeiro != NULL) {
            printf("Primeiro: %d | Ultimo: %d\n\n", primeiro->num, ultimo->num);
        } else {
            printf("Primeiro: NULL | Ultimo: NULL\n\n");
        }
        printf("-- Menu --\n");
        printf("{1} Inserir Valor\n");
        printf("{2} Remover Valor\n");
        printf("{3} Buscar Valor\n");
        printf("{4} Mostrar Lista\n");
        printf("{5} Sair\n");
        printf("Sua Escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                inserir(&primeiro, &ultimo, &quantidade);
                break;
            case 2:
                remover(&primeiro, &ultimo, &quantidade);
                break;
            case 3: {
                int pos = 0;

                if(quantidade == 0) {
                    printf("\nA Lista está vázia...\n");
                    break;
                }

                printf("\nTamanho Lista: %d\n", quantidade);
                printf("Deseja buscar qual valor: ");
                scanf("%d", &pos);

                if(pos > quantidade || pos < 1) {
                    printf("\nOpção Inválida...\n");
                    break;
                }

                LISTA* temp = buscar(&primeiro, pos);
                if(temp == NULL) {
                    printf("\nA Lista está vazia...\n");
                    break;
                }

                printf("\nO valor é: [%d]\n", temp->num);
                break;
            }
            case 4: 
                mostrar(&primeiro);
                break;
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nEscolha Inválida...\n");
                break;
        }

        system("pause");

    } while (escolha != 5);
    
}