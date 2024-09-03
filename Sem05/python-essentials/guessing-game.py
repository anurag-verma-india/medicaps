from random import randint 

jackpot = randint(1,100)
guess = int(input("\nEnter a number: "))

count = 1

while guess != jackpot:
    if guess < jackpot:
        print("Guess Higher: ", end="")
    else: 
        print("Guess lower: ", end="")
    count+=1
    guess = int(input())

print("You guessed correctly in ", count , " tries")


    
        