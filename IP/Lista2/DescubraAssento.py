N = int(input())
assento = 1
for i in range(N):
    musica = input().lower()
    soma = 0
    for letra in musica:
        if letra == "a" or letra == "e" or letra == "i" or letra == "o" or letra == "u":
            soma += 1
        else:
            soma += 2
    assento *= soma
print(f"Parabéns por adquirir o ingresso! Seu assento é o {assento}, estamos ansiosos para vê-lo, vai ser incrível!")