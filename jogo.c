#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_TENTATIVAS 5 // Define o número máximo de tentativas

int main() {
    char letras_corretas[] = "PROGRAMACAO"; // Palavra que o jogador deve adivinhar
    char letras_adivinhadas[sizeof(letras_corretas)] = {0}; // Array para armazenar letras adivinhadas
    int tentativas_restantes = MAX_TENTATIVAS; // Contador de tentativas restantes
    int letras_acertadas = 0; // Contador de letras corretas adivinhadas
    int i;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    printf("Bem-vindo ao Jogo de Adivinhacao de Letras!\n");
    printf("Voce tem %d tentativas para adivinhar a palavra.\n", MAX_TENTATIVAS);
    printf("A palavra tem %d letras. Boa sorte!\n", sizeof(letras_corretas) - 1);

    while (tentativas_restantes > 0 && letras_acertadas < sizeof(letras_corretas) - 1) {
        printf("\nDigite uma letra: ");
        char letra;
        scanf(" %c", &letra); // Lê a letra digitada pelo jogador
        letra = toupper(letra); // Converte a letra para maiúscula

        int ja_adivinhada = 0;
        for (i = 0; i < sizeof(letras_corretas) - 1; i++) {
            if (letras_adivinhadas[i] == letra) { // Verifica se a letra já foi adivinhada antes
                printf("Você ja tentou essa letra!\n");
                ja_adivinhada = 1;
                break;
            }
        }
        if (ja_adivinhada) {
            continue; // Pula para a próxima iteração do loop
        }

        int acertou = 0;
        for (i = 0; i < sizeof(letras_corretas) - 1; i++) {
            if (letras_corretas[i] == letra) { // Verifica se a letra está na palavra correta
                letras_adivinhadas[i] = letra; // Marca a letra como adivinhada
                letras_acertadas++; // Incrementa o contador de letras corretas
                acertou = 1;
            }
        }

        if (acertou) {
            printf("Parabens! '%c' esta na palavra.\n", letra); // Mensagem se o jogador acertou a letra
        } else {
            tentativas_restantes--; // Decrementa o número de tentativas restantes
            printf("Infelizmente '%c' nao esta na palavra.\n", letra); // Mensagem se o jogador errou a letra
            printf("Voce tem %d tentativas restantes.\n", tentativas_restantes);
        }

        printf("Palavra atual: ");
        for (i = 0; i < sizeof(letras_corretas) - 1; i++) {
            if (letras_adivinhadas[i]) {
                printf("%c ", letras_adivinhadas[i]); // Exibe as letras adivinhadas
            } else {
                printf("_ "); // Exibe espaços para letras ainda não adivinhadas
            }
        }
        printf("\n");
    }

    if (letras_acertadas == sizeof(letras_corretas) - 1) {
        printf("\nParabens! Voce adivinhou a palavra!\n"); // Mensagem de vitória se todas as letras foram adivinhadas
    } else {
        printf("\nQue pena! Voce nao adivinhou a palavra. A palavra era '%s'\n", letras_corretas); // Mensagem de derrota se o jogador não adivinhou a palavra
    }

    return 0;
}
