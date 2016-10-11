import random
print("Welcome to the number-guessing game.")

num = random.randint(0, 100)
first = True

while True:
    if first:
        answer = eval(input("Please guess a number between 0 and 100, inclusive. "))
    else:
        answer = eval(input("Please guess a number between 0 and 100, inclusive.\
        \nIf you want to quit, enter a number outside the range. "))

    if not first:
        if answer < 0 or answer > 100:
            print("\nYou quit!!")
            break

    if answer < num:
        print("\nYour guess is too low!")
    elif answer > num:
        print("\nYour guess is too high!")
    else:
        print("\nYour guess is correct!!")
        break

    first = False
