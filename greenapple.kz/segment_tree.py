#!/usr/bin/env python

def build(t, lst, v, tl, tr):
    if tl == tr:
        t[v] = lst[tl]
    else:
        tm = (tl + tr) / 2
        build(t, lst, v * 2, tl, tm)
        build(t, lst, v * 2 + 1, tm + 1, tr)
        t[v] = t[v * 2] + t[v * 2 + 1]


def sum(t, v, tl, tr, l, r):
    if l > r:
        return 0
    if l == tl and r == tr:
        return t[v]
    tm = (tl + tr) / 2
    return sum(t, v * 2, tl, tm, l, min(r, tm)) + sum(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)


def update(t, v, tl, tr, pos, new_val):
    if tl == tr:
        t[v] = new_val
    else:
        tm = (tl + tr) / 2
        if pos <= tm:
            update(t, v * 2, tl, tm, pos, new_val)
        else:
            update(t, v * 2 + 1, tm + 1, tr, pos, new_val)
        t[v] = t[v * 2] + t[v + 1]


def main():
    lst = [4, 3, 7, 10, 4, 6]
    t = [None for i in xrange(len(lst) * 4)]
    build(t, lst, 1, 0, len(lst) - 1)
    print 'lst:', lst
    print 't  :', t


if __name__ == '__main__':
    main()
