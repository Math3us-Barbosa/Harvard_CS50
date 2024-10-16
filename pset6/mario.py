from cs50 import get_int
height = get_int("Height: ")
for i in range (height+1):
    print(" " * (height-i),end = "")
    print("#" * i)
