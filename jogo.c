#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_TENTATIVAS 5

int main() {
    char letras_corretas[] = "PROGRAMACAO";
    char letras_adivinhadas[sizeof(letras_corretas)] = {0};
    int tentativas_restantes = MAX_TENTATIVAS;
    int letras_acertadas = 0;
    int i;

    srand(time(NULL));

    printf("Bem-vindo ao Jogo de Adivinhacao de Letras!\n");
    printf("Voce tem %d tentativas para adivinhar a palavra.\n", MAX_TENTATIVAS);
    printf("A palavra tem %d letras. Boa sorte!\n", sizeof(letras_corretas) - 1);

    while (tentativas_restantes > 0 && letras_acertadas < sizeof(letras_corretas) - 1) {
        printf("\nDigite uma letra: ");
        char letra;
        scanf(" %c", &letra);
        letra = toupper(letra);

        int ja_adivinhada = 0;
        for (i = 0; i < sizeof(letras_corretas) - 1; i++) {
            if (letras_adivinhadas[i] == letra) {
                printf("Você ja tentou essa letra!\n");
                ja_adivinhada = 1;
                break;
            }
        }
        if (ja_adivinhada) {
            continue;
        }

        int acertou = 0;
        for (i = 0; i < sizeof(letras_corretas) - 1; i++) {
            if (letras_corretas[i] == letra) {
                letras_adivinhadas[i] = letra;
                letras_acertadas++;
                acertou = 1;
            }
        }

        if (acertou) {
            printf("Parabens! '%c' esta na palavra.\n", letra);
        } else {
            tentativas_restantes--;
            printf("Infelizmente '%c' nao esta na palavra.\n", letra);
            printf("Voce tem %d tentativas restantes.\n", tentativas_restantes);
        }

        printf("Palavra atual: ");
        for (i = 0; i < sizeof(letras_corretas) - 1; i++) {
            if (letras_adivinhadas[i]) {
                printf("%c ", letras_adivinhadas[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }

    if (letras_acertadas == sizeof(letras_corretas) - 1) {
        printf("\nParabens! Voce adivinhou a palavra!\n");
    } else {
        printf("\nQue pena! Voce nao adivinhou a palavra. A palavra era '%s'\n", letras_corretas);
    }

    return 0;
}
