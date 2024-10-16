from cs50 import get_float

change = get_float("Change owed: ")
print(change)
coins = 0
while change > 0.0:
    if change >= 0.25:
        coins += 1
        change -= 0.25
    elif change >= 0.10:
        coins +=1
        change -= 0.10
    elif change >= 0.05:
        coins += 1
        change -= 0.05
    elif change >= 0.009:
        coins += 1
        change -=0.01
print(coins)
