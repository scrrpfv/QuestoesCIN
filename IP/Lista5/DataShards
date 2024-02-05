def separa(n, alvo):
  if n == alvo or n == -1:
    return -1, alvo
  elif n%3 == 0:
    resultado1, alvo = separa(n/3, alvo)
    resultado2, alvo = separa(2*(n/3), alvo)
    if resultado1 == -1:
      return -1, alvo
    elif resultado2 == -1:
      return -1, alvo
    else:
      return -2, alvo
  else:
    return -2, alvo

num_pedidos = int(input())
for i in range(num_pedidos):
  inp = input().split()
  n = int(inp[0])
  alvo = int(inp[1])
  resultado, alvo = separa(n, alvo)
  if resultado == -1:
    print('SIM')
  if resultado == -2:
    print('NAO')
