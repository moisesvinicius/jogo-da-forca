# Jogo da Forca em C 🎮

Este é um simples jogo da forca implementado em C. O jogador tenta adivinhar uma palavra oculta, digitando letras uma por uma. O jogo fornece feedback sobre letras corretas e erradas, além de um número limitado de tentativas para adivinhar a palavra inteira.

## Funcionalidades

- Jogo interativo de forca em modo texto.
- O jogador tem um número limitado de tentativas para adivinhar a palavra.
- Feedback em tempo real sobre letras corretas e erradas.
- Interface simples e fácil de entender.

## Como Jogar

1. Clone o repositório para o seu computador.
2. Compile o código-fonte usando um compilador C.
3. Execute o jogo.
4. Digite letras para tentar adivinhar a palavra oculta.
5. Continue até adivinhar a palavra correta ou até acabarem suas tentativas.

## Exemplo de Uso

```shell
$ ./jogo_da_forca
Bem-vindo ao Jogo da Forca!

Palavra: _ _ _ _ _ _

Tentativas restantes: 5

Digite uma letra: a
A palavra não contém a letra 'a'. Tente novamente.

Palavra: _ _ _ _ _ _

Tentativas restantes: 4

Digite uma letra: e
A palavra contém a letra 'e'. Continue assim!

Palavra: _ E _ _ E _

Tentativas restantes: 4
