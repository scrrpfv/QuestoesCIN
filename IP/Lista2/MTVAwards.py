N = int(input())

kanye = False
gerard = False
chris = False
taylor = False
katy = False
ariana = False
beyonce = False
shakira = False
taylorvenceu = False
beyoncevenceu = False
shakiravenceu = False

for i in range(N):
    celebridade = input()
    print(f"Apresentador: Contamos com a ilustre presença de {celebridade}, uma salva de palmas!")
    if celebridade == "Kanye West":
        kanye = True
    elif celebridade == "Gerard Piqué":
        gerard = True
    elif celebridade == "Chris Martin":
        chris = True

candidato = ''
while candidato != "Início da Premiação":
    candidato = input()
    if candidato == "Taylor Swift":
        taylor = True
    if candidato == "Katy Perry":
        katy = True
    if candidato == "Ariana Grande":
        ariana = True
    if candidato == "Beyoncé":
        beyonce = True
    if candidato == "Shakira":
        shakira = True

print("Apresentador: Vamos deixar de enrolação e ir para a premiação!")
print("Apresentador: E a artista do ano do MTV Video Music Awards 2023 é...")
if taylor:
    print("TAYLOR SWIFT")
    taylorvenceu = True
elif katy:
    print("KATY PERRY")
elif ariana:
    print("ARIANA GRANDE")
elif beyonce:
    beyoncevenceu = True
    print("BEYONCÉ")
else:
    shakiravenceu = True
    print("SHAKIRA")

if taylorvenceu and kanye:
    print("Kanye West: Eu vou te deixar terminar. Estou feliz por você, mas Beyoncé fez um dos melhores vídeos de todos os tempos.")
if shakiravenceu and gerard:
    print("Gerard Piqué: Meu amor me perdoa, volta pra mim...")
if beyoncevenceu and chris:
    print("Chris Martin: Minha heroína, minha irmã, meu tudo. Você merece!")