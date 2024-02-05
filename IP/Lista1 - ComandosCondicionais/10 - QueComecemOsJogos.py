pontuacao = 0

# Porta 1
direcao1, numero1 = input(), int(input())
direita1 = (numero1%2 == 1)
if (direcao1 == "direita" and direita1) or (direcao1 == "esquerda" and not direita1):
    stat1 = "CERTA"
    pontuacao += 150
else:
    stat1 = "ERRADA"
    pontuacao -=150

# Porta 2
direcao2, cor2, planta2, macaneta2 = input(), input(), input(), input()
direita2 = (cor2 == "dourada" or cor2 == "prateada") or ((planta2 == "avenca" or planta2 == "espadinha") and (macaneta2 == "redonda"))
if (direcao2 == "direita" and direita2) or (direcao2 == "esquerda" and not direita2):
    stat2 = "CERTA"
    pontuacao += 200
else:
    stat2 = "ERRADA"
    pontuacao -= 200

# Porta 3
direcao3, cor3, numero3, planta3, macaneta3 = input(), input(), int(input()), input(), input()
direita3 = (not ((numero3%5 == 0 and planta3 == "espadinha" and macaneta3 == "quadrada") or cor3 == "perolada"))
if (direcao3 == "direita" and direita3) or (direcao3 == "esquerda" and not direita3):
    stat3 = "CERTA"
    pontuacao += 250
else:
    stat3 = "ERRADA"
    pontuacao -= 250

# Porta 4
direcao4, numero4 = input(), int(input())
direita4 = ((numero4%3 == 0) and (numero4%2 != 0) and (numero4%2 != 0))
if (direcao4 == "direita" and direita4) or (direcao4 == "esquerda" and not direita4):
    stat4 = "CERTA"
    pontuacao += 300
else:
    stat4 = "ERRADA"
    pontuacao -= 300

# Porta 5
cor5, numero5, planta5, flor5, macaneta5 = input(), int(input()), input(), input(), input()
if (cor5 == "acobreada" and ((numero5%2 == 1) or (macaneta5 == "triangular") or (macaneta5 == "quadrada")) and planta5 == "jiboia"):
    stat5 = "CERTA"
    pontuacao += 500
elif (cor5 == "prateada" and (flor5 != "margarida" and flor5 != "papoula" and flor5 != "cosmos") and (macaneta5 == "hexagonal" or macaneta5 == "redonda")):
    stat5 = "CERTA"
    pontuacao += 450
elif (cor5 == "dourada" and (flor5 == "lirio" or flor5 == "ixora") and macaneta5 == "hexagonal"):
    stat5 = "CERTA"
    pontuacao += 400
else:
    stat5 = "ERRADA"
    pontuacao -= 500

acertoualguma = stat1 == "CERTA" or stat2 == "CERTA" or stat3 == "CERTA" or stat4 == "CERTA" or stat5 == "CERTA"
erroualguma = stat1 == "ERRADA" or stat2 == "ERRADA" or stat3 == "ERRADA" or stat4 == "ERRADA" or stat5 == "ERRADA"

print("ARISU, VOCÊ FEZ SUAS ESCOLHAS E AGORA VEREMOS SE ESCOLHEU AS PORTAS CERTAS:")
print(stat1 + " " + stat2 + " " + stat3 + " " + stat4 + " " + stat5)

if pontuacao > 0:
    if erroualguma:
        print(f"Você passou com {pontuacao} pontos, mas faça melhores escolhas da próxima vez.")
    else:
        print(f"Parece que a sorte está ao seu favor, Arisu... Você conseguiu passar com {pontuacao} pontos!")
else:
    if acertoualguma:
        print(f"Por mais que você tenha feito escolhas corretas, não foi suficiente para sobreviver. Você finalizou o jogo com {pontuacao} pontos")
    else:
        print(f"Todas suas escolhas foram erradas, Arisu, esperávamos mais de você... Você será executado pois obteve {pontuacao} pontos.")
