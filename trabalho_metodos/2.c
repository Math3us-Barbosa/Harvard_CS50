#include <stdio.h>
#include <math.h>

#define MAX 100
#define ERRO_TOLERADO 1e-6

// Função para calcular o erro relativo máximo entre as iterações
float calcularErro(float x_ant[], float x_atual[], int n) {
    float erro_max = 0.0;
    for (int i = 0; i < n; i++) {
        float erro = fabs((x_atual[i] - x_ant[i]) / x_atual[i]);
        if (erro > erro_max) {
            erro_max = erro;
        }
    }
    return erro_max;
}

// Método de Jacobi
void jacobi(float A[MAX][MAX], float b[MAX], float x_inicial[MAX], int n, int max_iter) {
    float x_atual[MAX], x_ant[MAX];
    int iteracao = 0;

    // Inicializar x_ant com o chute inicial
    for (int i = 0; i < n; i++) {
        x_ant[i] = x_inicial[i];
    }

    printf("Iteracao\t");
    for (int i = 0; i < n; i++) {
        printf("x%d\t", i + 1);
    }
    printf("Erro\n");

    while (iteracao < max_iter) {
        // Calcular as novas aproximações para x
        for (int i = 0; i < n; i++) {
            float soma = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    soma += A[i][j] * x_ant[j];
                }
            }
            x_atual[i] = (b[i] - soma) / A[i][i];
        }

        // Calcular o erro relativo máximo
        float erro = calcularErro(x_ant, x_atual, n);

        // Exibir os resultados da iteração
        printf("%d\t", iteracao + 1);
        for (int i = 0; i < n; i++) {
            printf("%.6f\t", x_atual[i]);
        }
        printf("%.6f\n", erro);

        // Verificar critério de parada
        if (erro < ERRO_TOLERADO) {
            printf("Convergencia atingida em %d iteracoes.\n", iteracao + 1);
            return;
        }

        // Atualizar x_ant para a próxima iteração
        for (int i = 0; i < n; i++) {
            x_ant[i] = x_atual[i];
        }

        iteracao++;
    }

    printf("Numero maximo de iteracoes atingido sem convergencia.\n");
}

int main() {
    int n, max_iter;
    float A[MAX][MAX], b[MAX], x_inicial[MAX];

    // Receber o número de variáveis
    printf("Digite o numero de variaveis: ");
    scanf("%d", &n);

    // Receber a matriz A
    printf("Digite os elementos da matriz A (coeficientes):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Receber o vetor b
    printf("Digite os elementos do vetor b (termos independentes):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    // Receber o chute inicial
    printf("Digite o chute inicial para as variaveis:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x_inicial[i]);
    }

    // Receber o número máximo de iterações
    printf("Digite o numero maximo de iteracoes: ");
    scanf("%d", &max_iter);

    // Resolver o sistema pelo método de Jacobi
    jacobi(A, b, x_inicial, n, max_iter);

    return 0;
}
