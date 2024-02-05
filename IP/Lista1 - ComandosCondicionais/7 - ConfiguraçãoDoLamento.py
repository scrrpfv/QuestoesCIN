n1=int(input())
if n1>0:
  n2=int(input())
  if n2>0:
    n3=int(input())
    if n3>0:
      p=input()
      if p.lower() == p:
        n5=int(input())
        r=(n5*(n1*(n1%2)*0.5+n1*(n1%2==0)*2)*(n2*(n2%2)*0.5+n2*(n2%2==0)*2)*(n3*(n3%2)*0.5+n3*(n3%2==0)*2))**0.5
        if r>10:
          print(f"O número {r:.2f} e a palavra {p} eram as respostas. A caixa foi aberta.")
        else:
          print(f"A combinação era muito pequena, a caixa só vai poder ser aberta daqui a {(10-r):.2f} anos.")
      else:
        print(f'{p} não está gravado(a) na caixa, não adianta nem continuar que ela não vai abrir.')
    else:
      print(f'{n3:.2f} não está gravado(a) na caixa, não adianta nem continuar que ela não vai abrir.')
  else:
    print(f'{n2:.2f} não está gravado(a) na caixa, não adianta nem continuar que ela não vai abrir.')
else:
  print(f'{n1:.2f} não está gravado(a) na caixa, não adianta nem continuar que ela não vai abrir.')