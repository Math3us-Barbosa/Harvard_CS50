import re
from cs50 import get_int

n = get_int("Number: ")
c = 0
x = 0
y = 0
p = 0
# loop to check if the number is valid or not
while n > 0:
    if c % 2 != 0:  # if odd
        y = 2 * (n % 10)
        x += (y % 10) + int((y / 10))
    elif c % 2 == 0:  # if even
        x += (n % 10)
    n = int(n / 10)  # going to the next algorism
    if n < 100 and n > 10:
        p = n  # declairing first 2 digits as p
    c += 1
# checking if the last digit of the Luhm algorithm is 0
if x % 10 != 0:
    print("INVALID")
# checking first to digits and amount of digits to define the output
elif c == 15 and (p == 34 or p == 37):
    print("AMEX")
elif (c == 16 or c == 13) and int(p/10) == 4:
    print("VISA")
elif ((c == 16) and (int(p / 10) == 5) and (p % 10 <= 5) and (p % 10 >= 1)):
    print("MASTERCARD")
else:
    print("INVALID")
