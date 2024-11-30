#include "bibliotecas.h"

#ifndef LISTA_H
#define LISTA_H

typedef struct lista LISTA;

struct lista {
    int num;
    LISTA* proxNo;
};

void mostrar(LISTA** primeiro) {
    if(*primeiro == NULL) {
        printf("A Lista está vázia...\n");
        return;
    }

    LISTA* temp = *primeiro;
    printf("\nLista: ");
    while (temp != NULL)
    {   
        printf("[%d] ", temp->num);
        temp = temp->proxNo;
    }
    printf("\n");
}

LISTA* buscar(LISTA** primeiro, int pos) {
    if(*primeiro == NULL) {
        return NULL;
    }

    LISTA* temp = *primeiro;
    for (int i = 0; i <= pos; i++) {
        if(pos == i + 1) {
            return temp;
        }

        temp = temp->proxNo;
    }

    return NULL;
}

//? Tipos de Inserção
//? Começo / Meio / Fim
void inserir(LISTA** primeiro, LISTA** ultimo, int* quantidade) {
    int escolha = 0;
    int auxPos = 0;

    printf("\nModo de Inserção: \n");
    printf("{1} Inicio\n");
    printf("{2} Meio\n");
    printf("{3} Fim\n");
    printf("Sua Escolha: \n");
    scanf("%d", &escolha);

    //? Caso a escolha seja 1 e a Lista estaja vazia inserir na primeira posição
    if((escolha != 1) && *primeiro == NULL) {
        escolha = 1;
    }

    //? Pegando a posicao do anterior ao que vai ser inserido
    switch (escolha)
    {
        case 1:
            printf("\nInserindo no começo...");
            auxPos = 0;
            break;
        case 2:
            printf("\nInserindo no meio...");
            auxPos = *quantidade % 2 == 0 ? (*quantidade / 2) : (*quantidade / 2) + 1;
            break;
        default:
            printf("\nInserindo no fim...");
            break;
    }

    //? Alocando a memória
    LISTA* novoNo = (LISTA*) malloc(sizeof(LISTA));
    novoNo->proxNo = NULL;
    if(novoNo == NULL) {
        printf("Erro ao alocar a memória...\n");
        return;
    }

    printf("\nQual o valor: \n");
    scanf("%d", &novoNo->num);

    if(escolha > 2 || (escolha == 2 && *quantidade < 2)) {
        (*ultimo)->proxNo = novoNo;
        *ultimo = novoNo;
        *quantidade += 1;
        printf("Valor Inserido...\n");

        return;
    }

    //? Buscando o valor anterior
    LISTA* temp = buscar(primeiro, auxPos);
    if(temp == NULL) {
        //? Caso o anterior seja NULL a lista está vázia
        novoNo->proxNo = *primeiro;
        *primeiro = novoNo;

        if(*ultimo == NULL) {
            *ultimo = novoNo;
        }

        *quantidade += 1;
        return;
    }

    //? Se não for NULL processo normal de inserção
    novoNo->proxNo = temp->proxNo;
    temp->proxNo = novoNo;

    if(escolha == 1) {
        printf("teste");
        *primeiro = novoNo;
    }

    novoNo = NULL;
    free(novoNo);
    temp = NULL;
    free(temp);
    
    *quantidade += 1;
    printf("\nValor Inserido...\n");
}

void remover(LISTA** primeiro, LISTA** ultimo, int* quantidade) {
    int remPos = 0;

    printf("\nTamanho Lista: %d", *quantidade);
    mostrar(primeiro);

    printf("\nQual posição deseja remover: ");
    scanf("%d", &remPos);

    if(remPos > *quantidade || remPos < 1) {
        printf("Valor Inválido...\n");
        return;
    }

    LISTA* auxRem = NULL;

    if(remPos == 1) {
        auxRem = *primeiro;
        *primeiro = (*primeiro)->proxNo;
        if(*primeiro == NULL) {
            *ultimo = NULL;
        }
    } else {
        LISTA* temp = buscar(primeiro, remPos - 1);
        auxRem = temp->proxNo;
        temp->proxNo = auxRem->proxNo;

        if(auxRem == *ultimo) {
            *ultimo = temp;
        }
    }

    auxRem = NULL;
    free(auxRem);

    *quantidade -= 1;

    printf("Valor Removido...\n");
}

#endif