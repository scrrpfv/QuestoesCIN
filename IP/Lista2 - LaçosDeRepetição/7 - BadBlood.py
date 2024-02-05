n = int(input())
acertos = 0
for i in range(n):
    plateia = input()
    plateiaup = ""
    for j in plateia:
        plateiaup += j.upper()
    if i == 0:
        print("Cause, baby, now we've got")
        if plateiaup == "BAD BLOOD":
            print(plateiaup)
            acertos += 1
    if i == 1:
        print("You know it used to be")
        if plateiaup == "MAD LOVE":
            print(plateiaup)
            acertos += 1
    if i == 2:
        print("So take a look what")
        if plateiaup == "YOU'VE DONE":
            print(plateiaup)
            acertos += 1
    if i == 3:
        print("Cause, baby, now we've got")
        if plateiaup == "BAD BLOOD, HEY":
            print(plateiaup)
            acertos += 1
if acertos == n:
    print("A plateia deu um show! Acertou tudo!")
elif acertos/n >= 0.5:
    print("A plateia acertou a maior parte da música")
else:
    print("Foi um dia atípico e a plateia se esqueceu de grande da música")
