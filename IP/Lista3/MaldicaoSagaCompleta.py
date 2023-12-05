saga = ['O Ladrão de Raios', 'O Mar de Monstros', 'A Maldição do Titã', 'A Batalha do Labirinto', 'O Último Olimpiano']
colecao = input().split(', ')
outros = []
numero = input()

for livro in colecao:
    if livro in saga:
        saga.remove(livro)
    elif livro != '':
        outros.append(livro)

if len(saga) == 0:
    print('Sua coleção está completa! Você pode ler à vontade.')
elif len(saga) < 5:
    print(f'Infelizmente, sua coleção está incompleta. Falta(m) esse(s) livro(s): {", ".join(saga)}.')
else:
    print('Caramba, você não tem nenhum livro. Compre todos imediatamente.')

if len(outros) != 0:
    print(f'Cuidado, Sérgio! Você está organizando seus livros de uma forma errada, o(s) livro(s): {", ".join(outros)}, não faz(em) parte da saga "Percy Jackson e os Olimpianos".')