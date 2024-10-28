#include <stdio.h>
#include <stdlib.h>

/*
void main() {
    int *p = NULL, *p2 = NULL, *k = NULL; 
    int x;
    p = (int*) malloc(sizeof(int));

    printf("Insira o tamanho de K: ");
    scanf("%d", &x);

    k = (int*) malloc(x * sizeof(int));

    for (int i = 0; i < x; i++)
    {
        printf("Insira o %d° valor de K: ", i + 1);
        scanf("%d", &k[i]);
    }
    
    printf("\n");

    for (int i = 0; i < x; i++)
    {
        printf("[%d]", k[i]);
    }

    printf("\n");

    int a[5];
    printf("Tamanho: %d", sizeof(a));
}
*/

typedef struct {
    int chave;
    char nome[51];
} DADOS;

void lbt() {
    char c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

void main() {
    DADOS *D = NULL;
    D = (DADOS*) malloc(sizeof(DADOS));

    printf("Insira a chave: ");
    scanf("%d", &D->chave);
    lbt();
    printf("Insira o nome: ");
    scanf("%[^\n]", &D->nome);

    printf("\n");

    printf("{%d} %s", D->chave, D->nome);
}