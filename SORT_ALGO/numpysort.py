import numpy as np
import sys
import datetime

file_name = str(sys.argv[1])
with open(file_name, "r") as raw:
    for line in raw.readlines():
        data = [float(i) for i in line.split(" ") if i.strip()]

    staTime = datetime.datetime.now()
    np.sort(data)
    endTime = datetime.datetime.now()
    exeTime = int((endTime - staTime).total_seconds() * 1000)
    i = 0
    while file_name[i] != 'i':
        i += 1
    print(file_name[i:] + ": " + str(exeTime) + '|')
