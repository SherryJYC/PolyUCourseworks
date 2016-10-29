from graphics import *

def main():
    str1 = input("Input the width and height of the window: ")
    str2 = input("Input 5 colors of the circle: ")
    wh = str1.split()
    width = int(wh[0])
    height = int(wh[1])
    colors = str2.split()
    colors.reverse()
    set = 2
    center = Point(width/2, height/2)
    maxD = width
    if (height < maxD):
        maxD = height
    maxD /= 2
    win = GraphWin("Target Board", width, height)
    for i in range(10):
        circ = Circle(center, (maxD / 10 * (10 - i)))
        circ.setFill(colors[i // 2])
        circ.draw(win)

if __name__ == "__main__":
    main()
