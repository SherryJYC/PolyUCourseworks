# months.py
# Print the 3-letter abbreviation for a given month
months = "JanFebMarAprMayJunJulAugSepOctNovDec"
monthNum = 3
# the rest of your programming statements goes here:
# month.py
# A program to print the abbreviation of a month, given its number
def main():
# months is used as a lookup table
# compute starting position of month n in months
# Grab the appropriate slice from months
# print the result
    monthAbbrev = months[monthNum * 3 : monthNum * 3 + 3]
    print("The month abbreviation is", monthAbbrev + ".")

if __name__ == "__main__":
    main()