#help function in pre-processing
def processRowPrice():
    file = open('rowData\data.txt')
    lines = file.readlines()
    table = []
    blockHead = [0, 17, 22, 38, 55, 63, 73, 85, 99]
    for i in lines:
        table.append(i.split())

    for i in range(len(table)):
        while (True):
            try:
                float(table[i][0])
                break
            except ValueError:
                table[i].pop(0)

    for i in range(len(table)):
        table[i].insert(i, '0.0')
        while len(table[i]) < 108:
            block = int(input("Please input the block for line " + str(i) + ":"))
            position = int(input("Please input the position in block " + str(block) + " for line " + str(i) + ":"))
            insertPosition = blockHead[block] + position;
            table[i].insert(insertPosition, '0.0')
            table[insertPosition].insert(i, '0.0')
            

    for i in range(len(table)):
        table[i] = ','.join(table[i])
    table = '\n'.join(table)

    file = open('stationPrice.csv', 'w')
    file.write(table)
    file.close()

def processRowPrice():
    file = open('rowData\dataStudent.txt')
    lines = file.readlines()
    table = []
    blockHead = [0, 17, 22, 38, 55, 63, 73, 85, 99]
    j = -1 
    pre = False
    for i in lines:
        try:
            float(i)
            table[j].append(i.replace('\n', ''))
            pre = False
        except:
            if pre == False:
                table.append([])
                j += 1
                pre = True

    for i in range(len(table)):
        table[i].insert(i, '0.0')
        while len(table[i]) < 108:
            block = int(input("Please input the block for line " + str(i) + ":"))
            position = int(input("Please input the position in block " + str(block) + " for line " + str(i) + ":"))
            insertPosition = blockHead[block] + position;
            table[i].insert(insertPosition, '0.0')
            table[insertPosition].insert(i, '0.0')
            

    for i in range(len(table)):
        table[i] = ','.join(table[i])
    table = '\n'.join(table)

    file = open('stationPriceStudent.csv', 'w')
    file.write(table)
    file.close()

def processRowPostion(win):
    global stationPosition
    for i in range(len(priceAdult)):
        print(stationName[i] + ': ')
        position = win.getMouse()
        stationPosition.append((str(position.getX()), str(position.getY())))
        print(str(stationPosition[i][0]), str(stationPosition[i][1]))

    for i in range(len(stationPosition)):
        stationPosition[i] = ','.join(stationPosition[i])
    print(len(stationPosition))
    win.getMouse()
    stationPosition = '\n'.join(stationPosition)
    file = open('stationPosition.csv', 'w')
    file.write(stationPosition)
    file.close()
