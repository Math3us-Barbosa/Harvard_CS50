import numpy as np
import matplotlib.pyplot as plt

# Definindo as funções não lineares
def f1(x):
    return np.exp(x) - 2*x**2

def f2(x):
    return x**3 - 2*x - 5

# Método da Secante
def secante(f, x0, x1, tolerancia, max_iter):
    iteracoes = 0
    x_vals = [x0, x1]
    f_vals = [f(x0), f(x1)]

    while iteracoes < max_iter:
        # Aplicando a fórmula da secante
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        f_x2 = f(x2)

        # Registrando os valores
        x_vals.append(x2)
        f_vals.append(f_x2)

        # Verificando a convergência
        if abs(x2 - x1) < tolerancia:
            break

        # Atualizando os valores para a próxima iteração
        x0, x1 = x1, x2
        iteracoes += 1

    return x2, iteracoes, x_vals, f_vals

# Parâmetros
x0 = 1.0  # Aproximação inicial
x1 = 2.0  # Segunda aproximação inicial
tolerancia = 1e-6
max_iter = 50

# Aplicando o método da secante nas duas funções
raiz_f1, iter_f1, x_vals_f1, f_vals_f1 = secante(f1, x0, x1, tolerancia, max_iter)
raiz_f2, iter_f2, x_vals_f2, f_vals_f2 = secante(f2, x0, x1, tolerancia, max_iter)

# Exibindo os resultados
print(f"Função 1 (f1) - Raiz aproximada: {raiz_f1}, Iterações: {iter_f1}")
print(f"Função 2 (f2) - Raiz aproximada: {raiz_f2}, Iterações: {iter_f2}")

# Plotando os gráficos da evolução do método da secante
x = np.linspace(-2, 2, 400)
y1 = f1(x)
y2 = f2(x)

plt.figure(figsize=(14, 6))

# Gráfico da função 1
plt.subplot(1, 2, 1)
plt.plot(x, y1, label="f1(x) = exp(x) - 2x^2")
plt.axhline(0, color='black',linewidth=1)
plt.scatter(x_vals_f1, f_vals_f1, color='red', label="Pontos de iteração")
plt.title("Método da Secante - f1(x)")
plt.xlabel("x")
plt.ylabel("f1(x)")
plt.legend()

# Gráfico da função 2
plt.subplot(1, 2, 2)
plt.plot(x, y2, label="f2(x) = x^3 - 2x - 5")
plt.axhline(0, color='black',linewidth=1)
plt.scatter(x_vals_f2, f_vals_f2, color='red', label="Pontos de iteração")
plt.title("Método da Secante - f2(x)")
plt.xlabel("x")
plt.ylabel("f2(x)")
plt.legend()

plt.tight_layout()
plt.show()
