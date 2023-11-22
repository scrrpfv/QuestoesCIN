nome = input()
while nome != 'vou dormir':
	passa = True
	pretendente = input()
	taylor = input()
	for i in taylor:
		if i in pretendente:
			pretendente = pretendente.replace(i, '', 1)
		else:
			passa = False
			break
	if passa:
		print(f'você acertou, estreou na lista! {nome}')
	else:
		print(f'perdeu covarde!')
	nome = input()
