nome_missao = input()
herois = []
rodando = True
while rodando:
    novo_heroi = input()
    if novo_heroi == "Grupo formado":
        rodando = False
    else:
        herois.append(novo_heroi)
print(f'O grupo formado por {len(herois)} heróis para a missão {nome_missao} foi:')
for i in range(len(herois)):
    print(f'- {herois[i]}')