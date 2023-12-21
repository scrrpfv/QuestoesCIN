def decodifica(codigo):
    presente = ''
    for i in codigo:
        if i != '':
            presente += chr(i)
    return presente

def detecta_excluidos(codigo):
    c = 0
    for i in codigo:
        c += i
    if c % 2:
        return True
    else:
        return False

def exclui_presentes(lista_presentes, presentes_excluidos):
    for presente_excluido in presentes_excluidos:
        lista_presentes.remove(presente_excluido)
    return lista_presentes

def principal(n_presentes):
    lista_presentes = []
    presentes_excluidos = []
    for i in range(n_presentes):
        codigo = list(map(int, input().split()))
        presente = decodifica(codigo)
        if presente not in lista_presentes:
            if detecta_excluidos(codigo):
                presentes_excluidos.append(presente)
            lista_presentes.append(decodifica(codigo))
            print(f'{presente} foi adicionado a lista ultrassecreta de presentes da Anya!!')
        else:
            print(f'{presente} já está na lista de presentes da Anya!!')

    lista_presentes = exclui_presentes(lista_presentes, presentes_excluidos)

    if n_presentes > 0:
        if len(presentes_excluidos) > 0:
            print(f'Infelizmente o Twilight é mão de vaca e os seguintes itens precisaram ser excluídos da lista de presentes ultrassecretos da Anya: {", ".join(presentes_excluidos)}.')
        else:
            print('Parece que o Dia das Crianças desse ano será especial!!!! Anya ganhará todos os presentes planejados, mesmo que ela não seja tão exemplar como deveria…')

    if len(lista_presentes) == 0:
        print('O quê? Nenhum presente? Isso é um absurdo! Vamos corrigir essa injustiça e garantir que Anya tenha um Dia das Crianças inesquecível!')
    else:
        print(f'Lista final dos melhores presentes da Anya: {", ".join(lista_presentes)}.')

principal(int(input()))
