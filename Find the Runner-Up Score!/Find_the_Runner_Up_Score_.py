n = int(input())

A = set(map(int, input().split()))

l = list(A)

l.sort()

print(l[-2])