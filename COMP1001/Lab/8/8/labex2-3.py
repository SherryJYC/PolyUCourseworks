#lab exercise
# Original string, with no punctuation.
origString = 'The cat had a hat The cat sat on the hat'

# Word frequency dictionary.
freqDict = {'the':3,'cat':2,'had':1,'a':1,'hat':2,'sat':1,'on':1}

# Phone number dictionary.
phoneDict = {'PolyU': '2766-5111',
             'COMP':'2766-7200',
             'CY':'2878-3300',
             'LegCo':'3919-3333'}

# Takes a dictionary as input and prints the key-value pairs. Returns nothing.
#ex2-(b)-i
def printDict(dictionary):
    print(str(myList))
# Takes a list as input and prints the values.  Returns nothing.
#ex2-(b)-ii
def printList(myList):
    print(str(myList))


# Takes a string and returns a dictionary of word frequencies
# e.g. if we give it origString, it should return something that's like freqDict
#ex3
def wordFreq(myString):
    myList = myString.split()
    myDict = {}
    for i in myList:
        if not i in myDict:
            myDict[i] = 1
        else:
            myDict[i] += 1
    return myDict

