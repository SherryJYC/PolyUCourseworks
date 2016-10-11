num = eval(input("Please enter a number: "))
sum = 0
for x in range(1, num - 1):
    if num % x == 0:
        sum += x
if sum == num:
    print("{} is a p-number.".format(num))
else:
    print("{} is not a p-number.".format(num))
