#include <stdio.h>

#define TAM 10  // Tamanho do tabuleiro
#define NAVIO 3 // Valor que representa um navio
#define TAMANHO_NAVIO 3 // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];  // Declara o tabuleiro 10x10

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // NAVIO HORIZONTAL (linha 0, colunas 2 a 4)
    for (int j = 2; j < 2 + TAMANHO_NAVIO; j++) {
        tabuleiro[0][j] = NAVIO;
    }

    // NAVIO VERTICAL (coluna 5, linhas 4 a 6)
    for (int i = 4; i < 4 + TAMANHO_NAVIO; i++) {
        tabuleiro[i][5] = NAVIO;
    }

 
    // Mostra o tabuleiro na tela
    printf("TABULEIRO BATALHA NAVAL (3 = NAVIO, 0 = ÁGUA)\n\n");

    // Cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Imprime o tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%d  ", i); // Número da linha
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}