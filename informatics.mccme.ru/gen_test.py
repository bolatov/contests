#!/usr/bin/python env

import random
import sys
import string

def generate():
    with open('input.txt', 'w') as f:
        N = 100000 #random.randint(1,20)
        M = 100000
        f.write(str(N) +' '+ str(M) + '\n')
        for i in xrange(N):
            for j in xrange(i + 1, M):
                if i != j:
                    f.write(str(i + 1) + ' ' + str(j + 1) + '\n')
            f.write('\n')

if __name__ == '__main__':
    generate()