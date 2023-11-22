computadores_disponiveis = int(input())
dinheiro_disponivel = int(input())
tempo_minutos = int(input())*60
nome = input()
amigos = 0
while nome != 'end':
    if nome != 'laura' and nome != 'carlos' and nome != 'roberto' and amigos >= computadores_disponiveis:
        amigos += 1
if amigos:
    valor_do_ingresso = input()
    local_do_show = input()

else:
    print('')
