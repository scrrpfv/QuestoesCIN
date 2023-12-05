linie = input()
nummer = 0
relikte = []

while linie != 'Fim do labirinto':
    linie = linie.split()
    for i in range(len(linie)):
        if linie[i] == '1':
            relikte.append([nummer, i])
    linie = input()
    nummer += 1

if len(relikte) != 0:
    print('Relíquias encontradas nos seguintes locais:')
    for paar in relikte:
        print(f'linha: {paar[0]}, coluna: {paar[1]}')
else:
  print("Nenhuma relíquia encontrada no labirinto.")