from graphics import *
import random as rd
import time

def main():
    win = GraphWin("Racing CIrcles", 1000, 300)

    randomR = rd.randint(150, 800)
    randomG = rd.randint(150, 800)

    rPosition = 50
    gPosition = 50
    circleR = Circle(Point(rPosition, 80), 50)
    circleG = Circle(Point(gPosition, 220), 50)
    circleR.setFill('Red')
    circleG.setFill('Green')
    circleR.draw(win)
    circleG.draw(win)

    rectR = Rectangle(Point(randomR, 30), Point(randomR + 30, 130))
    rectG = Rectangle(Point(randomG, 170), Point(randomG + 30, 270))
    rectR.setFill('Yellow')
    rectG.setFill('Yellow')
    rectR.draw(win)
    rectG.draw(win)

    t0 = Text(Point(450, 290), "Click to run!")
    t0.draw(win)

    win.getMouse()
        
    while(True):
        time.sleep(0.01)
        randR = rd.randint(0, 4)
        randG = rd.randint(0, 4)
        circleR.move(randR, 0)
        circleG.move(randG, 0)
        rPosition += randR
        gPosition += randG
        if (rPosition >= 950 and gPosition >= 950):
            t0.undraw()
            t = Text(Point(450, 290), "Both player arrived at the same time! It is a draw!")
            t.draw(win)
            break
        elif (rPosition >= 950):
            t0.undraw()
            t = Text(Point(450, 290), "Red player wins!")
            t.draw(win)
            break
        elif (gPosition >= 950):
            t0.undraw()
            t = Text(Point(450, 290), "Green player wins!")
            t.draw(win)
            break

if __name__ == "__main__":
    main()
    
