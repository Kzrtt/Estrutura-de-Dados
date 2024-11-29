#include "bibliotecas.h"

#ifndef FILA_H
#define FILA_H

typedef struct fila FILA;

struct fila {
    char tipo;
    int num;
    FILA* proxNo;
};

void enfileirar(FILA** primeiro, FILA** ultimo, int* quantidade) {
    int senhaTipo = 0;
    char charNovoNo;

    printf("\nQual é seu tipo de senha: \n");
    printf("{1} Senha Comum\n");
    printf("{2} Senha Preferencial\n");
    printf("{3} Senha VIP\n");
    printf("Sua Escolha: ");
    scanf("%d", &senhaTipo);

    switch (senhaTipo)
    {
        case 1:
            charNovoNo = 'C';
            break;
        case 2:
            charNovoNo = 'P';
            break;
        case 3:
            charNovoNo = 'V';
            break;
        default:
            printf("Opção Inválida...\n");
            return;
    }
    
    FILA* novoNo = (FILA*) malloc(sizeof(FILA));

    if(novoNo == NULL) {
        printf("Erro ao alocar a memória\n");
        return;
    }

    FILA* temp = *primeiro;
    int numPessoa = 0;
    while (temp != NULL)
    {
        if(temp->tipo == charNovoNo) {
            numPessoa += 1;
        }
        temp = temp->proxNo;
    }

    novoNo->tipo = charNovoNo;
    novoNo->num = numPessoa + 1;
    novoNo->proxNo = NULL;

    if(*primeiro == NULL) {
        *primeiro = *ultimo = novoNo;
    } else {
        (*ultimo)->proxNo = novoNo;
        *ultimo = novoNo;
    }

    *quantidade += 1;
    printf("Senha Gerada com Sucesso! {%c%d}\n", novoNo->tipo, novoNo->num);

    free(temp);
} 

void desenfileirar(FILA** primeiro, FILA** ultimo, int* quantidade) {
    srand(time(NULL));

    if(*primeiro == NULL) {
        printf("A Fila está vázia...\n");
        return;
    }

    int valorRemover = (rand() % *quantidade) + 1;

    FILA* temp = *primeiro;
    for (int i = 0; i < *quantidade; i++)
    {
        if(i == *quantidade + 1) {
            FILA* aux = temp;
            temp = temp->proxNo;
        }
    }
}

void mostrar(FILA** primeiro) {
    if(*primeiro == NULL) {
        printf("A Fila está vazia...\n");
        return;
    }

    FILA* temp = *primeiro;
    printf("\nFila: ");
    while (temp != NULL)
    {
        printf("[%c%d] ", temp->tipo, temp->num);
        temp = temp->proxNo;
    }
    printf("\n");
}

#endif