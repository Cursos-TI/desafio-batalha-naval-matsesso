#include <stdio.h>

// Desafio Batalha Naval - MateCheck- Nível Mestre 

// Definindo o tamanho do tabuleiro
#define TAMANHO 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar habilidade em cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (i + j >= 0 && i + j <= 2) {
                int novaX = x + i;
                int novaY = y + j;
                if (novaX >= 0 && novaX < TAMANHO && novaY >= 0 && novaY < TAMANHO) {
                    tabuleiro[novaX][novaY] = 1; // Marca a área afetada
                }
            }
        }
    }
}

// Função para aplicar habilidade em cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        if (x + i >= 0 && x + i < TAMANHO) {
            tabuleiro[x + i][y] = 1; // Marca a linha vertical
        }
        if (y + i >= 0 && y + i < TAMANHO) {
            tabuleiro[x][y + i] = 1; // Marca a linha horizontal
        }
    }
}

// Função para aplicar habilidade em octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2) {
                int novaX = x + i;
                int novaY = y + j;
                if (novaX >= 0 && novaX < TAMANHO && novaY >= 0 && novaY < TAMANHO) {
                    tabuleiro[novaX][novaY] = 1; // Marca a área afetada
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa o tabuleiro com 0

    // Posicionamento dos navios (exemplo)
    tabuleiro[1][1] = 3; // Navio horizontal
    tabuleiro[2][1] = 3; // Navio horizontal
    tabuleiro[3][1] = 3; // Navio horizontal
    tabuleiro[5][5] = 3; // Navio vertical
    tabuleiro[5][6] = 3; // Navio vertical

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    // Aplicar habilidades
    aplicarHabilidadeCone(tabuleiro, 4, 4);
    aplicarHabilidadeCruz(tabuleiro, 4, 4);
    aplicarHabilidadeOctaedro(tabuleiro, 4, 4);

    // Exibir o tabuleiro após aplicar habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}
