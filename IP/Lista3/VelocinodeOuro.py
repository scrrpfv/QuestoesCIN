informacoes_deuses = [
    ['Zeus', 'Poseidon', 'Atenas', 'Ares', 'Afrodite'],
    [100, 90, 80, 70, 60],
    ['Raio', 'Tridente', 'Égide', 'Lança', 'Cinto Mágico']
]

numero = input()
c = 0

for i in numero:
    num = int(i)
    if num == 2 or num == 4:
        d = 'Deusa'
    else:
        d = 'Deus'
    print(f'{d}:{informacoes_deuses[0][num]}')
    print(f'Poder:{informacoes_deuses[1][num]}')
    print(f'Artefato:{informacoes_deuses[2][num]}')
    c += 1
    if c != len(numero):
        print('')