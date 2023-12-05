equipamentos = ['Foice de Hades',
                'Talismã de Ícaro',
                'Elmo da Invisibilidade',
                'Cinto de Hermes',
                'Espada Anaklusmos',
                'Escudo Aegis',
                'Adaga Katoptris',
                ]

linha = input().split("-")
pessoa = linha[0]
equipamentos_indesejados = linha[1:]
while pessoa != 'Parar':
    equipamentos_pessoa = equipamentos.copy()
    for equipamento in equipamentos_indesejados:
        equipamentos_pessoa.remove(equipamento)

    if len(equipamentos_pessoa) == 0:
        print(f'{pessoa} irá batalhar na base do murro!')
    elif len(equipamentos_pessoa) == 1:
        print(f'{pessoa} irá rumo a batalha com o equipamento: {equipamentos_pessoa[0]}!')
    else:
        ultimo_equipamento = equipamentos_pessoa.pop()        
        print(f'{pessoa} irá rumo a batalha com os seguintes equipamentos: {", ".join(equipamentos_pessoa)} e {ultimo_equipamento}!')
    
    linha = input().split("-")
    pessoa = linha[0]
    if pessoa != 'Parar':
        equipamentos_indesejados = linha[1:]