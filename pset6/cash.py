from cs50 import get_float

change = get_float("Change owed: ")
print(change)
coins = 0
while change > 0.0:
    if change >= 0.25:
        coins += 1
        change -= 0.2500000
        print(change)
    elif change >= 0.10:
        coins +=1
        change -= 0.10
        print(change)
    elif change >= 0.05:
        coins += 1
        change -= 0.05
        print(change)
    elif change >= 0.009:
        coins += 1
        change -=0.01
        print(change)
print(coins)
