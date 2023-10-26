nomeEspecie = input()
rodando = True
contagem = 0
while rodando:
    et1, et2 = [], []
    et1.append(input())
    if et1[0] == 'fim':
        break
    et2.append(input())
    et1.append(input())
    et2.append(input())
    et1.append(input())
    et2.append(input())
    et1.append(input())
    et2.append(input())
    if (int(et1[2]) - int(et1[3]))**2 > (int(et2[2]) - int(et2[3]))**2:
        print(f'O bebê ET gerado é da espécie {et1[0]} e tem como característica {et1[1]}')
        if et1[0] == nomeEspecie:
            contagem += 1
    else:
        print(f'O bebê ET gerado é da espécie {et2[0]} e tem como característica {et2[1]}')
        if et2[0] == nomeEspecie:
            contagem += 1
print(f'nasceram {contagem} bebês ETs da espécie {nomeEspecie}')
