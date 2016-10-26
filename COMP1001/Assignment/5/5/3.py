def main():

    # Get the message and key for encryption
    inString = input("Please input a text (only English alphabets) to be encrypted: ")
    key = eval(input("Please enter a key (from 1 to 25): "))

    # Change the input characters to lower case
    inString = inString.lower()
    secret = []
    # Encrypt the message with the key
    for token in inString.split():
        for char in token:
            char = chr(((ord(char) + key - 97) % 26) + 97)
            secret.append(char)
        secret.append("$")
    secretMessage = "".join(secret)
    print("The encrypted message is: ", secretMessage[:-1])
                 main()