#include "bibliotecas.h"

#ifndef LISTAD_H
#define LISTAD_H

typedef struct listad LISTAD;

struct listad {
    int num;
    LISTAD* proxNo;
    LISTAD* antNo;
};

/**
 ** Inserir
 *  Inserção no Começo:
 *  1- NovoNo.proxNo aponta para o Primeiro
 *  2- Primeiro.antNo aponta para NovoNo
 *  3- Primeiro aponta para NovoNo
 * 
 *  Inserção no Fim:
 *  1- NovoNo.antNo aponta para o Ultimo
 *  2- Ultimo.proxNo aponta para NovoNo
 *  3- Ultimo aponta para o NovoNo
 * 
 *  Inserção no Meio:
 *! Em que a Lista seria [Aux] -> [Aux.proxNo] e o [NovoNo] será inserido entre ambos.
 *? Para remover indo pelo lado oposto (Direita para Esquerda) é só passar uma posição a mais quando for escolher o Aux.
 *  1- Encontrar qual a direção que deve caminhar
 *  2- NovoNo.proxNo aponta para Aux.proxNo
 *  3- NovoNo.antNo aponta para Aux
 *  4- Aux.proxNo.antNo = NovoNo
 *  5- Aux.proxNo = NovoNo
 * 
 * -------------------------------------------------------------------------------------------
 ** Remoção
 *  Remoção no Começo:
 *  1- Primeiro.proxNo.antNo = NULL
 *  2- Primeiro.proxNo.proxNo = Primeiro.proxNo
 * 
 *  Remoção no Fim:
 *  1- Ultimo.antNo.proxNo = NULL
 *  2- Ultimo.antNo.antNo = Ultimo.antNo
 * 
 *  Remoção no meio:
 *! O que será removido é o Aux
 *  1- Aux.proxNo.antNo = Aux.antNo
 *  2- Aux.antNo.proxNo = Aux.proxNo
 */

#endif