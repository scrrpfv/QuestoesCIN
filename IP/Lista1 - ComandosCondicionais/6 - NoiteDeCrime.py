v,a,l,s,am,lm,sm,dm=int(input()),int(input()),int(input()),int(input()),int(input()),int(input()),int(input()),int(input())
if a>am and l>lm and s>sm:
  c=1
  print("Ainda bem que deu tudo certo, está quase em casa")
else:
  v: str=v-dm
  if v>0:
    c,a,l,s=1,a*0.95,l*0.95,s*1.05
    print("Rápido, corra antes que ele vá atrás de você!")
  else:
    c=0
    print("Oh, no! Acabou pra mim")
if c:
  am,lm,sm=int(input()),int(input()),int(input())
  if a>=am or l>=lm or s>=sm:
    print("Casa, aqui vou eu")
  else:
    print("Oh, no! Acabou pra mim")