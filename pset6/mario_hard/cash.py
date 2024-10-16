from cs50 import get_float

change = get_float("Change owed: ")
coins = 0
while change > 0
    if change >= 0.25
        coins += 1
        change -= 0.25
    elif change >= 0.10
        coins +=1
        change -= 0.10
    elif change >= 0.5
        coins += 1
        change -= 0.10
    elif change >= 0.1
        coins += 1
        change -=0.1
print(coins)
