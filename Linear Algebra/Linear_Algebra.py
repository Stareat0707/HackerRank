import numpy

N = int(input())
A = list()

for i in range(0, N):
    A.insert(i, list(map(float, input().split())))

numpy.set_printoptions(legacy="1.13")
print(numpy.linalg.det(A))