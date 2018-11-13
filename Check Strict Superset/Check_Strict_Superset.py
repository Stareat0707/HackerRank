A = set(map(int, input().split()))
n = int(input())

otherSets = list()

for i in range(0, n):
    otherSet = set(map(int, input().split()))
    otherSets.insert(i, otherSet)

for otherSet in otherSets:
    if otherSet.issubset(A) == False:
        print(False)
        exit()

print(True)