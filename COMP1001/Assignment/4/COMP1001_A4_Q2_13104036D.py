def count_char(input_string, char):
    return input_string.count(char)
    

def main():
    string = input("Please enter a string: ")
    char = input("Please enter a character: ")
    print("The number of " + char + " in the input string '" + string + "' is " + str(count_char(string, char)))


if __name__ == '__main__':
    main()