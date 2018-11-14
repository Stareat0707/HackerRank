X = int(input())
Y = int(input())
Z = int(input())
N = int(input())

answer = list()

for i in range(0, X + 1):
    for j in range(0, Y + 1):
        for k in range(0, Z + 1):
            if i + j + k != N:
                answer.append([i, j, k])

print(answer)