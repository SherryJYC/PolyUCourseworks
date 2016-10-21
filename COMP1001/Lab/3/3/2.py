def sort2d(a,b):
    temp = 0
    if (a < b):
            temp = a;
            a = b;
            b = temp;
    return a, b

def sort3d(a, b, c):
    a, b = sort2d(a, b)
    b, c = sort2d(b, c)
    a, b = sort2d(a, b)
    print(a, b, c)

def main():
    sort3d(5,4,7)

if __name__ == "__main__":
    main()