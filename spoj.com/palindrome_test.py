#!/usr/bin/python env

import random as rd

def generate():
    MAX = 10000
    with open('input.txt', 'w') as f:
        T = rd.randint(1,1000)
        f.write(str(T))
        f.write('\n')

        for i in range(T):
            N = rd.randint(1,MAX)
            f.write(str(N))
            f.write('\n')

if __name__ == '__main__':
    generate()