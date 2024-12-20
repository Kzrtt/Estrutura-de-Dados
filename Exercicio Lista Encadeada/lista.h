#include "bibliotecas.h"

#ifndef LISTA_H
#define LISTA_H

typedef struct lista LISTA;

struct lista {
    int id;
    char descricao[100];
    int validador;
    LISTA* proxNo;
};

void lbt() {
    char c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

void inserirFragmento(LISTA** primeiro, LISTA** ultimo) {
    //? Alocando a memória
    LISTA* novoNo = (LISTA*) malloc(sizeof(LISTA));
    novoNo->proxNo = NULL;
    if(novoNo == NULL) {
        printf("Erro ao alocar a memória...\n");
        return;
    }

    printf("\nInsira o id do fragmento: ");
    scanf("%d", &novoNo->id);

    lbt();
    printf("Insira a descrição: ");
    scanf("%[^\n]", &novoNo->descricao);

    printf("Insira o validador temporal: ");
    scanf("%d", &novoNo->validador);

    //? Se a lista for vázia
    if(*primeiro == NULL) {
        novoNo->proxNo = NULL;
        *primeiro = novoNo;
        *ultimo = novoNo;

        printf("\nValor Inserido!!\n");
        return;
    }

    //? Se for no primeiro
    if(novoNo->validador < (*primeiro)->validador) {
        novoNo->proxNo = *primeiro;
        *primeiro = novoNo;

        printf("\nValor Inserido!!\n");
        return;
    }

    LISTA* temp = *primeiro;
    while (temp->proxNo != NULL && temp->proxNo->validador < novoNo->validador)
    {
        temp = temp->proxNo;
    }

    novoNo->proxNo = temp->proxNo;
    temp->proxNo = novoNo;

    printf("\nValor Inserido!!\n");
}

void mostrar(LISTA** primeiro) {
    if(*primeiro == NULL) {
        printf("\nA Lista está vázia\n");
        return;
    }

    LISTA* temp = *primeiro;
    printf("\nLista: \n");
    while (temp != NULL) {
        printf("\nId: %d\n", temp->id);
        printf("Descricao %s\n", temp->descricao);
        printf("Validador: %d\n", temp->validador);
        printf("\n--\n");

        temp = temp->proxNo;
    }
}

#endif