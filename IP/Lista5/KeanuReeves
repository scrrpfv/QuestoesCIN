def completa(palavra):
  if len(palavra) == 32:
    return palavra
  else:
    palavra = '0' + palavra
    return completa(palavra)


def testa(palavra, tentativa, max_tentativas):
  if tentativa == max_tentativas:
    print('Corre Keanu! Eles nos descobriram!!')
  else:
    byte = input()
    if byte in palavra:
      print('Muito bem! Estamos dentro! Vamos queimar essa cidade!!')
    else:
      print('Não é essa a senha, estamos ficando sem tempo.')
      testa(palavra, tentativa + 1, max_tentativas)

palavra = completa(input())
max_tentativas = int(input())
testa(palavra, 0, max_tentativas)
