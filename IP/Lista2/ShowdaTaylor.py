lugar = input()
codigo = ""
vips = 0
quebrou = False
while codigo != "0000" and not quebrou:
    codigo = input()
    if codigo == "1000":
        vips += 1
        print("Mais um VIP! Não podemos esquecer de contabilizá-lo.")
    elif codigo == "1001":
        print("Ingresso Normal. Não iremos contabilizá-lo.")
    elif codigo == "1002":
        print("Ele ficará na frente do show, porém não é VIP! Não será contabilizado também.")
    elif codigo == "1003":
        print("Espera, quem é esse? Ele não pagou! Não devemos sequer analisar sua entrada.")
    elif codigo == "1004":
        print("Esse código não existe! O sistema quebrou...")
        print("Vamos aguardar até que o suporte nos ajude.")
        quebrou = True
        situacao = input()
        while situacao != "Ajudou":
            print("Ainda não...")
            situacao = input()
print(f"O show da Taylor Swift será em {lugar} e contará com {vips} VIPs!")