#include <stdlib.h>
#include <stdio.h>

typedef struct PESSOA
{
    int idade;
};

void imprimeMatriz(struct PESSOA matriz[2][2]) {
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");   
    }
    printf("\n");
}

void main() {
    struct PESSOA matriz[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int idade;
            printf("Insira a idade: ");
            scanf("%d", &matriz[i][j].idade);
        }
        
    }
    
    printf("\n");
    imprimeMatriz(matriz);
}