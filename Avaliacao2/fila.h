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

void inserir(FILA** primeiro, FILA** ultimo, int* quantidade) {
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

    printf("\nQual a carga da missão (toneladas): ");
    scanf("%d", &novoNo->carga);

    printf("\nQual a distância (milhões de km): ");
    scanf("%d", &novoNo->distancia);
    novoNo->proxNo = NULL;

    //? Cadastro da Data
    int dia, mes, ano;
    struct tm data = {0};
    printf("\nDigite a data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data.tm_mday, &data.tm_mon, &data.tm_year);
    data.tm_mon -= 1;
    data.tm_year -= 1900;
    novoNo->data = data;

    //? Cadastro da Importancia
    //* Pega data atual
    time_t agora = time(NULL);
    struct tm *dataAtual = localtime(&agora);

    //* Calcula a diferença de tempo
    time_t dataMissao = mktime(&data);
    time_t dataAtualTime = mktime(dataAtual);

    if (dataMissao == -1 || dataAtualTime == -1) {
        printf("\nErro ao calcular as datas.\n");
        return;
    }

    //* Diferença em segundos convertida para dias
    double diferencaDias = difftime(dataMissao, dataAtualTime) / (60 * 60 * 24);

    if (diferencaDias <= 7) {
        novoNo->importancia = CRITICO;
    } else if (diferencaDias <= 14) {
        novoNo->importancia = ALTO;
    } else if (diferencaDias <= 21) {
        novoNo->importancia = MEDIO;
    } else {
        novoNo->importancia = BAIXO;
    }

    //? Lógica da Fila
    if(*primeiro == NULL) {
        *primeiro = novoNo;
        *ultimo = novoNo;
        *quantidade += 1;
        return;
    } else {
        //* O temp é a primeira prioridade menor, logo o anterior ainda é mais prioritário que o que vamos inserir
        FILA* temp = *primeiro;
        FILA* anterior = NULL;
        while ((temp != NULL) && temp->importancia <= novoNo->importancia)
        {
            anterior = temp;
            temp = temp->proxNo;
        }
        
        if (anterior == NULL) {
            //* Insere no início, pois está vázio a fila
            novoNo->proxNo = *primeiro;
            *primeiro = novoNo;
        } else {
            //* Insere no meio ou no final
            novoNo->proxNo = temp;
            anterior->proxNo = novoNo;

            //? // Atualiza o último nó, se necessário
            if (temp == NULL) {
                *ultimo = anterior->proxNo;
            }
        }

        *quantidade += 1;
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

void enviarMissao(FILA** primeiro, FILA** ultimo, int* quantidade) {
    if(*primeiro == NULL) {
        printf("A Fila de missões está vázia...\n");
        return;
    }

    if(*ultimo == *primeiro) {
        *ultimo = NULL;
        *primeiro = NULL;
        *quantidade -= 1;

        printf("\nMissão Enviada...\n");
        return;
    }

    FILA* aux = *primeiro;
    *primeiro = aux->proxNo;
    *quantidade -= 1;
    free(aux);

    printf("\nMissão Enviada...\n");
}

void adiantarMissao(FILA** primeiro, FILA** ultimo, int auxPos, int* quantidade) {
    //? Buscando valor na lista
    FILA* temp = buscarMissao(primeiro, auxPos);
    if(temp == NULL) {
        printf("\nMissão Não Encontrada...\n");
        return;
    }

    FILA* auxRem = temp->proxNo;
    temp->proxNo = auxRem->proxNo;
    *quantidade -= 1;
    
    auxRem = NULL;
    free(auxRem);
    temp = NULL;
    free(temp);

    printf("\nMissão Adiantada!\n");
}

#endif