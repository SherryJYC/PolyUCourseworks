length = eval(input("Please enter the length of the rectangle: "))
width = eval(input("Please enter the width of the rectangle: "))
space = eval(input("Please enter the number of spaces between symbols: "))
symbol = input("Please enter a symbol: ")

row = 1

type_a = ""
space_num = 0

for i in range(1, length + 1):
    if space_num == 0:
        type_a += symbol
    else:
        type_a += " "
    space_num += 1
    if space_num == space:
        space_num = 0

if space_num != 1:
    while space_num != space + 1:
        type_a += " "
        space_num += 1
    type_a += symbol

print(type_a)

type_b = ""

for n in range(len(type_a)):
    if n != 0 and n != len(type_a) - 1:
        type_b += " "
    else:
        type_b += symbol

for m in range(1, width - 1):
    print(type_b)

print(type_a)
