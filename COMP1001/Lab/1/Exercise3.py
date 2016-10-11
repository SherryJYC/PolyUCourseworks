num = eval(input("Please enter a number between 1 and 9 (inclusive): "))

for i in range(1, num + 1):
    temp = ""
    for n in range(1, num - i + 1):
        temp += " "
    for m in range(1, i + 1):
        temp += str(m)
    print(temp)

