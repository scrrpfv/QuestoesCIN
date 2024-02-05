string = ''
tempo = 0
while string != "parei":
    string = input()
    if string == "amei":
        tempo += 4
    elif string == "não parei de ouvir":
        string = input()
        while string != "pulei":
            tempo += 4
            string = input()
    elif string == "essa não deu":
        pass
    elif string == "escutei só metade":
        tempo += 2
print(f"Você ouviu {tempo} minutos hoje!!!")