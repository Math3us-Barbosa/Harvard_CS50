#include <stdio.h>
#include <math.h>

// Definir a função f(x)
double f(double x) {
    // Exemplo: f(x) = x^3 - x - 2
    return (pow(x, 3)) - x - 2;
}

// Implementação do Método da Bisseção
double bissecao(double a, double b, double tolerancia, int max_iter) {
    double c; // Ponto médio
    int iteracao = 0;

    if (f(a) * f(b) >= 0) {
        printf("O método da bisseção não pode ser aplicado: f(a) e f(b) devem ter sinais opostos.\n");
        return NAN;
    }

    printf("Iteração\ta\tb\tc\tf(c)\n");

    while ((b - a) / 2.0 > tolerancia && iteracao < max_iter) {
        c = (a + b) / 2.0; // Calcula o ponto médio

        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\n", iteracao, a, b, c, f(c));

        if (f(c) == 0.0) {
            // c é uma raiz exata
            return c;
        } else if (f(a) * f(c) < 0) {
            // A raiz está no intervalo [a, c]
            b = c;
        } else {
            // A raiz está no intervalo [c, b]
            a = c;
        }

        iteracao++;
    }

    return c; // Aproximação da raiz
}

int main() {
    double a, b, tolerancia, raiz;
    int max_iter;

    // Entrada do intervalo [a, b]
    printf("Digite o limite inferior (a): ");
    scanf("%lf", &a);
    printf("Digite o limite superior (b): ");
    scanf("%lf", &b);

    // Entrada da tolerância e do número máximo de iterações
    printf("Digite a tolerância: ");
    scanf("%lf", &tolerancia);
    printf("Digite o número máximo de iterações: ");
    scanf("%d", &max_iter);

    // Chamada do método da bisseção
    raiz = bissecao(a, b, tolerancia, max_iter);

    // Exibir a raiz aproximada
    if (!isnan(raiz)) {
        printf("\nA raiz aproximada é: %.6f\n", raiz);
    }

    return 0;
}
