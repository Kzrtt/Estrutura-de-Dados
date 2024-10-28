#include "bibliotecas.h"
#include "vetor.h"

//cd "c:\Users\elain\OneDrive\Área de Trabalho\UTFPR\4° Semestre\Estrutura de Dados\TAD Vetor\" ; if ($?) { gcc main.c buscar.c inserir.c mostrar.c remover.c ordemC.c ordemD.c -o main } ; if ($?) { .\main }

void main() {
    int escolha = 0, valor = 0, indice = 0, tamanho = 1;

    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tamanho);

    VETOR vetor;
    vetor.tamanho = tamanho;
    vetor.dados = (int*) malloc(tamanho * sizeof(int));
    vetor.quantidade = 0; 

    while(1) {
        printf("\n -- Menu -- \n");
        printf("{1} Buscar\n");
        printf("{2} Inserir\n");
        printf("{3} Mostrar\n");
        printf("{4} Remover\n");
        printf("{5} Ordem Crescente\n");
        printf("{6} Ordem Decrescente\n");
        printf("{0} Sair\n");
        printf("Sua Escolha: ");
        scanf("%d", &escolha);
        printf("\n");

        if(escolha == 0) {
            printf("Saindo...\n");
            break;
        }

        switch (escolha)
        {
        case 1: {
            printf("Insira o valor: ");
            scanf("%d", &valor);
            indice = buscar(&vetor, valor);
            if(indice == -1) {
                printf("Valor não encontrado...\n");
                break;
            }

            printf("O indice do valor e: %d\n", indice);
            break;
        }
        case 2: {
            printf("Insira o valor: ");
            scanf("%d", &valor);
            inserir(&vetor, valor);
            break;
        }
        case 3: {
            mostrar(&vetor);
            break;
        }
        case 4: {
            printf("Insira o valor: ");
            scanf("%d", &valor);
            remover(&vetor, valor);
            break;
        }
        case 5: {
            ordemC(&vetor);
            break;
        }
        case 6: {
            ordemD(&vetor);
            break;
        }
        default:
            printf("Opção Inválida...\n");
            break;
        }
    }

    free(vetor.dados);
}