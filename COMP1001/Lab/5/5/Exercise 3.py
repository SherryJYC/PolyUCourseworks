fileName = "tiger.txt"
inFile = open(fileName)
fileString = inFile.read()
inFile.close()
list2 = []

for line in fileString.splitlines():
    list2.append(line.split())

sum = 0
count = 0
list = []

for line in list2:
    for word in line:
        if (len(word) > 4):
            count += 1
            list.append(word)

print("The number of words with length > 4 is " + str(count))
print("Those words are: " + str(list))