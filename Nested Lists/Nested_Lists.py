N = int(input())

students = list()

for i in range(0, N):
    name = input()
    grade = float(input())
    students.append([name, grade])

students.sort(key=lambda student: (student[1], student[0]))

lowest = students[0][1]
for i in range(1, len(students)):
    if students[i][1] != students[i - 1][1]:
        lowest = students[i][1]
        while students[i][1] == lowest:
            print(students[i][0])
            i += 1
        break