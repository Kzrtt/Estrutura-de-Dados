#include "bibliotecas.h"
#include "pilha.h"

void main() {
    PILHA* topo = NULL;
    char palavra[100];
    int isPalindrome = 1, count = 0;

    printf("Insira a palavra: ");
    scanf("%[^\n]", &palavra);

    for (int i = 0; i < strlen(palavra); i++)
    {
        if(isalpha(palavra[i])) {
            empilhar(&topo, tolower(palavra[i]));
        }
    }
    
    printf("A palavra invertida é: ");
    while (topo != NULL)
    {
        if(isspace(palavra[count])) {
            count++;
        }

        if(palavra[count] != topo->valor) {
            isPalindrome = 0;
        }

        printf("%c", topo->valor);
        desempilhar(&topo);
        count++;
    }
    
    if(isPalindrome) {
        printf("\n\n A palavra é um Palindromo!!");
    } else {
        printf("\n\n A palavra não é um Palindromo!!");
    }
}