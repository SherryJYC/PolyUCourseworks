fileName = "tiger.txt"
inFile = open(fileName)
fileString = inFile.read()
inFile.close()
list2 = []

for line in fileString.splitlines():
    list2.append(line.split())

sum = 0
count = 0

for line in list2:
    for word in line:
        sum += len(word)
        count += 1

print("The average length fo the words in the poem (excluding punctuations) is: " + str(sum / count))