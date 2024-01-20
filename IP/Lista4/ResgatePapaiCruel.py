def fibo(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fibo(n - 1) + fibo(n - 2)


def desafio_1(frase_x):
    frase_x = frase_x.lower()
    letras = []
    quantidades = []
    for letra in frase_x:
        if letra != ' ':
            if letra not in letras:
                letras.append(letra)
                quantidades.append(1)
            else:
                indice = letras.index(letra)
                quantidades[indice] += 1
    if len(letras) == 26:
        return max(quantidades)
    else:
        return min(quantidades)


def desafio_2(palavra_y):
    palavra_y = palavra_y.lower()
    n = len(palavra_y)
    if 'a' in palavra_y or 'e' in palavra_y or 'i' in palavra_y or 'o' in palavra_y or 'u' in palavra_y:
        multiplicador = 4
    else:
        multiplicador = 2
    numero = fibo(n) * multiplicador
    return numero


def desafio_3(palavra_z, frase_z):
    n_palavra = 0
    n_frase = 0
    for letra in palavra_z:
        if letra.islower():
            n_palavra += 1
        else:
            n_palavra -= 1
    for letra in frase_z:
        if letra != ' ':
            if letra.islower():
                n_frase += 1
            else:
                n_frase -= 1
    return int(n_frase ** n_palavra)


def main():
    x_noel = desafio_1(input())
    y_noel = desafio_2(input())
    z_noel = desafio_3(input(), input())
    x_jack, y_jack, z_jack = int(input()), int(input()), int(input())
    distancia = ((x_noel - x_jack)**2 + (y_noel - y_jack)**2 + (z_noel - z_jack)**2)**(1/2)
    xyz_noel = [x_noel, y_noel, z_noel]
    for i in range(3):
        print(f'A {i + 1}ª coordenada do Papai Noel é: {xyz_noel[i]}')
    print(f'A distância entre Jack Esqueleto e Papai Noel é: {distancia:.2f}')


main()
