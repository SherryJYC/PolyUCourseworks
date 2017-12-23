'''***I love COMP3211***'''
import random
import argparse

def encrypt(inString):
    inString = inString.lower()
    secret = []
    for char in inString:
        if ord(char) == 97:
            char = chr(97 + random.randint(16, 16))
        elif ord(char) == 98:
            char = chr(98 + random.randint(21, 21))
        elif ord(char) == 99:
            char = chr(99 + random.randint(2, 2))
        elif ord(char) == 100 or ord(char) == 103:
            char = chr(ord(char) + random.randint(14, 14))
        elif ord(char) == 101:
            char = chr(101 + random.randint(15, 15))
        elif ord(char) == 102:
            char = chr(102 + random.randint(19, 19))
        elif ord(char) == 104:
            char = chr(104 + random.randint(1, 1))
        elif ord(char) == 105 or ord(char) == 106:
            char = chr(ord(char) + random.randint(6, 6))
        elif ord(char) == 107:
            char = chr(107 + random.randint(-10, -10))
        elif ord(char) == 108:
            char = chr(108 + random.randint(7, 7))
        elif ord(char) == 109:
            char = chr(109 + random.randint(-9, -9))
        elif ord(char) >= 110 and ord(char)<=112:
            char = chr(ord(char) + random.randint(-8, -8))
        elif ord(char) >= 113 and ord(char)<=115:
            char = chr(ord(char) + random.randint(-7, -7))
        elif ord(char) == 116:
            char = chr(116 + random.randint(6, 6))
        elif ord(char) == 117:
            char = chr(117 + random.randint(3, 3))
        elif ord(char) == 118:
            char = chr(118 + random.randint(-19, -19))
        elif ord(char) == 119:
            char = chr(119 + random.randint(-1, -1))
        elif ord(char) == 120:
            char = chr(120 + random.randint(-22, -22))
        elif ord(char) == 121:
            char = chr(121 + random.randint(-11, -11))
        elif ord(char) == 122:
            char = chr(122 + random.randint(-13, -13))
        else:
            char = ' '
        secret.append(char)
    secretMessage = "".join(secret)
    return secretMessage


def decrypt(inString):
    inString = inString.lower()
    secret = []
    for char in inString:
        if ord(char) == 97:
            char = chr(97 + random.randint(10, 10))
        elif ord(char) == 98:
            char = chr(98 + random.randint(22, 22))
        elif ord(char) == 99:
            char = chr(99 + random.randint(19, 19))
        elif ord(char) == 100:
            char = chr(100 + random.randint(9, 9))
        elif ord(char) == 101:
            char = chr(101 + random.randint(-2, -2))
        elif ord(char) == 102:
            char = chr(102 + random.randint(8, 8))
        elif ord(char) == 103:
            char = chr(103 + random.randint(8, 8))
        elif ord(char) == 104:
            char = chr(104 + random.randint(8, 8))
        elif ord(char) == 105:
            char = chr(105 + random.randint(-1, -1))
        elif ord(char) == 106:
            char = chr(106 + random.randint(7, 7))
        elif ord(char) == 107:
            char = chr(107 + random.randint(7, 7))
        elif ord(char) == 108:
            char = chr(108 + random.randint(7, 7))
        elif ord(char) == 109:
            char = chr(109 + random.randint(13, 13))
        elif ord(char) == 117:
            char = chr(117 + random.randint(-14, -14))
        elif ord(char) == 114:
            char = chr(114 + random.randint(-14, -14))
        elif ord(char) == 115:
            char = chr(115 + random.randint(-7, -7))
        elif ord(char) == 118:
            char = chr(118 + random.randint(1, 1))
        elif ord(char) == 119:
            char = chr(119 + random.randint(-21, -21))
        elif ord(char) == 120:
            char = chr(120 + random.randint(-3, -3))
        elif ord(char) == 121:
            char = chr(121 + random.randint(-19, -19))
        elif ord(char) == 122:
            char = chr(122 + random.randint(-6, -6))
        elif ord(char) == 110:
            char = chr(110 + random.randint(11, 11))
        elif ord(char) == 111:
            char = chr(111 + random.randint(-6, -6))
        elif ord(char) == 112:
            char = chr(112 + random.randint(-6, -6))
        elif ord(char) == 113:
            char = chr(113 + random.randint(-16, -16))
        elif ord(char) == 116:
            char = chr(116 + random.randint(-15, -15))
        else:
            char = char
        secret.append(char)
    secretMessage = "".join(secret)
    return secretMessage

def verify(a):
    if (decrypt(encrypt(a)) == a):
        exit(1)
    else:
        exit(0)

parser = argparse.ArgumentParser()
parser.add_argument('input')
args= parser.parse_args()
string=args.input
verify(string)