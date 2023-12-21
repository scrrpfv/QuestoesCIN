def organiza_malas(lista_pesos):
    lista_organizada = sorted(lista_pesos)
    lista_organizada[0], lista_organizada[-1] = lista_organizada[-1], lista_organizada[0]
    lista_organizada[1], lista_organizada[-2] = lista_organizada[-2], lista_organizada[1]
    return lista_organizada

def parametros(qtd_carvao, peso, qtd_passageiros):
    velocidade = int((qtd_carvao + 200)/2)
    carga = int((peso + 4000)/1000)
    passageiros = qtd_passageiros + 40
    return velocidade, carga, passageiros

def turno(hora_viagem, numero_roteiro, lista_funcionarios):
    convocados = []
    if (21 > hora_viagem >= 7):
        if numero_roteiro == 1:
            convocados = [lista_funcionarios[0], lista_funcionarios[1]]
        else:
            convocados = [lista_funcionarios[0], lista_funcionarios[-1]]
    else:
        if numero_roteiro == 1:
            convocados = [lista_funcionarios[2]]
        else:
            convocados = []
    return convocados

def protocolo_de_inicio():
    lista_pesos = list(map(int, input().split(', ')))
    lista_organizada = organiza_malas(lista_pesos)
    print(f'A nova organização das malas é a seguinte: {", ".join(list(map(str, lista_organizada)))}')

    info_parametros = input().split(', ')
    qtd_carvao, peso, qtd_passageiros = int(info_parametros[0]), int(info_parametros[1]), int(info_parametros[2])
    velocidade, carga, passageiros = parametros(qtd_carvao, peso, qtd_passageiros)
    print(f'A velocidade que o trem partirá é de: {velocidade}Km/H')
    print(f'A carga do Trem em Toneladas é: {carga} Ton.')
    print(f'A quantidade de passageiros é de {passageiros}')

    lista_funcionarios = input().split(', ')
    hora_viagem = input().split(':')
    hora_viagem = int(hora_viagem[0]) + (int(hora_viagem[1]) / 60)
    numero_roteiro = int(input().split()[1])
    convocados = turno(hora_viagem, numero_roteiro, lista_funcionarios)
    if len(convocados) > 0:
        print(f'Os funcionários convocados são: {", ".join(convocados)}')
    else:
        print('Os funcionários convocados são: Nenhum! O turno da Madrugada vai ser tranquilo para todos')

protocolo_de_inicio()
