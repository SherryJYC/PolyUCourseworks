record = []

def isInList(list, element):
    return element in list

def sort(list):
    return sort(list)

def removeDup(list):
    list2 = []
    for i in list:
        if i not in list2:
            list2.append(i)
    return list2

def printSize(str):
    print(len(str))

def decomposeUniq(str):
    record = []
    list = str.split()
    for i in list:
        if i not in record:
            record.append(i)
    return record

def main():
    list = decomposeUniq("happy birthday to you")
    print("1. " + str(isInList(list, "to")))
    print("2. " + str(isInList(list, "me")))
    str1 = "TIGER tiger tiger burning bright In bright In the forests of the night What the immortal hand or eye hand or eye Could frame thy fearful symmetry?"
    list2 = removeDup(decomposeUniq(str1))
    str2 = "TIGER tiger burning bright In the forests of the night What the immortal hand or eye Could frame thy fearful symmetry?"
    list3 = decomposeUniq(str2)
    if len(list2) != len(list3):
        print("4. False")
    else: 
        for i in range(len(list2)):
            if list2[i] != list3[i]:
                print("4. False")
        else:
            print("4. True")
    printSize(str1)

if __name__ == "__main__":
    main()