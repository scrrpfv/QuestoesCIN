def decifra(codigo, decifrado=''):
  if len(codigo) == 0:
    return decifrado
  else:
    binario = list(codigo.pop())
    binario.reverse()
    decimal = bin_p_decimal(binario)[1]
    decifrado += chr(decimal)
    decifrado = decifra(codigo, decifrado)
  return decifrado

def bin_p_decimal(binario, decimal=0):
  if len(binario) == 0:
    return binario, decimal
  else:
    n = int(binario.pop())
    decimal += n*2**len(binario)
    return bin_p_decimal(binario, decimal)

codigo = input().split()
codigo.reverse()
info = decifra(codigo)
print(f'Os códigos da Matrix indicam que {info} está perto.')
