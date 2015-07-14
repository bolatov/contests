#!/usr/bin/python env

import random
import sys

def generate():
    f = open('input.txt', 'w')
    T = 100
    f.write(str(T))
    f.write('\n')
    for i in range(T):
        f.write('2 1000000 1\n')
    f.close()

if __name__ == '__main__':
    generate()