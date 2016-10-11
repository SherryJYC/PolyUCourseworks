word = "hi"
myList = ["hello", "hi", "ni hao", "annyong", "bonjour", "ciao"]
i = 0
for p in myList:
    if word == p:
        print("{}".format(i))
        break
    i += 1
