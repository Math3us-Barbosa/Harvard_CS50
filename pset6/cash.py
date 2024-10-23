from cs50 import get_float

#getting change vallue
change = get_float("Change owed: ")
#counter for coins started as 0
coins = 0
#while change > 0.00 chose 
while round(change,2) > 0:
    if change >= 0.25:
        coins += 1
        change -= 0.25
        change = round(change,2)
    elif change >= 0.10:
        coins +=1
        change -= 0.10
        change = round(change,2)
    elif change >= 0.05:
        coins += 1
        change -= 0.05
        change = round(change,2)
    elif change >= 0.01:
        coins += 1
        change -=0.01
        change = round(change,2)
print(coins)
