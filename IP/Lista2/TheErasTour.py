string = ''
musicas = 0
pontos = 0
while string != "long live":
    string = input()
    if string == "os fãs estão formando uma ciranda":
        pontos -= 3
    elif string == "os fãs estão ligando os flashes e atrapalhando a visão":
        pontos -= 2
    elif string == "os fãs estão dançando na frente da tela":
        pontos -= 2
    elif string == "os fãs estão gritando o nome da Taylor e atrapalhando a música":
        pontos -= 2
    elif string == "os fãs estão cantando as músicas em coro":
        pontos += 2
    elif string == "houve um pedido de casamento na sessão":
        pontos += 2
    else:
        musicas += 1
        pontos += 1
    if pontos <= 0:
        print(f"A Taylor só conseguiu cantar {musicas} músicas e a sessão foi interrompida.")
        break
if string == "long live":
    print(f"A Taylor conseguiu concluir o show sem muitas interrupções e cantou {musicas} músicas.")