from cs50 import get_int

height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")
    if height < 1 or height > 8:
        print("height vallue must be between 1 and 8")
for i in range (height):
    print(" " * (height - 1 - i), end = "")
    print("#" * (i + 1), end = " ")
    print("#" * (i + 1), end = "")
    print(" " *(height - 1 - i))

x
