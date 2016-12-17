#First, use a list to record the roof height for each segment. i.e. list[i] record the roof height in segment [i-1, i]
#    Detail: initial the list to all zero. Then traversal the input and update the height of each segments to its 
#    highest value
#Second, traversal the list to draw all roofs. If any two neighbor roofs have a difference in hight, just add a 
#    vertical line to represent the wall. 

from graphics import *

input = [[1, 5, 11],
        [2, 7, 6],
        [3, 9, 13],
        [12, 16, 7],
        [14, 25, 3],
        [19, 22, 18],
        [23, 29, 13],
        [24, 28, 4]]

def draw(intput):
    max = 0
    for i in input:
        if i[1] > max:
            max = i[1]

    outline = [0] * (max + 2)

    for i in input:
        left = i[0]
        right = i[1]
        height = i[2]
        for j in range(left + 1, right + 1):
            if outline[j] < height:
                outline[j] = height

    win = GraphWin("Buildings", 1000, 400)
    line = Line(Point(0, 380), Point(1000, 380))
    line.draw(win)

    #mark roofs
    for i in range(20):
        text = i * 5
        number = i * 50
        index = Text(Point(number, 390), str(text))
        index.setSize(5)
        index.draw(win) 

    #draw
    for pre in range(0, max + 1):
        cur = pre + 1
        line = Line(Point(10 * pre, 400 - 10 * outline[cur] - 20), Point(10 * cur, 400 - 10 * outline[cur] - 20))
        line.draw(win)
        line = Line(Point(10 * cur, 400 - 10 * outline[cur] - 20), Point(10 * cur, 400 - 10 * outline[cur + 1] - 20))
        line.draw(win)

def main():
    draw(input)

if __name__ == '__main__':
    main()