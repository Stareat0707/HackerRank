import numpy

P = tuple(map(float, input().split()))
x = int(input())

print(numpy.polyval(P, x))