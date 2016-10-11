 # Converts a date in form "mm/dd/yyyy" to "month day, year"
def main():
# get the date
# split into components
# convert monthStr to the month name
# output result in month day, year format
    str = input("Please enter day, month, and year numbers: ")
    res1 = str.replace(",", "/")
    res2 = str.split(",")
    months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
    print("The date is {} or {} {}, {}".format(res1, months[int(res2[0] - 1)], res2[1], res2[2]))

if __name__ == "__main__":
    main()

