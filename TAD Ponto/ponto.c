#include "bibliotecas.h"
#define TAM_LISTA 5

void validarIndice(int indice) {
    if (indice < 0 || indice >= TAM_LISTA) {
        printf("Índice inválido...\n");
        return;
    }
}

void imprimirPontos(PONTO** pontos) {
    printf("[");
    int primeiro = 1; 
    for (int i = 0; i < TAM_LISTA; i++) {   
        if (pontos[i] != NULL) {
            // Se não é o primeiro ponto, imprime uma vírgula antes.
            if (!primeiro) {
                printf(", ");
            }
            printf("{%d} => (%d, %d)", i, pontos[i]->x, pontos[i]->y);
            primeiro = 0; 
        }
    }

    printf("]\n");
}

PONTO* criarPonto() {
    PONTO* ponto = (PONTO*) malloc(sizeof(PONTO));
    if(ponto == NULL) {
        printf("Erro ao alocar a memória...\n");
        return NULL;
    }

    printf("Insira o valor x: ");
    scanf("%d", &ponto->x);
    printf("Insira o valor de y: ");
    scanf("%d", &ponto->y);

    return ponto;
}

void exibirPonto(PONTO** pontos, int indice) {
    validarIndice(indice);

    if (pontos[indice] != NULL) {
        printf("pontos[%d]: (x: %d, y: %d)\n", indice, pontos[indice]->x, pontos[indice]->y);
    } else {
        printf("pontos[%d] está vazio.\n", indice);
    }
}

void editarPonto(PONTO** pontos, int indice) {
    validarIndice(indice);

    printf("Digite o novo x: ");
    scanf("%d", &pontos[indice]->x);
    printf("Digite o novo y: ");
    scanf("%d", &pontos[indice]->y);

    printf("pontos[%d] alterado com sucesso!\n", indice);
}

void liberarPonto(PONTO** pontos, int indice) {
    validarIndice(indice);

    free(pontos[indice]);
    pontos[indice] = NULL;
    printf("Ponto apagado.\n");
}

void calcularDistancia(PONTO** pontos, int indiceUm, int indiceDois) {
    validarIndice(indiceUm);
    validarIndice(indiceDois);

    float somaX = (pontos[indiceUm]->x - pontos[indiceDois]->x);
    float somaY = (pontos[indiceUm]->y - pontos[indiceDois]->y);
    float somaPontos = pow(somaX, 2) + pow(somaY, 2);
    printf("A distância entre os dois pontos é: %.2f\n", sqrt(somaPontos));
}

void ponto() {
    PONTO* pontos[TAM_LISTA] = { NULL }; 
    int quantidade = 0;
    int escolha = 0;

    while(1) {
        printf("\n == Menu == \n");
        printf("[1] Criar Ponto\n");
        printf("[2] Exibir Ponto\n");
        printf("[3] Editar Ponto\n");
        printf("[4] Liberar Ponto\n");
        printf("[5] Calcular Distância\n");
        printf("[6] Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        printf("\n");

        if(escolha == 6) {
            printf("Saindo...\n");
            break;
        }

        switch (escolha)
        {
        case 1:
            if(quantidade < TAM_LISTA) {
                pontos[quantidade] = criarPonto(quantidade);
                if(pontos[quantidade] != NULL) {
                    quantidade++;
                    printf("Ponto criado com sucesso!\n");
                }
            } else {
                printf("Tamanho máx de pessoas atingido!\n");
            }
            break;
        case 2: {
            int indice = 0;
            imprimirPontos(pontos);
            printf("Qual o índice do ponto: ");
            scanf("%d", &indice);
            exibirPonto(pontos, indice);
            break;
        }
        case 3: {
            int indice = 0;
            imprimirPontos(pontos);
            printf("Qual o índice do ponto: ");
            scanf("%d", &indice);
            editarPonto(pontos, indice);
            break;
        }
        case 4: {
            int indice = 0;
            imprimirPontos(pontos);
            printf("Qual o índice do ponto: ");
            scanf("%d", &indice);
            liberarPonto(pontos, indice);
        }
        case 5: {
            int indiceUm = 0;
            int indiceDois = 0;
            imprimirPontos(pontos);
            printf("Qual o índice do primeiro ponto: ");
            scanf("%d", &indiceUm);
            printf("Qual o índice do segundo ponto: ");
            scanf("%d", &indiceDois);
            calcularDistancia(pontos, indiceUm, indiceDois);
            break;
        }
        default:
            printf("Opção Inválida...\n");
            break;
        }
    }

    // Libera a memória dos pontos ao sair do programa.
    for (int i = 0; i < TAM_LISTA; i++) {
        if (pontos[i] != NULL) {
            free(pontos[i]);
        }
    }
}