import re

num = get_int("Number: ")
c = 0
x = 0
y = 0
#loop to check if the number is valid or not
while n > 0:
    if c % 2 != 0: #if odd
        y = 2 * (n % 10)
        if y >= 10:
            x = x + (y % 10) + (y / 10)
        else:
            x = x + y
        n = n / 10
    elif c % 2 == 0 #if even
        x = x + (n % 10)
        n = n / 10

    #declairing first 2 digits as p
    if n < 100 and n > 10:
        p = n
    c+=
if x % 10 != 0:
    print("INVALID")
elif c = 15 and (p = 34 or p = 37):
    print("AMEX")
elif c = 16 and p


