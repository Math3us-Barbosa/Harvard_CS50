from cs50 import get_int

height = 0
#getting the height from the user, the height must be between 1 and 8
while height < 1 or height > 8:
    height = get_int("Height: ")
    if height < 1 or height > 8:
        print("height vallue must be between 1 and 8")
#loop to iterate through all lines
for i in range (height):
    print(" " * (height - 1 - i), end = "") #printing spaces before 1st pyramide
    print("#" * (i + 1), end = "  ") #printing hashes from 1st pyramide/space at the end
    print("#" * (i + 1))  #printing hashes from 2nd pyramide


