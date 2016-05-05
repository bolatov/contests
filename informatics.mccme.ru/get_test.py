#!/usr/bin/python env

import random
import sys
import string

def generate():
    with open('input.txt', 'w') as f:
        N = 999 #random.randint(1,20)
        M = 999
        f.write(str(N) +' '+ str(M) + '\n')
        for i in xrange(N):
            for j in xrange(M):
                if i == 0 or i == N-1 or j == 0 or j == M-1:
                    f.write('1 ')
                else:
                    f.write('0 ')
            f.write('\n')

if __name__ == '__main__':
    generate()