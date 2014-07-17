#!/usr/bin/python env

import random as rd
import sys

def generate_tests(T, N):
    f = open('input.txt', 'w')
    f.write(str(T))
    f.write('\n')

    for itest in range(T):
        N = rd.randint(1, N)
        f.write(str(N))
        f.write('\n')

        arr = []
        for i in range(0, N):
            arr.append(i+1)
        rd.shuffle(arr)

        for i in arr:
            f.write(str(i))
            f.write(' ')

        f.write('\n')

    f.close()

if __name__ == '__main__':
    T = int(sys.argv[1]) # Number of test cases
    N = int(sys.argv[2]) # Upper limit for N
    generate_tests(T, N)

'''
to run the script:
    python sgarden_gen.py 5 100
'''
