#!/usr/bin/python env

import random
import sys

def generate():
    f = open('input.txt', 'w')
    T = 15
    f.write(str(T) + '\n')
    N = 100

    for i in range(T):
        f.write(str(N) + '\n')

        arr = []
        for i in range(N):
            arr.append(i+1)
        
        random.shuffle(arr)
        
        for i in arr:
            f.write(str(i) + ' ')
        f.write('\n')
    f.close()

if __name__ == '__main__':
    generate()