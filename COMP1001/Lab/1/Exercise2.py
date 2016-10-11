total = 0
maxVal = 1000
for i in range(1,maxVal+1):
    if i % 2 == 1:
        total += i
print ("The sum of odd numbers between 1–" + str(maxVal) + " is " + str(total))