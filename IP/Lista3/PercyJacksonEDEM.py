Gabarito = [['Zeus', 'trovão', 'deus'],
            ['Afrodite', 'amor', 'deusa'],
            ['Poseidon', 'oceanos', 'deus'],
            ['Hércules', 'força', 'semideus'],
            ['Aquiles', 'resistência', 'semideus'],
            ['Orfeu', 'música', 'semideus']]

for i in range(6):
    Gabarito[i].sort()

acertos = 0
quantidade = int(input())
for i in range(quantidade):
    questao = input().split(', ')
    questao.sort()
    if questao in Gabarito:
        print(f'A resposta da {i+1}ª questão está... CORRETA!')
        acertos += 1
    else:
        print(f'A resposta da {i+1}ª questão está... ERRADA!')

if quantidade == 0:
    print('Infelizmente, Percy Jackson, chegou atrasado para a exame...')

else:
    porcentagem = int(100*acertos/quantidade)
    print(f'Percy Jackson, sua taxa de acerto no EDEM é de aproximadamente... {porcentagem}%')
    if porcentagem == 100:
        print('UAU, você gabaritou! Você é praticamente um deus do Olimpo!')
    elif porcentagem >= 60:
        print('Muito bem, você quase pode começar a desfilar entre os semideuses!')
    elif porcentagem >= 20:
        print('Você pode melhorar um pouco mais!')
    else:
        print('Bem... te vejo ano que vem')