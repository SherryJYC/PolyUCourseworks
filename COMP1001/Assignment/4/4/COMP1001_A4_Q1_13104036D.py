def list_sym(max, sym):
    res = []
    for i in range(max):
        res.append(sym * (i + 1))
    return res
    

def main():
    symbol = input("Please enter a symbol: ")
    num = int(input("Please enter the maximun number of symbols: "))
    res = list_sym(num, symbol)
    print(res)


if __name__ == '__main__':
    main()