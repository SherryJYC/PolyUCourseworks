#stringSplit.py
# using the split() function to manipulate strings data.
# Lines that start with '#' are COMMENTS.
# They are not interpreted by Python.
myString = "TIGER, tiger, burning bright\nIn the forests of the night,\nWhat immortal hand or eye\nCould frame thy fearful symmetry?"
print(myString)
#separate word by word
#write your code here
print(myString.replace(",", "").replace("?", "").split())
#separate the string by sentence
#write your code here
print(myString.split('\n'))