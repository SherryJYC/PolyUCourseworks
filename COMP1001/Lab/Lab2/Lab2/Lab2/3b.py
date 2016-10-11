myStr = "The Hong Kong Polytechnic University"
str2 = "gnok"
str2 = str2[::-1]
for i in range(len(myStr)):
    if str2 == myStr[i:i+len(str2)]:
        print("Yes")
        break
else:
    print("No")