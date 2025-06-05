#include <stdio.h>

#define TAM 10
#define HABILIDADE 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(".");  // água
            else if (tabuleiro[i][j] == 3)
                printf("3");  // navio
            else if (tabuleiro[i][j] == 5)
                printf("5");  // área de habilidade
        }
        printf("\n");
    }
    printf("\n");
}

// Função para aplicar a habilidade ao tabuleiro, centrando em (linha, coluna)
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HABILIDADE][HABILIDADE], int origemLinha, int origemColuna) {
    int meio = HABILIDADE / 2;
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int tabLinha = origemLinha - meio + i;
                int tabColuna = origemColuna - meio + j;
                // Verifica limites e se não é navio
                if (tabLinha >= 0 && tabLinha < TAM && tabColuna >= 0 && tabColuna < TAM) {
                    if (tabuleiro[tabLinha][tabColuna] != 3) {
                        tabuleiro[tabLinha][tabColuna] = 5;  // marca área afetada
                    }
                }
            }
        }
    }
}

int main() {
    // Tabuleiro inicial: 0 = água, 3 = navio
    int tabuleiro[TAM][TAM] = {0};

   

    // Matriz de habilidade: Cone (5x5) - ponto de origem no topo, área em forma de cone para baixo
    int cone[HABILIDADE][HABILIDADE] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    // Matriz de habilidade: Cruz (5x5) - ponto de origem no centro
    int cruz[HABILIDADE][HABILIDADE] = {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };

    // Matriz de habilidade: Octaedro (5x5) - ponto de origem no centro, forma losango
    int octaedro[HABILIDADE][HABILIDADE] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };


    // Aplicar habilidades com pontos de origem escolhidos:
    aplicarHabilidade(tabuleiro, cone, 2, 3); // cone perto do topo
    aplicarHabilidade(tabuleiro, cruz, 6,2); // cruz no canto inferior esquerdo
    aplicarHabilidade(tabuleiro, octaedro, 7, 7); // octaedro no canto inferior direito

    printf("Habilidades:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}