from cs50 import get_int
height = int(input("Height: "))
for i in  [0,1,2,3]:
    print(" " * (height - 1 - i),end = "")
    print("#" * i)

