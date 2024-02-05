numero, str1, str2, str3 = int(input()), input(), input(), input()
l1, l2, l3 = len(str1), len(str2), len(str3)
maior, menor = "", ""
conseguiu = False

if numero == 1:
    if (l2 < l1 > l3) or (l1 < l2 > l3) or (l1 < l3 > l2):
        maior = str1*(l2 < l1 > l3) + str2*(l1 < l2 > l3) + str3*(l1 < l3 > l2)
        print(maior)
        conseguiu = True
else:
    if (l2 > l1 < l3) or (l1 > l2 < l3) or (l1 > l3 < l2):
        menor = str1*(l2 > l1 < l3) + str2*(l1 > l2 < l3) + str3*(l1 > l3 < l2)
        print(menor)
        conseguiu = True

if len(maior) == 0 and len(menor) == 0:
    print("(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)")
    leximaior = str1*(str2 < str1 > str3) + str2*(str1 < str2 > str3) + str3*(str1 < str3 > str2)
    if len(leximaior) != 0:
        print(leximaior)
        conseguiu = True
    else:
        print('"AAAAAA! Um fantasma me assustou!"')
        print('(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')

if conseguiu:
    print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
print('(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
