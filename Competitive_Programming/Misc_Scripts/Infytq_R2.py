import math
from collections import Counter


def frequency_sort(a):
    f = Counter(a)
    a.sort(key=lambda x: (-f[x], x))
    return a


m = int(input())
p = int(input())

inmatrix1 = []
for i in range(m):
    inp = [int(x) for x in input().split()]
    n = len(inp)
    inmatrix1.append(inp)

inmatrix2 = []
for i in range(p):
    inp = [int(x) for x in input().split()]
    q = len(inp)
    inmatrix2.append(inp)


outmatrix = inmatrix1


def valid(i, j):
    return (i >= 0 and i < p) and (j >= 0 and j < q)


for r1 in range(m):
    for c1 in range(n):
        store = []

        if (valid(r1, c1)):
            store.append(inmatrix1[r1][c1]*inmatrix2[r1][c1])

        if (valid(r1, r1)):
            store.append(inmatrix1[r1][c1]*inmatrix2[r1][r1])

        if (valid(c1, r1)):
            store.append(inmatrix1[r1][c1]*inmatrix2[c1][r1])

        if (valid(c1, c1)):
            store.append(inmatrix1[r1][c1]*inmatrix2[c1][c1])

        if (len(store) == 0):
            outmatrix[r1][c1] = -1
        else:
            result = frequency_sort(store)
            outmatrix[r1][c1] = result[0]

for row in range(len(outmatrix)):
    for i in outmatrix[row]:
        print(i, end=" ")

    if (row != len(outmatrix)-1):
        print()
