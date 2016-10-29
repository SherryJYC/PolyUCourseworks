"""This is a module that enables user to encrypt and decrypt a string.
The user must provide a string and stored the random generated key"""
import random

"""Return a random key"""
def getKey():
    return int(random.randint(1, 25))

"""Get the input text from the user"""
def getText():
    str = input("Please input a string")

"""Return the encrypted string
given a string and a key"""
def encrypt(inString, key):
    return __help(inString, key, ' ', "$")

"""Return the original string
given a encrypted string and a key""" 
def decrypt(inString, key):
    key = 0 - key
    return __help(inString, key, "$", ' ')


def __help(inString, key, symbol1, symbol2):
    # Get the message and key for encryption

    # Change the input characters to lower case
    inString = inString.lower()
    secret = []
    # Encrypt the message with the key
    for token in inString.split(symbol1):
        for char in token:
            if 97 <= ord(char) < 97 + 26:
                char = chr(((ord(char) + key - 97) % 26) + 97)
            secret.append(char)
        secret.append(symbol2)
    secret.pop()
    secretMessage = "".join(secret)
    return secretMessage

"""Given a string and a key
verify whether the string is the same after encrypt and decrypt operations"""
def verify(inString, key):
    return inString.lower() == decrypt(encrypt(inString, key), key)

"""Return whether the encrypt/dectypt functions work correctly
Also print the result"""
def test():
    str1 = "I am a novice problem-solver."
    str2 = "I am an intermediate problem-solver."
    str3 = "I am an advanced problem-solver."
    key1 = getKey()
    key2 = getKey()
    key3 = getKey()
    if verify(str1, key1) and verify(str2, key2) and verify(str3, key3):
        print("Test result: the encrypt/dectypt functions work properly.")
        return True
    else:
        print("Test result: the encrypt/dectypt functions do not work properly.")
        return False 


if __name__ == "__main__":
    print(str(test()))

 
