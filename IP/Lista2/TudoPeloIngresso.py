computadores_disponiveis = int(input())
dinheiro_disponivel = int(input())
tempo_minutos = int(input())*60
nome = input()
amigos = 0
ingressos_validos = 0
posicao_minima = int(tempo_minutos*16/10)
while nome != 'end':
    if nome != 'laura' and nome != 'carlos' and nome != 'roberto' and amigos <= computadores_disponiveis:
        amigos += 1

if not amigos:
    print('Ah não! João não conseguiu nenhum amigo que o ajudasse. Agora ele vai ter que contar com a sorte para pegar um bom lugar na fila, usando apenas seu computador.')
else:
    print(f'Bom começo! Consegui {amigos} amigos que podem me ajudar a comprar o ingresso')
for i in range(amigos):
    valor_do_ingresso = ''
    while valor_do_ingresso != 'end':
        valor_do_ingresso = int(input())
        local_do_show = input()
        if local_do_show == 'rio de janeiro' or local_do_show == 'são paulo' or local_do_show == 'buenos aires':
            print('Consegui um ingresso em um local que João possa ir! Agora temos que ver o preço')
            if valor_do_ingresso <= dinheiro_disponivel:
                print('Consegui o dinheiro! Agora só falta ver a minha colocação na fila dos ingressos...')
                posicao_fila = int(input())
                if posicao_fila < posicao_minima:
                    print('ISSOOO, conseguimos um ingresso!!!')
                    computador_escolhido = i
                    posicao_minima = posicao_fila
                    ingressos_validos += 1
                else:
                    print(f'Caramba, essa foi quase! Mas infelizmente não consegui um bom lugar na fila dos ingressos no computador de número {i}')
            else:
                print('Caramba! Só tinha ingresso para a pista vip, que está bem acima do meu orçamento.')

if ingressos_validos:
    print(f'Consegui o ingresso! Com {int((ingressos_validos/amigos)*100)}% de aproveitamento da ajuda dos meus amigos. E a fila escolhida para comprar o ingresso foi do computador número {computador_escolhido}. Rumo ao show da Taylor!!!')
elif amigos/computadores_disponiveis >= 0.5:
    print('Não acredito que tive amigos para ocuparem mais da metade dos computadores, e ainda assim não consegui um ingresso...')
else:
    print('Poxa, não acredito que não consegui o ingresso, acho que eu devia ter chamado mais amigos para ajudar.')
