def count_char(input_string, char):
    return input_string.count(char)

def count_all_letters(input_string):
    for i in range(26):
        print("The number of " + chr(i + 65) + " or " +
              chr(i + 97) + " is " + str(count_char(input_string, chr(i + 65)) +
                                         count_char(input_string, chr(i + 97))))


def main():
    string = input("Please enter a string: ")
    count_all_letters(string)


if __name__ == '__main__':
    main()