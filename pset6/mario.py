from cs50 import get_int
height = int(input("Height: "))
for i in  range (height):
    print(" " * (height - 1 - i),end = "")
    print("#" * (i+1))

