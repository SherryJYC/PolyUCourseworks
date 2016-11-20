# lab ex5
# Name: <your name here>
# StudentID: <Your studentID here>

# from http://gizmodo.com/the-25-most-popular-passwords-of-2014-were-all-doomed-1680596951
passwordDictionary = {'Alice':'password',
                      'Bob': '123456',
                      'Carol':'12345678',
                      'Deb':'qwerty',
                      'Emma':'abc123',
                      'Florence':'letmein',
                      'Gary':'trustno1',
                      'Hillary':'dragon',
                      'Ingrid':'baseball',
                      'Jeremy':'111111',
                      'Kyle':'monkey',
                      'Lou':'mustang',
                      'Mary':'696969',
                      'Ned':'master',
                      'Owen':'batman',
                      'Pat':'passw0rd',
                      'Quintin':'shadow',
                      'Ryan':'123123',
                      'Sandra':'1234567',
                      'Trevor':'superman',
                      'Uma':'qazwsx',
                      'Valerie':'michael',
                      'Wilbur':'football'}


# Prints the dictionary key-value pairs from a dictionary.
# What is the difference between sorted() and myList.sort()? Your answer here:
# first one returns a new list and second one is in-place sorting
def printDictionary(dictionary):
    #write the code here
    print(str(dictionary))

    
# Adds the (key,value) pair to the dictionary and returns the new dictionary
# will need you to modify this function
def addPassword(dictionary,key,value):
    print('Warning, overwriting an existing password!')
    dictionary[key] = value
     
# Adds a new "user" to the password list
# Complete this function
def addUser(dictionary):
    print("This function is supposed to add a new user/password pair to the dictionary. Finish it!")
    # 1. Get the user input from the dictionary using input()
    user = input("Input the user name")
    # 2. Call addPassword to add the user and his/her password
    password = input("Input the password")
    addPassword(dictionary, user, password)
    # 3. Print a feedback message to the user
    print("Added!")
    # 4. Return the dictionary
    return dictionary

# Update Corrects a user's name in the dictionary
def updateUserName(dictionary):
	# 1. Ask the user for the old name (that needs to be updated.)
    oldName = input("Input old name:")
	# 2. Check the dictionary for the old key -- if it doesn't exist, print a warning message
    if not oldName in dictionary:
        print("The name does not exist")
        return
	# 3. If it does exist, 
	#      (a) call addPassword to insert the new name into the dictionary as a new key 
	#          but with the same password 
	#      (b) Remove the old key from the dictionary
    newName = input("Input new name:")
    dictionary[newName] = dictionary.get(oldName)
    dictionary.remove(oldName)
	# 4. Return the dictionary
	# (These is just a very basic outline.)
    return dictionary

#######################################################################################
# Non-Function Programming Code


# Print out the initial dictionary
#write a statement to print the dictionary
 
# Add a user
#write a statement to call add user function


# Print out the dictionary again so we can check if it updated properly
#write a function to check the updated dictionary
 
# Update a user's name
#write a statement to call updated function
 
# Print out the dictionary again for checking.
 #write a function to updated the dictionary