monstro = input()
caracteristica = input()
permitido = "Bem-vindos ao Hotel Transilvânia!"
if monstro == "Parou filhotada, assim vocês vão deixar todo mundo maluco." and (caracteristica == "Uivar" or caracteristica == "Pelos" or caracteristica == "Caninos"):
  print(permitido)
  print("Wayne, seu cachorrão.")
elif monstro == "Veio de novo pelo correio, deixa de ser pão duro." and (caracteristica == "Desmontável" or caracteristica == "Parafusos" or caracteristica == "Morto-vivo"):
  print(permitido)
  print("Frank, assim vai acabar perdendo a cabeça.")
elif monstro == "Quem me beliscou?" and caracteristica == "Transparente":
  print(permitido)
  print("Griffin, prazer em vê-lo.")
elif monstro == "Tô na área galera!" and (caracteristica == "Enfaixado" or caracteristica == "Morto-vivo"):
  print(permitido)
  print("Murray, sempre soltando areia.")
else:
  print("UM HUMANO! Quem é você, e como você achou esse lugar?")