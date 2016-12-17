import random as rd
legislators = { "Tsang Yok-sing" : "DAB", "Albert Ho" : "Democratic", "Lee Cheuk-yan" :
"Labour", "James To" : "Democratic", "Chan Kam-lam" : "DAB", "Lau Wong-fat" : "Economic Synergy", "Emily Lau" : "Democratic" }
# Complete the following programming statement.
# We want it to give us a list of all the
# legislators¡¯ names
names = list(legislators.keys())
# Complete the following programming statement.
# We want it to give us a list of all the political parties
parties = list(legislators.values())
# We will generate 5 True/False questions
numberCorrect = 0
for i in range(5):
    # randomly choose one legislator's name
    # randomly choose one party
    # Ask the user a T/F question. Store the answer in ans
    i1 = rd.randint(0, len(legislators) - 1)
    i2 = rd.randint(0, len(legislators) - 1)
    name = names[i1]
    party = parties[i2]
    ans = input("Does " + name + " belong to " + party + " (Y/N)?")
    # Write programming statements to check if ans is correct.
    # That is, if the name and the party match
    # You may assume the user will always type in 'Y or 'N''
    # Also count the number of times the user was right
    if (i1 == i2 and ans == 'Y') or (i1 != i2 and ans == 'N'):
        print("Correct!")
        numberCorrect += 1
    else:
        print("You are incorrect!")
print("You were correct " + str(numberCorrect) + " times out of 5!")
