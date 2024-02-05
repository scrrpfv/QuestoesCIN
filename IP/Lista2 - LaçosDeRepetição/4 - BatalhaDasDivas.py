n = int(input())
acabou = False
tayscore, beyscore = 0, 0
print("Vai começar! Vamos ver quem é a verdadeira diva!")
for i in range(n):
    if not acabou:
        print(f"Vai começar a {i+1}º rodada!")
        tayrodada, beyrodada = 0, 0
        tayrodada += int(input())*4 + int(input())*3
        beyrodada += int(input())*4 + int(input())*3    
        if tayrodada > beyrodada:
            tayscore += 1
            print(f"Fim da apresentação! O placar da rodada {i+1} foi {tayrodada}x{beyrodada} para os representantes da Tay.")
        else:
            beyscore += 1
            print(f"Fim da apresentação! O placar da rodada {i+1} foi {beyrodada}x{tayrodada} para os representantes da Bey.")
        diferenca = abs(tayrodada - beyrodada)
        if diferenca > 20:
            print(f"A diferença na pontuação foi de {diferenca} pontos.")
        else:
            print(f"A diferença de pontos foi de apenas {diferenca}.")
        if tayscore >= 3 or beyscore >= 3:
            acabou = True
if tayscore > beyscore:
    print(f"Uuuh! Por um placar de {tayscore} a {beyscore}, a equipe da Taylor Swift venceu a competição e mostrou que ela é a verdadeira diva do pop!")
else:
    print(f"Minha nossa! A equipe da Beyoncé chocou o mundo e venceu a equipe da Taylor Swift por um placar de {beyscore} a {tayscore}. A Bey é a verdadeira rainha do pop!")