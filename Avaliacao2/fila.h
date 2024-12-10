#include "bibliotecas.h"

#ifndef FILA_H
#define FILA_H

typedef struct fila FILA;

typedef enum {
    CRITICO = 0,
    ALTO = 1,
    MEDIO = 2,
    BAIXO = 3
} Importancia;

struct fila {
    char nome[51];
    int carga;
    int distancia;
    struct tm data;
    Importancia importancia;
    FILA* proxNo;
};

const char* importanciaToString(Importancia imp) {
    switch (imp) {
        case CRITICO: return "CRÍTICO";
        case ALTO: return "ALTO";
        case MEDIO: return "MÉDIO";
        case BAIXO: return "BAIXO";
        default: return "DESCONHECIDO";
    }
}

void imprimirImportancia(Importancia importancia) {
    printf("   Importância: ");
    switch (importancia) {
        case CRITICO:
            printf("Crítica\n");
            break;
        case ALTO:
            printf("Alta\n");
            break;
        case MEDIO:
            printf("Média\n");
            break;
        case BAIXO:
            printf("Baixa\n");
            break;
        default:
            printf("Não Encontrada\n");
            break;
    }
}

void lbt() {
    char c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

void inserir(FILA** primeiro, FILA** ultimo) {
    //? Alocando a memória
    FILA* novoNo = (FILA*) malloc(sizeof(FILA));

    if(novoNo == NULL) {
        printf("\nErro ao alocar na memória\n");
        return;
    }

    //? Cadastros Comuns
    lbt();
    printf("\nQual o nome da missão (máx: 50): ");
    scanf("%[^\n]", &novoNo->nome);

    printf("Qual a carga da missão (toneladas): ");
    scanf("%d", &novoNo->carga);

    printf("Qual a distância (milhões de km): ");
    scanf("%d", &novoNo->distancia);
    novoNo->proxNo = NULL;

    //? Cadastro da Data
    int dia, mes, ano;
    struct tm data = {0};
    printf("Digite a data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data.tm_mday, &data.tm_mon, &data.tm_year);
    data.tm_mon -= 1;
    data.tm_year -= 1900;
    novoNo->data = data;

    int importancia = 4;
    printf("\nImportância: (1 => Crítico, 2 => Alta, 3 => Médio, 4 => Baixo)\n");
    printf("Digite a importância: ");
    scanf("%d", &importancia);
    
    switch (importancia)
    {
        case 1:
            novoNo->importancia = CRITICO;
            break;
        case 2: 
            novoNo->importancia = ALTO;
            break;
        case 3:
            novoNo->importancia = MEDIO;
            break;
        default:
            novoNo->importancia = BAIXO;
            break;
    }

    if(*primeiro == NULL) {
        *primeiro = novoNo;
        *ultimo = novoNo;
    } else {
        (*ultimo)->proxNo = novoNo;
        *ultimo = novoNo;
    }

    printf("\nValor adicionado com sucesso!\n");

    novoNo = NULL;
    free(novoNo);
}

void mostrar(FILA** primeiro) {
    if(*primeiro == NULL) {
        printf("\nA Fila está vázia...\n");
        return;
    }

    FILA* temp = *primeiro;
    int count = 1;
    while (temp != NULL)
    {
        printf("\nRegistro #%d: \n", count);
        printf("   Nome: %s \n", temp->nome);
        printf("   Carga: %d Toneladas \n", temp->carga);
        printf("   Distância: %d \n", temp->distancia);

        char buffer[50];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y", &temp->data);
        printf("   Data: %s \n", buffer);

        imprimirImportancia(temp->importancia);

        temp = temp->proxNo;
        count++;
    }
    printf("\n");
}

void reorganizar(FILA** primeiro, FILA** ultimo) {
    if(*primeiro == NULL) {
        printf("A Fila está vázia...\n");
        return;
    }

    FILA* i = *primeiro;
    FILA* j;
    
    printf("\n");
    while (i != NULL)
    {
        j = i->proxNo;

        while (j != NULL)
        {
            if(
                i->importancia > j->importancia || 
                (i->importancia == j->importancia && difftime(mktime(&i->data), mktime(&j->data)) > 0)
            ) {
                FILA aux = *i;
                char data_i[20], data_j[20];

                // Formata as datas para strings legíveis (Ex: "DD/MM/YYYY")
                strftime(data_i, sizeof(data_i), "%d/%m/%Y", &i->data);
                strftime(data_j, sizeof(data_j), "%d/%m/%Y", &j->data);

                // Imprime os detalhes no printf
                printf("Trocando %s (Importância: %s, Data: %s) e %s (Importância: %s, Data: %s)\n",
                    i->nome, importanciaToString(i->importancia), data_i,
                    j->nome, importanciaToString(j->importancia), data_j
                );

                strcpy(i->nome, j->nome);
                i->carga = j->carga;
                i->distancia = j->distancia;
                i->data = j->data;
                i->importancia = j->importancia;

                strcpy(j->nome, aux.nome);
                j->carga = aux.carga;
                j->distancia = aux.distancia;
                j->data = aux.data;
                j->importancia = aux.importancia;
            }

            j = j->proxNo;
        }
        
        i = i->proxNo;
    }

    printf("\nA Fila foi ordenada...\n");

    i = NULL;
    j = NULL;
    free(i);
    free(j);
}

FILA* buscarMissao(FILA** primeiro, int indice) {
    //? Se a lista está vázia retorna NULL
    if(*primeiro == NULL || indice < 0) {
        return NULL;
    }

    FILA* temp = *primeiro;
    for (int i = 0; i <= indice; i++) {
        if(indice == i + 1) {
            return temp;
        }

        temp = temp->proxNo;
    }

    return NULL;
}

void enviarMissao(FILA** primeiro, FILA** ultimo) {
    if(*primeiro == NULL) {
        printf("A Fila de missões está vázia...\n");
        return;
    }

    if(*ultimo == *primeiro) {
        *ultimo = NULL;
        *primeiro = NULL;

        printf("\nMissão Enviada...\n");
        return;
    }

    FILA* aux = *primeiro;
    *primeiro = aux->proxNo;
    free(aux);

    printf("\nMissão Enviada...\n");
}

void adiantarMissao(FILA** primeiro, FILA** ultimo, int auxPos) {
    //? Buscando valor na lista
    FILA* temp = buscarMissao(primeiro, auxPos);
    if(temp == NULL) {
        printf("\nMissão Não Encontrada...\n");
        return;
    }

    FILA aux = **primeiro;

    strcpy((*primeiro)->nome, temp->nome);
    (*primeiro)->carga = temp->carga;
    (*primeiro)->distancia = temp->distancia;
    (*primeiro)->data = temp->data;
    (*primeiro)->importancia = temp->importancia;

    strcpy(temp->nome, aux.nome);
    temp->carga = aux.carga;
    temp->distancia = aux.distancia;
    temp->data = aux.data;
    temp->importancia = aux.importancia;

    printf("\nMissão Adiantada!\n");
}

#endif