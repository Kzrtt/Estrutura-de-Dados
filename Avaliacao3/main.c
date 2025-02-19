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
           printf("Primeiro: %d | Ultimo: %d\n\n", primeiro->id, ultimo->id);
        } else {
            printf("Primeiro: NULL | Ultimo: NULL\n\n");
        }
        printf("-- Menu --\n");
        printf("{1} Inserir Produto\n");
        printf("{2} Vender Produto\n");
        printf("{3} Mostrar Produtos\n");
        printf("{4} Verificar Estoque\n");
        printf("{5} Sair\n");
        printf("Sua Escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                inserirProduto(&primeiro, &ultimo, &quantidade);
                break;
            case 2: {
                if(quantidade == 0) {
                    printf("\nA Lista está vázia...\n");
                    break;
                }

                mostrar(&primeiro);

                int id = 0;
                printf("Qual produto irá vender [id]: ");
                scanf("%d", &id);

                LISTA* temp = buscarProduto(&primeiro, id);
                venderProduto(&temp, &primeiro, &ultimo, &quantidade);
                break;
            }
            case 3: 
                mostrar(&primeiro);
                break;
            case 4:
                verificarEstoque(&primeiro);
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