#include "bibliotecas.h"

#ifndef LISTA_H
#define LISTA_H

typedef struct lista LISTA;

struct lista {
    int id;
    char nome[101];
    int quantidade;
    double valor;
    LISTA* proxNo;
    LISTA* antNo;
};

void lbt() {
    char c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

LISTA* insercaoOrdenada(LISTA** primeiro, LISTA** ultimo, int qntdNovo) {
    if(*primeiro == NULL) {
        printf("\nA Lista está vázia...\n");
        return NULL;
    }
    
    //? Se o novo valor é menor ou igual ao primeiro, retorna o primeiro
    if(qntdNovo <= (*primeiro)->quantidade) {
        return *primeiro;
    }

    //? Se o novo valor é maior que o último, retorna NULL (inserir no fim)
    if(qntdNovo > (*ultimo)->quantidade) {
        return NULL;
    }

    LISTA* temp;
    int diferencaPrimeiro = (*primeiro)->quantidade - qntdNovo;
    int diferencaUltimo = (*ultimo)->quantidade - qntdNovo;

    if(diferencaPrimeiro >= diferencaUltimo) {
        //? Mais perto pelo começo
        temp = *primeiro;

        while (temp != NULL)
        {
            if(qntdNovo <= temp->quantidade) {
                return temp;
            }

            temp = temp->proxNo;
        }

        return *ultimo;
    } else {
        //? Mais perto do fim
        temp = *ultimo;

        while (temp != NULL)
        {
            if(qntdNovo >= temp->quantidade) {
                return temp;
            }

            temp = temp->antNo;
        }
        
    }

    return NULL;
} 

LISTA* buscarProduto(LISTA** primeiro, int id) {
    if(*primeiro == NULL) {
        printf("\nA Lista está vázia...\n");
        return NULL;
    }  

    LISTA* temp = *primeiro;
    while (temp != NULL)
    {
        if(temp->id == id) {
            return temp;
        }

        temp = temp->proxNo;
    }
    
}

void inserirProduto(LISTA** primeiro, LISTA** ultimo, int* quantidade) {
    LISTA* novoNo;
    if((novoNo = (LISTA*) malloc(sizeof(LISTA))) == NULL) {
        printf("Erro ao alocar a memória!\n");
        return;
    }

    printf("\nInforme o id: ");
    scanf("%d",  &(*novoNo).id);
    lbt();
    printf("Informe o nome do produto [100]: ");
    scanf("%[^\n]", &(*novoNo).nome);
    printf("Informe a quantidade: ");
    scanf("%d", &(*novoNo).quantidade);
    printf("Qual o valor do produto: ");
    scanf("%lf", &(*novoNo).valor);

    (*novoNo).proxNo = NULL;
    (*novoNo).antNo = NULL;

    //? Inserção caso a lista esteja vazia
    if(*primeiro == NULL) {
        printf("\nInserindo o primeiro produto na lista!\n");
        *primeiro = *ultimo = novoNo;
        *quantidade += 1;
        return;
    }

    LISTA* temp = insercaoOrdenada(primeiro, ultimo, (*novoNo).quantidade);

    //? Caso o valor esteja sendo inserido no começo
    if(temp == *primeiro && temp->quantidade >= (*novoNo).quantidade) {
        (*novoNo).proxNo = *primeiro;
        (*primeiro)->antNo = novoNo;
        *primeiro = novoNo;
        *quantidade += 1;

        return;
    }

    //? Caso o valor esteja sendo inserido no fim
    if(temp == NULL) {
        (*novoNo).antNo = *ultimo;
        (*ultimo)->proxNo = novoNo;
        *ultimo = novoNo;
        *quantidade += 1;

        return;
    }

    (*novoNo).proxNo = temp->proxNo;
    (*novoNo).antNo = temp;
    temp->proxNo->antNo = novoNo;
    temp->proxNo = novoNo;
    *quantidade += 1;
} 

void mostrar(LISTA** primeiro) {
    if(*primeiro == NULL) {
        printf("\nA Lista está vázia...\n");
        return;
    }

    LISTA* temp = *primeiro;
    printf("\nProdutos: \n");
    while(temp != NULL) {
        printf("\nId: %d\n", temp->id);
        printf("Nome: %s\n", temp->nome);
        printf("Valor: R$%.2f\n", temp->valor);
        printf("Quantidade %d\n", temp->quantidade);
        printf("--------------------------");
        temp = temp->proxNo;
    }
    printf("\n");
}

void venderProduto(LISTA** remove, LISTA** primeiro, LISTA** ultimo, int* total) {
    int quantidade;

    if(remove == NULL) {
        printf("\nProduto não encontrado!\n");
        return;
    }

    printf("[%s][R$%.2f] Unidades: ", (*remove)->nome, (*remove)->valor);
    scanf("%d", &quantidade);

    if((*remove)->quantidade < quantidade) {
        printf("\nVendendo todas as %d unidades de %s por um total de R$%.2lf\n", (*remove)->quantidade, (*remove)->nome, (*remove)->quantidade * (*remove)->valor);
        (*remove)->quantidade = 0;
    } else {
        printf("\nVendendo %d unidades de %s por um total de R$%.2lf\n", quantidade, (*remove)->nome, quantidade * (*remove)->valor);
        (*remove)->quantidade -= quantidade;
    }

    if((*remove)->quantidade <= 5) {
        printf("\n------Alerta------\n");
        printf("Estoque de [%s] baixo", (*remove)->nome);
        printf("\n------Alerta------\n");
    }

    if((*remove)->quantidade == 0) {
        printf("\nRemovendo o item %s\n", (*remove)->nome);

        if(*remove == *primeiro) {
            (*primeiro)->proxNo->antNo = NULL;
            *primeiro = (*primeiro)->proxNo;

            *total -= 1;
            free(remove);
            return;
        }

        if(*remove == *ultimo) {
            (*ultimo)->antNo->proxNo = NULL;
            *ultimo = (*ultimo)->antNo;

            *total -= 1;
            free(remove);
            return;
        }

        (*remove)->proxNo->antNo = (*remove)->antNo;
        (*remove)->antNo->proxNo = (*remove)->proxNo;

        *total -= 1;
        free(remove);
    }

    printf("\n");
}

void verificarEstoque(LISTA** primeiro) {
    if(*primeiro == NULL) {
        printf("\nA Lista está vázia...\n");
        return;
    }

    LISTA* temp = *primeiro;
    while (temp != NULL)
    {
        if(temp->quantidade <= 5) {
            printf("\n------Alerta------\n");
            printf("Estoque de [%s] baixo", temp->nome);
            printf("\n------Alerta------\n");
        }

        temp = temp->proxNo;
    }
    
    printf("\n");
}

#endif