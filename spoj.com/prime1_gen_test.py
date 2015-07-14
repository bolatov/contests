#!/usr/bin/python env

import sys
import random as rd

def generate():
    MAX = 1000000000
    with open('input.txt', 'w') as f:
        T = rd.randint(1,10)
        f.write(str(T))
        f.write('\n')

        for i in range(T):
            M = rd.randint(1,MAX)
            if M - 100000 > 0:
                N = M-100000
                print '1.M: %d, N: %d' % (N, M)
                f.write(str(N))
                f.write(' ')
                f.write(str(M))
            else:
                f.write(str(M))
                f.write(' ')
                N = M+100000
                print '2.M: %d, N: %d' % (M, N)
                f.write(str(N))
            f.write('\n')

if __name__ == '__main__':
    generate()