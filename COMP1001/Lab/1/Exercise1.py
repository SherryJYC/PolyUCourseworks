name = input("Please input your name: ")
score = eval(input("Please input your score: "))

if score >= 75:
    grade = 'A'
elif 65 <= score < 75:
    grade = 'B'
elif 55 <= score < 65:
    grade = 'C'
elif 45 <= score < 55:
    grade = 'D'
else:
    grade = 'F'

print(name + "'s grade is " + grade)
if grade == 'A':
    print("Congratulations! You got an A!")