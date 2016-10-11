str = input("Please enter the combination of braces: ")
record = []
for bra in str:
    if bra == '(':
        record.append(bra)
    else:
        if record:
            record.pop()
        else:
            print("The result is: False.")
            break
else:
    if record:
        print("The result is: False.")
    else:
        print("The result is: True.")
