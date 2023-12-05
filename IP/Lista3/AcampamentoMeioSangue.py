M = int(input()); N = int(input())

matrix = []
for i in range(M):
    line = []
    for j in range(N):
        line.append(input())
    matrix.append(line)

max = 0; c = 1; pos = 0
for line in matrix:
    print(" ".join(line))
    sum = 0
    for value in line:
        sum += int(value)
    if sum > max:
        max = sum
        pos = c
    c += 1

print('')
print(f'O chalé {pos} foi o que mais recebeu semi-deuses, tendo um acréscimo de {max} novos campistas!')