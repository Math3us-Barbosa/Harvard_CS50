from cs50 import get_float

# Getting change value from user
change = get_float("Change owed: ")
while change < 0.01:
    change = get_float("Change can't be negative, type a positive vallue: ")

# Counter for coins starts at 0
coins = 0

# Loop while there's still change to give, rounding to 2 decimal places
while round(change, 2) > 0:
    if change >= 0.25:  # If change is at least 0.25, give a quarter
        coins += 1
        change -= 0.25
        change = round(change, 2)
    elif change >= 0.10:  # If change is at least 0.10, give a dime
        coins += 1
        change -= 0.10
        change = round(change, 2)
    elif change >= 0.05:  # If change is at least 0.05, give a nickel
        coins += 1
        change -= 0.05
        change = round(change, 2)
    elif change >= 0.01:  # If change is at least 0.01, give a penny
        coins += 1
        change -= 0.01
        change = round(change, 2)

# Print the total number of coins used
print(coins)
