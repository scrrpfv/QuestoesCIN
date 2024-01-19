def nova_cidade():
    str_input = input()
    lista_input = str_input.split(', ')
    lista_input[1] = float(lista_input[1])
    lista_input[2] = float(lista_input[2])
    lista_input[4] = float(lista_input[4])
    return lista_input


def decifra(palavra_criptografada, numero_de_posicoes, direcao):
    lista_char = [ord(letra) for letra in palavra_criptografada]

    sinal = 1
    if direcao == "L":
        sinal = -1
    palavra = ""

    for i in range(len(lista_char)):
        palavra += chr(int(65 + ((lista_char[i] + sinal * numero_de_posicoes - 65) % 26)))
    return palavra


def proxima_cidade(x_atual, y_atual, lista_cidades):
    id_cidade = -1
    menor_distancia = float('inf')

    for i in range(len(lista_cidades)):
        distancia_cidade = distancia_euclideana(x_atual, y_atual, lista_cidades[i][1], lista_cidades[i][2])

        if distancia_cidade < menor_distancia:
            menor_distancia = distancia_cidade
            id_cidade = i
    return id_cidade


def distancia_euclideana(x_atual, y_atual, x_cidade, y_cidade):
    distancia = ((x_atual - x_cidade)**2 + (y_atual - y_cidade)**2)**(1/2)
    return distancia


def main():
    quantidade_de_cidades = int(input())
    lista_cidades = []
    for i in range(quantidade_de_cidades):
        lista_cidades.append(nova_cidade())

    x_atual = 0
    y_atual = 0
    for i in range(quantidade_de_cidades):
        id_cidade_atual = proxima_cidade(x_atual, y_atual, lista_cidades)
        cidade_atual = lista_cidades.pop(id_cidade_atual)
        nome = cidade_atual[0]

        palavra_criptografada = cidade_atual[3]
        numero_de_posicoes = cidade_atual[4]
        direcao = cidade_atual[5]
        palavra_descriptografada = decifra(palavra_criptografada, numero_de_posicoes, direcao)

        print(f'A senha da cidade {nome} é: {palavra_descriptografada}')


main()
