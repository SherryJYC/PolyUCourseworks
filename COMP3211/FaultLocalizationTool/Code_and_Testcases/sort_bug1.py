import argparse
def naive_sort_process(c, d, e, f):
    if (c >= d):
        if (d >= e):
            if (e >= f):
                return [c, d, e, f]
            elif (d >= f):
                return [c, d, f, e]
            elif (c >= f):
                return [f, c, d, e]
            else:
                return [f, c, d, e]
        else:
            if (e >= f):
                if (d >= f):
                    if (c >= e):
                        return [c, e, d, f]
                    else:
                        return [e, c, d, f]
                else:
                    if (c >= e):
                        return [c, e, f, d]
                    else:
                        if (c >= f):
                            return [e, c, f, d]
                        else:
                            return [e, f, c, d]
            else:
                if (c >= f):
                    return [c, f, e, d]
                else:
                    if (c >= e):
                        return [f, c, e, d]
                    else:
                        return [f, e, c, d]
    else:
        if (c >= e):
            if (e >= f):
                return [d, c, e, f]
            elif (c >= f):
                return [d, c, f, e]
            elif (d >= f):
                return [d, f, c, e]
            else:
                return [f, d, c, e]
        else:
            if (e >= f):
                if (c >= f):
                    if (d >= e):
                        return [d, e, c, f]
                    else:
                        return [e, d, c, f]
                else:
                    if (d >= e):
                        return [d, e, f, c]
                    else:
                        if (d >= f):
                            return [e, d, f, c]
                        else:
                            return [e, f, d, c]
            else:
                if (d >= f):
                    return [d, f, e, c]
                else:
                    if (d >= e):
                        return [f, d, e, c]
                    else:
                        return [f, e, d, c]

def naive_sort(c, d, e, f):
    a = naive_sort_process(c, d, e, f)
    array=[c,d,e,f]
    result = []
    for j in range(4):
        temp=array[0]
        location = 0
        for i in range(len(array)):
            if array[i] >= temp:
                temp = array[i]
                location = i
        result.append(temp)
        del array[location]
    if a==result:
        exit(1)
    else:
        exit(0)

parser = argparse.ArgumentParser()
parser.add_argument('input')
args= parser.parse_args()
string=args.input.split(",")
naive_sort(int(string[0]),int(string[1]),int(string[2]),int(string[3]))