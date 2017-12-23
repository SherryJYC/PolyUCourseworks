from subprocess import call, check_output
import glob, os

def file_len(fname):
    with open(fname) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

os.chdir("source")

sources = glob.glob("*.py")
ipt = glob.glob("input.txt")[0]

for source in sources:
    matrix = []
    with open(ipt, 'r') as input_file:
        lines = input_file.readlines()
        for line in lines:
            vector = ""
            miss = []
            line = line.replace("\n", "")
            print(line)
            success = call(["coverage", "run", source, line])
            print("finish")
            output = check_output(["coverage", "report", "-m"])
            coverage = output.decode("utf-8").split('\n')[2]
            items = coverage.split()

            total = file_len(source)

            i = 4
            while i <= len(items) - 1:
                item = items[i].replace(',', '')
                subitem = list(map(int, item.split('-')))
                if len(subitem) > 1:
                    for j in range(subitem[0], subitem[1] + 1):
                        miss.append(j)
                else:
                    miss.append(subitem[0])

                i += 1

            for i in range(1, total + 1):
                if i in miss:
                    vector += "0 "
                else:
                    vector += "1 "
            vector += str(success)
            matrix.append(vector)

        with open(source.replace("py", "txt"), "w+") as output_file:
            for line in matrix:
                output_file.write("%s\n" % line)