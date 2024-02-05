gabarito1, gabarito2, gabarito3 = input(), input(), input()
errou = "A resposta está e…e…rrada hahahahaha. Essa é a parte que eu mais gosto, venha aqui no quintal, você pode dar um adeus!"
input()
resposta1 = input()
printou = False

if resposta1 == gabarito1:
  print("Muito bem! Olha como a primeira foi fácil, seu amigo talvez sobreviva. Falta só mais duas para acabar com isso!")
  passou = True
else:
  print(errou)
  passou = False

if passou:
  input()
  resposta2 = input()
  if resposta2 == gabarito2:
    print("A resposta está e…exata! Você é mais inteligente do que eu pensei, já posso caprichar nesta última, vamos ver se você realmente conhece filmes de terror!")
    passou = True
  else:
    print(errou)
    passou = False

if passou:
  input()
  resposta3 = input()
  if resposta3 == gabarito3:
    print("Droga, não vai ser hoje que vou ver sangue, que pena! Mas não se esqueça de mim, quem sabe um dia algum dos seus amigos não queiram brincar para lhe salvar!")
  else:
    print(errou)