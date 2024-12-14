#include <stdio.h>
#include <math.h>

// Definindo as funções não lineares
double f1(double x) {
    return exp(x) - 2 * x * x;
}

double f2(double x) {
    return x * x * x - 2 * x - 5;
}

// Método da Secante
double secante(double (*f)(double), double x0, double x1, double tolerancia, int max_iter) {
    int iteracoes = 0;
    double x2, f_x2;

    // Imprimindo o cabeçalho
    printf("Iteração\tx0\t\t x1\t\t x2\t\t f(x2)\n");

    while (iteracoes < max_iter) {
        // Aplicando a fórmula da secante
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        f_x2 = f(x2);

        // Imprimindo os valores de cada iteração
        printf("%d\t\t %.6f\t %.6f\t %.6f\t %.6f\n", iteracoes + 1, x0, x1, x2, f_x2);

        // Verificando a convergência
        if (fabs(x2 - x1) < tolerancia) {
            break;
        }

        // Atualizando os valores para a próxima iteração
        x0 = x1;
        x1 = x2;
        iteracoes++;
    }

    return x2; // Retorna a raiz aproximada
}

int main() {
    double x0 = 1.0, x1 = 2.0; // Aproximações iniciais
    double tolerancia = 1e-6; // Tolerância
    int max_iter = 50; // Número máximo de iterações

    // Aplicando o método da secante nas duas funções
    printf("Evolução do Método da Secante - Função 1: f1(x) = exp(x) - 2x^2\n");
    double raiz_f1 = secante(f1, x0, x1, tolerancia, max_iter);
    printf("\nRaiz aproximada de f1: %.6f\n\n", raiz_f1);

    printf("Evolução do Método da Secante - Função 2: f2(x) = x^3 - 2x - 5\n");
    double raiz_f2 = secante(f2, x0, x1, tolerancia, max_iter);
    printf("\nRaiz aproximada de f2: %.6f\n", raiz_f2);

    return 0;
}
