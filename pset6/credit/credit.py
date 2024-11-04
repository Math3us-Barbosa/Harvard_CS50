import re

n = get_int("Number: ")
c = 0
//loop para checar validade do numero
while n > 0:
    if c % 2 != 0: //se impar
        y = 2 * (n % 10)
        if y >= 10:
            x = x + (y % 10) + (y / 10)
        else:
            x = x + y
        n = n / 10
    elif c % 2 == 0 //se par
        x = x + (n % 10)
        n = n / 10

    #declairing first 2 digits as p
    if n < 100 and n > 10:
        p = n
    c+=
num = str(n)

patterns = {
    "AMEX": r"^3[47][0-9]{13}$",          # Começa com 34 ou 37, e tem 15 dígitos
    "VISA": r"^4[0-9]{12}(?:[0-9]{3})?$", # Começa com 4, e tem 13 ou 16 dígitos
    "MASTERCARD": r"^5[1-5][0-9]{14}$"    # Começa com 51-55, e tem 16 dígitos
}
if re.match(pattern,num)
    print(pattern)
