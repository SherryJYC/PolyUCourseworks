# ACT2-2 functions.

# Lines that start with '#' are COMMENTS.
# They are not interpreted by Python.

# Step 1: Make a variable called fileName, and assign it the name of the file
fileName = "tiger.txt"


# Step 2: Open the file whose name is saved in fileName
inFile = open(fileName)


# Step 3: Read in the contents of the file into a string called fileString
fileString = inFile.read()


# Step 4: Close the file
inFile.close()

# Step 5: Split the file so that we can count the number of words
# Hint: You will need to use the split command
list = fileString.split()
print("The list is: " + str(list))
print("The number of words is: " + str(len(list)))

# Step 6: Split the file so that we can count the number of sentence
# Hint: You will need to use split with a delimiter
list2 = fileString.split('\n')
print("The list is: " + str(list2))
print("The number of rows is: " + str(len(list2)))