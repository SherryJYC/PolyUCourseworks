#a
def inputData(fileName):
    file1 = open(fileName)
    fileString1 = file1.read()
    list1 = []
    for line in fileString1.splitlines():
        for word in line.split():
            list1.append(word)
    return list1

#b
def countWord(fileName):
    list1 = inputData(fileName)
    return len(list1)

#c
def removeDup(list):
    list2 = []
    for i in list:
        if i not in list2:
            list2.append(i)
    return list2

#d
def countWors(fileName):
    list = inputData(fileName)
    list2 = removeDup(list1)
    return len(list2)

#e
def sizeOfFile(fileName):
    file1 = open(fileName)
    fileString1 = file1.read()
    file1.close()
    return len(file1)

#f
def largestFile(fileNames):
    sizes = []
    for file in fileNames:
        sizes.append(sizeOfFile(file))
    max = max(sizes)
    maxIndex = sizes.index(max)
    return fileNames[maxIndex]