#!/usr/bin/python env

import random
import sys

def generate():
    f = open('input.txt', 'w')
    f.write('100000 100000\n')
        
    n = 100000

    # A
    for i in range(n):
        f.write(str(1) + ' ')
    f.write('\n')

    # B
    for i in range(n):
        f.write(str(1) + ' ')
    f.write('\n')

    # C
    for i in range(n):
        f.write(str(3) + ' ')
    f.write('\n')
        
    f.close()

if __name__ == '__main__':
    generate()