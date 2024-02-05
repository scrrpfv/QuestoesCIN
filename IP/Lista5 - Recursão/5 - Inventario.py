def encontra_posicao(item, inventario, x0=0, y0=0):
  x_max, y_max = len(inventario[0]), len(inventario)
  x_item, y_item = map(int, item[1].split('x'))
  skip = False
  for i in range(y0, y0 + y_item):
    for j in range(x0, x0 + x_item):
      if inventario[i][j] != 'O':
        if x0 + 1 > x_max - x_item and y0 + 1 <= y_max - y_item:
          x0 = 0
          y0 += 1
        elif x0 + 1 <= x_max - x_item:
          x0 += 1
        else:
          return -1, -1
        x0, y0 = encontra_posicao(item, inventario, x0, y0)
        skip = True
        break
    if skip:
      break
  return x0, y0


def encaixa_item(item, inventario, x, y):
  letra = item[2][0].upper()
  x_item, y_item = map(int, item[1].split('x'))
  for i in range(y, y + y_item):
    for j in range(x, x + x_item):
      inventario[i][j] = letra
  return inventario


def printa(inventario):
  for linha in inventario:
    print(''.join(linha))


inventario = []
linha = input()
while linha != "finalizar":
  inventario.append(list(linha))
  linha = input()

obrigatorios = input().split(', ')

for linha in inventario:
  for letra in linha:
    if letra != 'O':
      if letra == 'M':
        if 'munição' in obrigatorios:
          obrigatorios.remove('munição')
      elif letra == 'G':
        if 'granada' in obrigatorios:
          obrigatorios.remove('granada')
      elif letra == 'B':
        if 'branca' in obrigatorios:
          obrigatorios.remove('branca')
      elif letra == 'S':
        if 'secundaria' in obrigatorios:
          obrigatorios.remove('secundaria')
      elif letra == 'P':
        if 'primaria' in obrigatorios:
          obrigatorios.remove('primaria')
      elif letra == 'A':
        if 'acessorios' in obrigatorios:
          obrigatorios.remove('acessorios')

item = input()
while item != 'finalizar programa':
  item = item.split('-')
  if item[2] in obrigatorios:
    x, y = encontra_posicao(item, inventario)
    if x != -1:
      inventario = encaixa_item(item, inventario, x, y)
      obrigatorios.remove(item[2])
      print(f'Item adicionado: {item[0]}')
    else:
      print(f'Não há espaço para {item[0]}')
  else:
    print(f'Não precisamos de {item[0]}')
  item = input()
printa(inventario)
if len(obrigatorios) > 0:
  print(f'Faltou: {", ".join(obrigatorios)}')
