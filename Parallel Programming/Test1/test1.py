'''
Calculate a global sum using multiple processes
Trent Scott
'''

import sys
import multiprocessing as mp
from math import ceil



resultsQue = mp.Queue()


def readfile(fname):
    '''Reads a text file; returns a list of integers'''
    f = open(fname, 'r')
    contents = f.read()
    numbers = contents.split()
    for i in range(len(numbers)):
        numbers[i] = int(numbers[i])
    return numbers

def subtotal(numsToAdd, resultsQue):
    resultsQue.put(sum(numsToAdd))
    return

def main(num_processes):
    fname = "randnums.txt"
    numList = readfile(fname)  #numlist is a list of integers

    numsToGo = len(numList)

    processes = []
    numsToCalculate = []
    for i in range(num_processes):
        oneCPU = ceil(len(numList)/num_processes)

        if (oneCPU < numsToGo):
            numsInCore = oneCPU
            numsToCalculate.append(numList[0:oneCPU])
            numList = numList[oneCPU:] #pop out a list
            numsToGo -= oneCPU
        else:
            numsInCore = numsToGo
            numsToCalculate.append(numList[0:])
            numsToGo = 0
        p = mp.Process(target=subtotal, args=(numsToCalculate[i], resultsQue))
        processes.append(p)

    for k in range(len(processes)):
        processes[k].start()
    for l in range(len(processes)):
        processes[l].join()

    results = []
    for m in range(num_processes):
        results.append(resultsQue.get())

    print(sum(results))


if __name__ == "__main__":
    num_proc = int(sys.argv[1])
    main(num_proc)
    

