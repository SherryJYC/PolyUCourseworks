def main():
    print("!!!The number of space per item includes the number of digits in that item, according to th example in assignment description!!!")
    print("!!!Please make sure the number of space per item is larger than or equal to the maximum number of digits in each item!!!")

    first = input("Please enter a starting number and an ending number: ").split(",")
    start = int(first[0].strip())
    end = int(first[1].strip())
    print(start + end)
    second = input("Please enter the number of numbers printed on a row and the number of spaces per item:").split(",")
    row = int(second[0].strip())
    space = int(second[1].strip())

    cur = start
    count = 0
    print("---------------------------------------------")
    print("Your print-out of numbers " + str(start) + "-" + str(end) + " using " + str(row) + " columns and " + str(space) + " spaces between numbers:")
    while (True):
        digitNum = len(str(cur))
        print(" " * (space - digitNum) + str(cur), end = "")
        cur += 1
        count += 1
        if (cur > end):
            break
        if (count % row == 0):
            print("")
        




if __name__ == "__main__":
    main()