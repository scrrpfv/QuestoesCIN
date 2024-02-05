x1 = float(input())
a, b, c, d, e = float(input()), float(input()), float(input()), float(input()), float(input())
h = 1e-9
zero = 0.001


def processa(x1, equacao=''):
  if a == 0 and e*x1 == 0:
    print(f'Maldição, a função é aproximadamente a reta y={round(d, 3)} que é paralela ao eixo das abscissas, não tem raiz e não é possível aplicar o método.')
    return 0
  else:
    y1 = (a*(x1+b)**c)+(e*x1)+d
    
    if abs(y1) < zero:
      print(f'Acertou em cheio! A raiz foi encontrada e o valor dela nas abscissas é aproximadamente {round(x1, 3)}, e a equação da reta tangente neste ponto é aproximadamente {equacao}.')
      return 0
      
    resultado_derivada = (((a*((x1+h)+b)**c)+(e*(x1+h))+d) - ((a*(x1+b)**c)+(e*x1)+d)) / h
    termo_independente = y1-(resultado_derivada*x1)
    sinal = '+'*(termo_independente > 0) + '-'*(termo_independente < 0)
    if abs(resultado_derivada) > zero:
      equacao = (f'y={round(resultado_derivada, 3)}*x{sinal}{round(termo_independente, 3)}')
      x2 = (-termo_independente)/resultado_derivada
      y2 = (a*(x2+b)**c)+(e*x2)+d
    else:
      equacao = (f'y={round(termo_independente, 3)}')
    y = resultado_derivada*x1+termo_independente
    if abs(y1) > zero:
      print(f'Encontramos o ponto ({round(x1, 3)};{round(y1, 3)}) da função, a equação da reta tangente deste ponto é aproximadamente {equacao}, porém, ainda não é a raiz devemos continuar para otimizar a trajetória do disparo.')
    if abs(resultado_derivada) < zero:
      print(f'Droga, a reta tangente {equacao} é paralela ao eixo das abscissas, não tem raiz, tenho pena de quem estiver usando a arma quando isto acontecer, kkkkk.')
      return 0
    processa(x2, equacao)


processa(x1)
