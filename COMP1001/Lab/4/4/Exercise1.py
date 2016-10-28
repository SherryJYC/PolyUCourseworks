name = []
score = []

def inputData():
    while True:
        inputText = input("Please input student name and score, seperated by space. Input Q to quit.")
        if inputText == 'Q':
            printData()
            break
        inputText = inputText.split()
        name.append(inputText[0])
        score.append(int(inputText[1]))


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

if __name__ == "__main__":
    inputData()

