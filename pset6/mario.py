from cs50 import get_int
height = int(input("Height: ))
for i in range (height+1):
    print(" " * (height-i),end = "")
    print("#" * i)
