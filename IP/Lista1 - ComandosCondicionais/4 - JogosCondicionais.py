nome_vitima = input()
antagonista = input()
armadilha = input()
tempo = int(input())/60
over = "Game Over..."

if antagonista == "John Kramer":
  if armadilha == "Armadilha de urso reversa":
    if tempo >= 5:
      print(f"Com tempo de sobra, {nome_vitima} consegue retirar a armadilha de sua cabeça, sobrevivendo com sucesso ao jogo de Jigsaw.")
    elif 2.5 <= tempo < 5:
      print(f"À beira de perder a cabeça, e desafiando as expectativas de seu algoz, {nome_vitima} remove a armadilha de urso e por pouco escapa de um destino cruel.")
    else:
      print(over)
  if armadilha == "Tanque de agua":
    if tempo >= 4:
      print(f"{nome_vitima} usa suas práticas de respiração na natação a seu favor, vencendo o jogo de Jigsaw sem perder muito fôlego.")
    elif 2 <= tempo < 4:
      print(f"{nome_vitima} passa por maus bocados, mas vira o jogo e consegue evitar, no limite, seu afogamento dentro da armadilha.")
    else:
      print(over)
if antagonista == "Amanda Young":
  if armadilha == "Caixa de laminas":
    if tempo >= 10:
      print(f"Apenas com ferimentos leves, {nome_vitima} se liberta rapidamente das perigosas lâminas da armadilha montada pela discípula de Jigsaw.")
    elif 6 <= tempo < 10:
      print(f"Por um triz, {nome_vitima} sobrevive ao jogo de Amanda, mas com lesões profundas em suas mãos e braços.")
    else:
      print(over)
  elif armadilha == "Asas de anjo":
    if tempo >= 3:
      print(f"Com surpreendente facilidade, {nome_vitima} alcança a chave da armadilha e vence o desafio da aprendiz de Jigsaw.")
    elif 1.5 <= tempo < 3:
      print(f"{nome_vitima} desafia as possibilidades e o cruel anseio de sua algoz, escapando da armadilha com poucas queimaduras e arranhões.")
    else:
      print(over)