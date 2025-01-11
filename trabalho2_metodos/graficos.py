import numpy as np
import matplotlib.pyplot as plt

# Função para plotar os gráficos
def plotar_funcoes():
    # Definir o intervalo de valores para x
    x = np.linspace(-10, 10, 400)

    # Funções para plotar
    funcoes = {
        "P(x) = 2x^3 - 3x^2 - 6x + 5": 2*x**3 - 3*x**2 - 6*x + 5,  # Função polinomial P(x)
        "f(x) = e^(2x) - 2x^3 - 5": np.exp(2*x) - 2*x**3 - 5,        # Função f(x) = e^(2x) - 2x^3 - 5
        "f(x) = 2x^3 + 5x^2 - sen(x) - 3": 2*x**3 + 5*x**2 - np.sin(x) - 3,  # Função f(x) = 2x^3 + 5x^2 - sen(x) - 3
        "f(x) = (x+1)(x-1)(x-35)": (x+1)*(x-1)*(x-35),             # Função f(x) = (x+1)(x-1)(x-35)
    }

    # Criar a figura
    plt.figure(figsize=(10, 6))

    # Plotar cada função
    for nome, funcao in funcoes.items():
        plt.plot(x, funcao, label=nome)

    # Ajustar os limites do gráfico para melhorar a visualização
    plt.ylim(-200, 200)

    # Adicionar título e rótulos aos eixos
    plt.title('Gráficos das Funções')
    plt.xlabel('x')
    plt.ylabel('y')

    # Mostrar a legenda
    plt.legend()

    # Mostrar o gráfico
    plt.grid(True)
    plt.show()

# Chamar a função para plotar os gráficos
plotar_funcoes()
