# -*- coding: utf-8 -*-
from random import randint

from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro : Tabuleiro, tipo : int):
        super().__init__(tabuleiro, tipo)
            

    def getJogada(self) -> (tuple[int, int]):
        jogada = self.regra1()
        if jogada is not None:
            return jogada

        jogada = self.regra2()
        if jogada is not None:
            return jogada

        jogada = self.regra3()
        if jogada is not None:
            return jogada

        jogada = self.regra4()
        if jogada is not None:
            return jogada

        jogada = self.regra5()
        if jogada is not None:
            return jogada

        jogada = self.regra6()
        if jogada is not None:
            return jogada
    
    # R1: Se você ou seu oponente tiver duas marcações em sequência, marque o quadrado restante.
    def regra1(self) -> (tuple[int, int]):
        
        # Verificação das Linhas
        for l in range(3):
            if sum(self.matriz[l]) == 2 or sum(self.matriz[l]) == 8:
                for c in range(3):
                    if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                        return (l, c)
                    
        # Verificação das Colunas
        for c in range(3):
            somaC = sum(self.matriz[l][c] for l in range(3))
            if somaC == 2 or somaC == 8:
                for l in range(3):
                    if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                        return (l, c)
                    
        # Verificação da Diagonal Principal
        somaDP = 0
        for l in range(3):
            somaDP += self.matriz[l][l]
            if somaDP == 2 or somaDP == 8:
                for c in range(3):
                    if self.matriz[c][c] == Tabuleiro.DESCONHECIDO:
                        return (c, c)
                    
        # Verificação da Diagonal Secundária
        somaDS = 0
        for l in range(3):
            somaDS += self.matriz[2 - l][l]
            if somaDS == 2 or somaDS == 8:
                for c in range(3):
                    if self.matriz[2 - c][c] == Tabuleiro.DESCONHECIDO:
                        return (2 - c, c)
                    
        return None

    # R2: Se houver uma jogada que crie duas sequências de duas marcações, use-a. 
    def regra2(self) -> (tuple[int, int]):
        for l in range(3):
            for c in range(3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    # Aqui vamos ir testando todas as jogadas possíveis e ver se esse "O" gera duas condições de vitória
                    self.matriz[l][c] = 1  # Marca temporariamente com "O"
                    vitorias = self.checarPossibilidades()
                    self.matriz[l][c] = Tabuleiro.DESCONHECIDO  # Desfaz a hipótese
                    if vitorias >= 2:
                        return (l, c)
        return None


    def checarPossibilidades(self):
        vitorias = 0

        # Verificar linhas
        for linha in self.matriz:
            if linha.count(1) == 2 and linha.count(Tabuleiro.DESCONHECIDO) == 1:
                vitorias += 1

        # Verificar colunas
        for c in range(3):
            coluna = [self.matriz[r][c] for r in range(3)]
            if coluna.count(1) == 2 and coluna.count(Tabuleiro.DESCONHECIDO) == 1:
                vitorias += 1

        # Verificar diagonais
        diagonais = [
            [self.matriz[i][i] for i in range(3)], # Principal
            [self.matriz[i][2 - i] for i in range(3)] # Secundária
        ]
        for diagonal in diagonais:
            if diagonal.count(1) == 2 and diagonal.count(Tabuleiro.DESCONHECIDO) == 1:
                vitorias += 1

        return vitorias
    
    # R3: Se o quadrado central estiver livre, marque-o.
    def regra3(self) -> (tuple[int, int]):
        if self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
            return (1, 1)
        
        return None
    
    # R4: Se seu oponente tiver marcado um dos cantos, marque o canto oposto.
    def regra4(self) -> (tuple[int, int]):
        for canto in [(0, 0), (0, 2), (2, 0), (2, 2)]:
            (l, c) = canto
            oposto = self.matriz[2 - l][2 - c]
            if self.matriz[l][c] == 4 and oposto == Tabuleiro.DESCONHECIDO:
                return (2 - l, 2 - c)

        return None
    
    # R5: Se houver um canto vazio, marque-o.
    def regra5(self) -> (tuple[int, int]):
        for l, c in [(0, 0), (0, 2), (2, 0), (2, 2)]:
            if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                return (l, c)
        return None
    
    # R6: Marque arbitrariamente um quadrado vazio.
    def regra6(self) -> (tuple[int, int]):
        for l in range(3):
            for c in range(3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    return (l, c)
                
        return None