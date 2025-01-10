import numpy as np
import sympy as sp
import math

# Funções auxiliares para os métodos
def bissecao(func, a, b, epsilon):
   if func(a) * func(b) >= 0:
       raise ValueError("O intervalo inicial [a, b] não garante uma raiz.")


   print(f"{'Iteração':<10}{'a':<15}{'b':<15}{'c':<15}{'f(c)':<15}")
   iteracao = 0
   while abs(b - a) >= epsilon:
       c = (a + b) / 2
       fc = func(c)
       print(f"{iteracao:<10}{a:<15.10f}{b:<15.10f}{c:<15.10f}{fc:<15.10f}")

       if fc == 0 or abs(b - a) < epsilon:
           break
       elif func(a) * fc < 0:
           b = c
       else:
           a = c
       iteracao += 1
   return c


def falsa_posicao(func, a, b, epsilon):
   if func(a) * func(b) >= 0:
       raise ValueError("O intervalo inicial [a, b] não garante uma raiz.")


   print(f"{'Iteração':<10}{'a':<15}{'b':<15}{'c':<15}{'f(c)':<15}")
   iteracao = 0
   c_ant = a
   while True:
       c = (a * func(b) - b * func(a)) / (func(b) - func(a))
       fc = func(c)
       print(f"{iteracao:<10}{a:<15.10f}{b:<15.10f}{c:<15.10f}{fc:<15.10f}")


       if abs(c - c_ant) < epsilon:
           break
       c_ant = c


       if func(a) * fc < 0:
           b = c
       else:
           a = c
       iteracao += 1
   return c


def ponto_fixo(func, g, x0, epsilon):
   print(f"{'Iteração':<10}{'x':<15}{'g(x)':<15}{'f(x)':<15}")
   iteracao = 0
   while True:
       x = g(x0)
       print(f"{iteracao:<10}{x0:<15.10f}{x:<15.10f}{func(x):<15.10f}")

       if abs(x - x0) < epsilon:
           break
       x0 = x
       iteracao += 1
   return x


def newton(func, x0, epsilon):
   # Definindo a variável simbólica x para o cálculo da derivada
   x = sp.symbols('x')
   # Derivada simbólica da função
   f_prime = sp.diff(func(x), x)
   f_prime_lambda = sp.lambdify(x, f_prime, 'numpy')  # Converte a derivada simbólica em função numérica


   print(f"""{"Iteração":<10}{"x":<15}{"f(x)":<15}{"f'(x)":<15}""")






   iteracao = 0
   while True:
       fx = func(x0)
       dfx = f_prime_lambda(x0)  # Calculando a derivada numericamente
       if dfx == 0:
           raise ValueError("Derivada zero, não é possível continuar.")


       x = x0 - fx / dfx
       print(f"{iteracao:<10}{x0:<15.10f}{fx:<15.10f}{dfx:<15.10f}")

       if abs(x - x0) < epsilon:
           break
       x0 = x
       iteracao += 1
   return x


def secante(func, x0, x1, epsilon):
    print(f"{'Iteração':<10}{'x0':<15}{'x1':<15}{'x':<15}{'f(x)':<15}")
   iteracao = 0
   while True:
       fx0 = func(x0)
       fx1 = func(x1)
       if fx1 - fx0 == 0:
           raise ValueError("Diferença zero entre f(x0) e f(x1), divisão por zero.")


       x = x1 - fx1 * (x1 - x0) / (fx1 - fx0)
       print(f"{iteracao:<10}{x0:<15.10f}{x1:<15.10f}{x:<15.10f}{func(x):<15.10f}")

       if abs(x - x1) < epsilon:
           break
       x0, x1 = x1, x
       iteracao += 1
   return x


# Função principal
def main():
   print("Escolha o método numérico:")
   print("1 - Bisseção")
   print("2 - Falsa Posição")
   print("3 - Ponto Fixo")
   print("4 - Newton")
   print("5 - Secante")


   metodo = int(input("Digite o número do método: "))



   # Variável simbólica
   x = sp.Symbol('x')

    # Função simbólica para o SymPy
    func_simb = sp.exp(2 * x) - 2 * x**3 - 5  # Use sp.exp em vez de math.exp

    # Função numérica para cálculo
    func = lambda x: math.exp(2 * x) - 2 * x**3 - 5
    epsilon = 0.01


   if metodo == 1 or metodo == 2:
       a = float(input("Digite o valor de a (início do intervalo): "))
       b = float(input("Digite o valor de b (fim do intervalo): "))
       if metodo == 1:
           raiz = bissecao(func, a, b, epsilon)
       else:
           raiz = falsa_posicao(func, a, b, epsilon)


   elif metodo == 3:
       x0 = float(input("Digite o valor de x0 (ponto inicial): "))
       g = lambda x: math.log(2 * x**3 + 5) / 2 # Insira aqui a função para o ponto fixo
       raiz = ponto_fixo(func, g, x0, epsilon)


   elif metodo == 4:
       x0 = float(input("Digite o valor de x0 (ponto inicial): "))
       raiz = newton(func, x0, epsilon)


   elif metodo == 5:
       x0 = float(input("Digite o valor de x0 (primeiro ponto inicial): "))
       x1 = float(input("Digite o valor de x1 (segundo ponto inicial): "))
       raiz = secante(func, x0, x1, epsilon)


   else:
       print("Método inválido!")
       return


   print(f"\nRaiz encontrada: {raiz}")


if __name__ == "__main__":
   main()



