#!/usr/bin/python env

import random
import sys

def generate():
    f = open('input.txt', 'w')
    T = 200
    f.write(str(T) + '\n')
    for i in range(T):
        a = random.randint(0,1e5)
        b = random.randint(a+1, 1e5)
        f.write(str(a) +' '+ str(b) +'\n')
    f.close()

if __name__ == '__main__':
    generate()