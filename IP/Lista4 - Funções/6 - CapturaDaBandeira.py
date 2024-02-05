def printmapa(coords, pegou_bandeira):
    mapa = [['-' for _ in range(8)] for __ in range(8)]
    mapa[coords[0]][coords[1]] = 'P'
    mapa[coords[4]][coords[5]] = 'A'
    mapa[coords[2]][coords[3]] = 'C'
    if not pegou_bandeira:
        mapa[coords[6]][coords[7]] = 'B'
    for linha in mapa:
        print(' '.join(linha))


def movepercy(coords, direcao):
    if direcao == 'cima':
        coords[0] -= 1
    elif direcao == 'baixo':
        coords[0] += 1
    elif direcao == 'esquerda':
        coords[1] -= 1
    else:
        coords[1] += 1
    return coords


def moveclarisse(coords):
    if coords[3] != coords[1]:
        if coords[3] > coords[1]:
            coords[3] -= 1
        else:
            coords[3] += 1
    else:
        if coords[2] > coords[0]:
            coords[2] -= 1
        else:
            coords[2] += 1
    return coords


def main():
    coords = [
        int(input()), int(input()),
        int(input()), int(input()),
        int(input()), int(input()),
        int(input()), int(input())
    ]

    pisou_agua = False
    pegou_bandeira = False
    printou_bandeira = False
    vencedor = False
    while not vencedor:
        coords = moveclarisse(coords)
        if coords[2] == coords[4] and coords[3] == coords[5]:
            vencedor = 'percy'
        elif coords[2] == coords[0] and coords[3] == coords[1]:
            vencedor = 'clarisse'
        if vencedor:
            break

        direcao = input()
        coords = movepercy(coords, direcao)

        if coords[0] == coords[4] and coords[1] == coords[5]:
            coords = movepercy(coords, direcao)
            pisou_agua = True
        if coords[0] == coords[6] and coords[1] == coords[7]:
            pegou_bandeira = True
        if coords[0] == 0 and pegou_bandeira:
            vencedor = 'percy'

        elif not vencedor:
            if pisou_agua:
                print('Sinto o poder de Poseidon em minhas veias!')
            if not pegou_bandeira:
                print('Preciso pegar aquela maldita bandeira vermelha.')
            elif pegou_bandeira and not printou_bandeira:
                print('Isso! Consegui a bandeira!')
                printou_bandeira = True
            elif pegou_bandeira:
                print('Agora eu só preciso meter o pé daqui!')
            printmapa(coords, pegou_bandeira)
            print('')
        pisou_agua = False

    if vencedor == 'clarisse':
        print('Ah não, Annabeth vai me matar...')
        printmapa(coords, pegou_bandeira)
    if vencedor == 'percy':
        print('Vitória!! Nunca subestime o cabeça de alga!')
        printmapa(coords, pegou_bandeira)


main()
