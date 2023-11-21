n = int(input())
cambistas = 0
for i in range(n):
    criterios = 0
    nome = input()
    cpf = input()
    nomeid = input()
    cpfid = input()
    ingressos = int(input())
    preco = float(input())
    codigo = input()

    if nome != nomeid:
        criterios += 1
    
    if cpf != cpfid:
        criterios += 1
    
    if ingressos > 12:
        criterios += 1
    
    if preco > 1500:
        criterios += 1
    
    digitosimpares = 0
    for digit in codigo:
        if int(digit)%2:
            digitosimpares += 1
    if digitosimpares >= 7:
        criterios += 1

    if criterios >= 3:
        cambistas += 1

print(f"Total de compradores analisados: {n}")
print(f"Total de suspeitas de cambistas: {cambistas}")