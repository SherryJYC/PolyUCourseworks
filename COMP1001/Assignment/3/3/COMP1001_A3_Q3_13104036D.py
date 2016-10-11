
fn = input("Please enter your first name: ")
ln = input("Please enter your last name: ")
n = fn + " " + ln
for i in range(2 * len(n) - 1):
    print(n[:len(n) - abs((len(n) - 1) - i)])