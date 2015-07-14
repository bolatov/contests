#!/usr/bin/python env

import random
import sys
import string

def generate():
    f = open('input.txt', 'w')
    T = 100
    f.write(str(T) + '\n')

    for i in range(T):
        N = random.randint(1,20)
        f.write(str(N) + '\n')
        words = set()
        while len(words) < N:
            w = ''.join(random.SystemRandom().choice(string.lowercase) for _ in xrange(10))
            if not w in words:
                words.add(w)
                f.write(w + '\n')
    f.close()

if __name__ == '__main__':
    generate()