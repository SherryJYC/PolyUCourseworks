from __future__ import division
import sys


def cal_datalist(l, size):
    data_list = [None] * size
    for k in range(size):
        data_list[k] = [0] * 4
    for item in l:
        i = 0
        flag = int(item[-1])
        for data in item:
            if i >= size:
                break
            data = int(data)
            if flag == 1 and data == 1:
                data_list[i][0] += 1 #successful pass
            elif flag == 1 and data == 0:
                data_list[i][1] += 1 #successful no pass
            elif flag == 0 and data == 1:
                data_list[i][2] += 1 #unsccessful pass
            elif flag == 0 and data == 0:
                data_list[i][3] += 1
            i += 1
    return data_list

def cal_susp(data_list):
    susp_list = []
    for data in data_list:
        total_passed = data[0] + data[1]
        total_failed = data[2] + data[3]
        passed = data[0]
        failed = data[2]
        if failed == 0:
            susp_list.append(0)
            continue
        if passed == 0:
            susp_list.append(1)
            continue
        under = (passed/total_passed) + (failed/total_failed)
        #print(under)
        hue = (passed/total_passed)/ under
        susp = 1 - hue
        susp_list.append(susp)
    return susp_list

l = []
size = 0
for lines in sys.stdin:
    line = lines.split()
    size = len(line) - 1
    l.append(line)
susp_list = cal_susp(cal_datalist(l,size))
rank = sorted(range(len(susp_list)), key=lambda k: susp_list[k])
rank = [x+1 for x in rank]
print(rank[::-1])
