import re
from cs50 import get_int

n = get_int("Number: ")
c = 0
x = 0
y = 0
p = 0
#loop to check if the number is valid or not
while n > 0:
    if c % 2 != 0: #if odd
        y = 2 * (n % 10)
        x = x + (y % 10) + int((y / 10))
    elif c % 2 == 0: #if even
        x = x + (n % 10)
    n = int(n / 10)
    if n < 100 and n > 10:
        p = n     #declairing first 2 digits as p
    c+= 1

if x % 10 != 0:
    print("INVALID")
    
elif c == 15 and (p == 34 or p == 37):
    print("AMEX")
    y = 0
elif (c == 16 or c == 13) and int(p/10) == 4:
    print("VISA")
    y = 0
elif ((c == 16) and (int(p / 10) == 5) and (p % 10 <= 5) and (p % 10 >= 1)):
    print("MASTERCARD")
    y = 0
else:
    print("INVALID")
