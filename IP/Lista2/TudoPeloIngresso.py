computadores_disponiveis = int(input())
dinheiro_disponivel = int(input())
tempo_minutos = int(input())*60
nome = ''
amigos = 0
ingressos_validos = 0
posicao_minima = int(tempo_minutos*16/10)
posicao_escolhida = posicao_minima
while nome != 'end' and amigos < computadores_disponiveis:
    nome = input()
    if nome != 'laura' and nome != 'carlos' and nome != 'roberto' and nome != 'end':
        amigos += 1
    

if not amigos:
    print('Ah não! João não conseguiu nenhum amigo que o ajudasse. Agora ele vai ter que contar com a sorte para pegar um bom lugar na fila, usando apenas seu computador.')
else:
    print(f'Bom começo! Consegui {amigos} amigos que podem me ajudar a comprar o ingresso')
for i in range(amigos):
    conseguiu_ingresso = False
    valor_do_ingresso = dinheiro_disponivel + 1
    local_do_show = ''
    achou_local = False
    while local_do_show != 'end' and not achou_local:
        valor_do_ingresso = int(input())
        local_do_show = input()
        if local_do_show == 'rio de janeiro' or local_do_show == 'são paulo' or local_do_show == 'buenos aires':
            achou_local = True
            print('Consegui um ingresso em um local que João possa ir! Agora temos que ver o preço')
            if valor_do_ingresso <= dinheiro_disponivel:
                print('Consegui o dinheiro! Agora só falta ver a minha colocação na fila dos ingressos...')
                posicao_fila = int(input())
                if posicao_fila <= posicao_minima:
                    print('ISSOOO, conseguimos um ingresso!!!')
                    conseguiu_ingresso = True
                    ingressos_validos += 1
                    if posicao_fila < posicao_escolhida:
                        computador_escolhido = i
                        posicao_escolhida = posicao_fila
                else:
                    print(f'Caramba, essa foi quase! Mas infelizmente não consegui um bom lugar na fila dos ingressos no computador de número {i + 1}')
            else:
                print('Caramba! Só tinha ingresso para a pista vip, que está bem acima do meu orçamento.')


if ingressos_validos:
    print(f'Consegui o ingresso! Com {int((ingressos_validos/amigos)*100)}% de aproveitamento da ajuda dos meus amigos. E a fila escolhida para comprar o ingresso foi do computador número {computador_escolhido + 1}. Rumo ao show da Taylor!!!')
elif amigos/computadores_disponiveis > 0.5:
    print('Não acredito que tive amigos para ocuparem mais da metade dos computadores, e ainda assim não consegui um ingresso...')
elif amigos and amigos/computadores_disponiveis <= 0.5:
    print('Poxa, não acredito que não consegui o ingresso, acho que eu devia ter chamado mais amigos para ajudar.')
