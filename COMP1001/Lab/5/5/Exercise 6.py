import csv

record = {}

fileName = input("Please input the file name: ")
file = open(fileName)
fileString = file.read()
list = []
for line in fileString.splitlines():
    for word in line.split():
        list.append(word)
for word in list:
    if word in record:
        record[word] += 1
    else:
        record[word] = 1
        
keys = record.keys()
values = record.values()



with open('result.csv', 'w') as myfile:
    wr = csv.writer(myfile, quoting=csv.QUOTE_ALL)
    wr.writerow(keys)
    wr.writerow(values)

