"""This program aims to save the MTR travel cost for a family. 

Assuming that there are n>1 family members. Each one of them will travel starting from a given station to another station. For each member, he or she have specific ticket type, namely Adult ticket, Student ticket, and Child ticket. Besides, each member could have different round trip per day. This program will compute the location (in terms of the station) where they should live to minimize the total travel cost."""
from graphics import *
import math

"""Main class for the Program"""
class Interface:
    def __init__(self, title, x, y):
        self.win = GraphWin(title, x, y)
        self.stationPosition = []
        self.priceAdult = []
        self.priceChild = []
        self.priceStudent = []
        self.stationName = []

        self.typeButton = []
        self.tripButton = []

        self.record = []
        self.destChosen = -1
        self.tripChosen = -1
        self.typeChosen = -1

        self.readData()
        self.setUi(self.win)

    """read the data from .csv files"""
    def readData(self):
        file = open('stationName.csv')
        self.stationName = file.read().split('\n')
        file.close()

        file = open('stationPrice.csv')
        lines = file.readlines()
        for i in lines:
            self.priceAdult.append(i.split(','))
            self.priceAdult[len(self.priceAdult) - 1] = list(map(float, self.priceAdult[len(self.priceAdult) - 1]))
        file.close()

        file = open('stationPriceChild.csv')
        lines = file.readlines()
        for i in lines:
            self.priceChild.append(i.split(','))
            self.priceChild[len(self.priceChild) - 1] = list(map(float, self.priceChild[len(self.priceChild) - 1]))
        file.close()

        file = open('stationPriceStudent.csv')
        lines = file.readlines()
        for i in lines:
            self.priceStudent.append(i.split(','))
            self.priceStudent[len(self.priceStudent) - 1] = list(map(float, self.priceStudent[len(self.priceStudent) - 1]))
        file.close()

        file = open('stationPosition.csv')
        lines = file.readlines()
        for i in lines:
            self.stationPosition.append(i.split(','))
            self.stationPosition[len(self.stationPosition) - 1] = list(map(float, self.stationPosition[len(self.stationPosition) - 1]))
        file.close()

    """set the window"""    
    def setUi(self, win):
        img = Image(Point(512, 363), './ui/mtrFull.png')
        img.draw(win)

        destLabel = Text(Point(1200, 100), "Destination")
        destLabel.draw(win)
        self.destName = Text(Point(1200, 120), "Please pick a destination")
        self.destName.draw(win)

        numLable = Text(Point(1200, 180), "Number of People")
        numLable.draw(win)
        self.numEntry = Entry(Point(1200, 200), 5)
        self.numEntry.draw(win)
        self.numAlert = Text(Point(1200, 220), "Please enter an integer")
        self.numAlert.setTextColor('red')
    
        typeLable = Text(Point(1200, 260), "Customer Type")
        typeLable.draw(win)
        self.typeButton.append(Circle(Point(1150, 275), 3))
        self.typeButton[0].draw(win)
        typeAdultText = Text(Point(1150, 290), "Adult")
        typeAdultText.draw(win)
        self.typeButton.append(Circle(Point(1200, 275), 3))
        self.typeButton[1].draw(win)
        typeChildText = Text(Point(1200, 290), "Child")
        typeChildText.draw(win)
        self.typeButton.append(Circle(Point(1250, 275), 3))
        self.typeButton[2].draw(win)
        typeStudentText = Text(Point(1250, 290), "Student")
        typeStudentText.draw(win)
        self.typeAlert = Text(Point(1200, 310), "Please choose a type")
        self.typeAlert.setTextColor('red')

        tripLable = Text(Point(1200, 350), "How many round trip per day?")
        tripLable.draw(win)
        self.tripButton.append(Circle(Point(1150, 375), 3))
        self.tripButton[0].draw(win)
        tripOneText = Text(Point(1150, 400), "One")
        tripOneText.draw(win)
        self.tripButton.append(Circle(Point(1200, 375), 3))
        self.tripButton[1].draw(win)
        tripTwoText = Text(Point(1200, 400), "Two")
        tripTwoText.draw(win)
        self.tripOtherEntry = Entry(Point(1250, 375), 1)
        self.tripOtherEntry.draw(win)
        tripOtherEntryText = Text(Point(1250, 400), "Other")
        tripOtherEntryText.draw(win)
        self.tripAlert = Text(Point(1200, 420), "Please specify trip number")
        self.tripAlert.setTextColor('red')

        self.buttonAdd = Rectangle(Point(1080, 460), Point(1170, 480))
        self.buttonAdd.setFill('Yellow')
        self.buttonAdd.draw(win)
        textAdd = Text(Point(1125, 470), "Add")
        textAdd.draw(win)

        self.buttonConfirm = Rectangle(Point(1230, 460), Point(1320, 480))
        self.buttonConfirm.setFill('Green')
        self.buttonConfirm.draw(win)
        textConfirm = Text(Point(1275, 470), "Confirm")
        textConfirm.draw(win)
        self.confirmAlert = Text(Point(1200, 490), "Please add people first")
        self.confirmAlert.setTextColor('red')

        homeLabel = Text(Point(1150, 540), "Best Living Place:")
        homeLabel.draw(win)
        self.homeName = Text(Point(1300, 540), "")
        self.homeName.draw(win)
    
        costLabel = Text(Point(1150, 570), "Cost/Day:")
        costLabel.draw(win)
        self.costNum = Text(Point(1300, 570), "")
        self.costNum.draw(win)

        self.addNotation = Text(Point(1200, 590), "Add Successful!")

    """process user mouse click"""
    def run(self):
        while(True):
            click = self.win.getMouse()
            self.addNotation.undraw()
            self.processClick(click.getX(), click.getY())

    """process each mouse click"""
    def processClick(self, x, y):
        if self.processClickDest(x, y):
            pass
        elif self.processClickType(x, y):
            pass
        elif self.processClickTrip(x, y):
            pass
        elif self.processClickAdd(x, y):
            pass
        else:
            self.processClickConfirm(x, y)
            

    """process click for destination"""
    def processClickDest(self, x, y):
        for i in self.stationPosition:
            if self.validClick(x, i[0], y, i[1]):
                self.destName.undraw()
                self.destName.setText(self.stationName[self.stationPosition.index(i)])
                self.destName.setTextColor('black')
                self.destName.draw(self.win)
                self.destChosen = self.stationPosition.index(i)
                return True
        return False

    """prcess click for type choosing"""
    def processClickType(self, x, y):
        for i in self.typeButton:
            center = i.getCenter()
            if self.validClick(x, center.getX(), y, center.getY()):
                for j in self.typeButton:
                    if self.typeButton.index(j) != self.typeButton.index(i):
                        j.undraw()
                        j.setFill('white')
                        j.draw(self.win)
                i.undraw()
                i.setFill('black')
                i.draw(self.win) 
                self.typeChosen = self.typeButton.index(i)
                return True
        return False

    """process the click for round trip chossing"""
    def processClickTrip(self, x, y):
        for i in self.tripButton:
            center = i.getCenter()
            if self.validClick(x, center.getX(), y, center.getY()):
                i.undraw()
                i.setFill('black')
                i.draw(self.win)
                self.tripChosen = self.tripButton.index(i)
                for j in self.tripButton:
                    if self.tripButton.index(j) != self.tripButton.index(i):
                        j.undraw()
                        j.setFill('white')
                        j.draw(self.win)
                self.tripOtherEntry.undraw()
                self.tripOtherEntry.setText('')
                self.tripOtherEntry.draw(self.win)
                return True
        return False

    """process the click for add button"""
    def processClickAdd(self, x, y):
        valid = True
        if self.validClickRange(x, y, 1080, 1170, 460, 480):
            if self.destChosen == -1:
                self.destName.undraw()
                self.destName.setTextColor('red')
                self.destName.draw(self.win)
                valid = False    

            try:
                num = int(self.numEntry.getText())
                self.numAlert.undraw()
            except:
                self.numAlert.undraw()
                self.numAlert.draw(self.win)
                valid = False
                pass

            if self.typeChosen == -1:
                self.typeAlert.undraw()
                self.typeAlert.setTextColor('red')
                self.typeAlert.draw(self.win)
                valid = False 
            else:
                self.typeAlert.undraw()

            try:
                trip = int(self.tripOtherEntry.getText())
                self.tripAlert.undraw()
            except:
                if self.tripChosen != -1:
                    trip = self.tripChosen
                    self.tripAlert.undraw()
                else:
                    valid = False
                    self.tripAlert.undraw()
                    self.tripAlert.draw(self.win)
                pass

            if valid:
                self.record.append((self.destChosen, num, self.typeChosen, trip))
                self.addNotation.draw(self.win)
            return True
        return False

    """process the click for confirm button"""
    def processClickConfirm(self, x, y):
        if len(self.record) == 0:
            self.confirmAlert.undraw()
            self.confirmAlert.draw(self.win)
            return
        self.confirmAlert.undraw()

        if self.validClickRange(x, y, 1230, 1320, 460, 480):
            min = -1
            home = -1
            for i in range(108):
                sum = 0
                for j in self.record:
                    if j[2] == 0:
                        sum += self.priceAdult[i][j[0]] * j[1] * j[3] * 2
                    elif j[2] == 1:
                        sum += self.priceChild[i][j[0]] * j[1] * j[3] * 2
                    else:
                        sum += self.priceStudent[i][j[0]] * j[1] * j[3] * 2
                if min < 0 or sum < min:
                    min = sum
                    home = i
            self.homeName.undraw()
            self.homeName.setText(self.stationName[home])
            self.homeName.draw(self.win)

            self.costNum.undraw()
            self.costNum.setText(str(int(min)))
            self.costNum.draw(self.win)

    """ return the distance between two points"""
    def validClick(self, x1, x2, y1, y2):
        return (abs(x1 - x2) + abs(y1 - y2)) < 20

    """ return whether on point is in certain area"""
    def validClickRange(self, x, y, xMin, xMax, yMin, yMax):
        return xMin < x < xMax and yMin < y < yMax

def main():
    win = Interface("Project", 1500, 726)
    win.run()

if __name__ == '__main__':
    main()
