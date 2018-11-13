def print_rangoli(N):
    alphabet = list("abcdefghijklmnopqrstuvwxyz")
    for i in range(0, N * 2 - 1):
        string = list('-' * (N * 4 - 3))
        index = N - 1
        for j in range(abs(N * 2 - i * 2 - 2), N * 4 - 3 - abs(N * 2 - i * 2 - 2), 2):
            string[j] = alphabet[abs(index)]
            index -= 1

            if j >= (N - 1) * 2:
                index += 2
        print(''.join(string))

N = int(input())
print_rangoli(N)