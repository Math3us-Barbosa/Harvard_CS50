#include <stdio.h>
#include <math.h>

#define MAX 10 // Definição do tamanho máximo da matriz

// Função para trocar duas linhas
void trocarLinhas(float matriz[MAX][MAX+1], int linha1, int linha2, int n) {
    for (int i = 0; i <= n; i++) {
        float temp = matriz[linha1][i];
        matriz[linha1][i] = matriz[linha2][i];
        matriz[linha2][i] = temp;
    }
}

// Função para fazer o escalonamento da matriz utilizando o método de Gauss-Jordan
void gaussJordan(float matriz[MAX][MAX+1], int n, int m) {
    for (int i = 0; i < n; i++) {
        // Encontrar o maior valor na coluna i para evitar divisão por números pequenos
        int maxRow = i;
        for (int k = i+1; k < n; k++) {
            if (fabs(matriz[k][i]) > fabs(matriz[maxRow][i])) {
                maxRow = k;
            }
        }

        // Trocar a linha atual com a linha com o maior valor
        if (maxRow != i) {
            trocarLinhas(matriz, i, maxRow, m);
        }

        // Normalizar a linha para que o elemento da diagonal principal seja 1
        float pivot = matriz[i][i];
        if (pivot == 0) {
            printf("Sistema não tem solução única (possivelmente indeterminado ou inconsistente).\n");
            return;
        }

        for (int j = 0; j <= m; j++) {
            matriz[i][j] /= pivot;
        }

        // Eliminar todos os elementos abaixo e acima da diagonal
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = matriz[k][i];
                for (int j = 0; j <= m; j++) {
                    matriz[k][j] -= factor * matriz[i][j];
                }
            }
        }

        // Mostrar a matriz após cada coluna ser processada
        printf("Matriz após a coluna %d ser escalonada:\n", i+1);S
        for (int a = 0; a < n; a++) {
            for (int b = 0; b <= m; b++) {
                printf("%.2f ", matriz[a][b]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int n, m;

    // Receber o número de equações (n) e variáveis (m)
    printf("Digite o número de equações: ");
    scanf("%d", &n);

    printf("Digite o número de variáveis: ");
    scanf("%d", &m);

    float matriz[MAX][MAX+1];

    // Receber a matriz aumentada
    printf("Digite os elementos da matriz aumentada (coeficientes e termos constantes):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    // Mostrar a matriz original
    printf("\nMatriz original:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Chamar o método de Gauss-Jordan
    gaussJordan(matriz, n, m);

    // Exibir a solução do sistema (valores das variáveis)
    printf("Soluções do sistema:\n");
    for (int i = 0; i < m; i++) {
        printf("x%d = %.2f\n", i+1, matriz[i][m]);
    }

    return 0;
}
