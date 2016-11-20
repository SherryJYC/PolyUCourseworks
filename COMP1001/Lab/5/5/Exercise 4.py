name = []
score = []

def inputData(fileName):
    file = open(fileName)
    fileString = file.read()
    file.close()
    for line in fileString.splitlines():
        list = line.split()
        name.append(list[0])
        score.append(int(list[1]))


def printData():
    global name
    global score
    for i in range(len(name)):
        print(name[i] + " " + " " + str(score[i]) + " " + grade(score[i]))


def grade(x):
    if x >= 95:
        return "A+"
    elif 85 <= x <= 89:
        return "A"
    elif 80 <= x <= 84:
        return "B+"
    elif 75 <= x <= 79:
        return "B"
    elif 70 <= x <= 74:
        return "B-"
    elif 65 <= x <= 69:
        return "C+"
    elif 60 <= x <= 64:
        return "C"
    elif 55 <= x <= 59:
        return "C-"
    elif 50 <= x <= 54:
        return "D"
    else:
        return "F"

def main():
    fileName = input("Please input the fileName: ")
    inputData(fileName)
    printData()

if __name__ == "__main__":
    main()



