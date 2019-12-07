# Jenga Builder

## Conceito do projeto
O projeto visa a elaboração de um robô construtor de torres de Jenga, um jogo de habilidade física em que jogadores devem retirar uma peça por vez de uma torre previamente construída. Espera-se, com o desenvolvimento desse projeto, estudar mais profundamente os fundamentos da robótica e as práticas da área em um projeto semelhante aos robôs utilizados na industria atual.

A proposta do projeto é desenvolver e construir um robô capaz de construir torres de Jenga. Uma torre de Jenga é composta de peças padronizadas dispostas três à três em níveis, sendo que cada nível é rotacionado 90º em relação ao anterior, conforme a figura abaixo:

<img src="https://github.com/eijiuema/hackerspace2019-jengabuilder/blob/master/imagens/torre_de_jenga.jpg" height=300>
  
## Pré-requisitos e recursos utilizados

Para a impressão dos modelos 3D **foi necessária uma impressora com área de impressão de no mínimo 190 x 190mm**, os modelos podem ser encontrados na pasta *modelos-impressao*.

- 2x Motores servo 9g SG90 TowerPro
- 4x Motores de passo 8BYJ-48
- 4x Drivers ULN2003
- 1x Arduino Uno
- 1x Breadboard
- 1x Elástico
- 1x Rolamento 3 x 13 x 5mm 633zz
- 1x Parafuso M3 15mm + Arruela
- 2x Parafusos M3 6mm
- 1x Parafuso M2.5 10mm
- 1x Folha em EVA
- 1x Fonte de energia 5Vdc de 2A
- 4x Parafusos #6-32 x 2"
- 8x Parafusos #6-32 x 1-1/4"
- 4x Parafusos #6-32 x 3/4"
- 26x Porcas #6

Para controlar os motores de passo, foi necessária a biblioteca [CheapStepper](https://github.com/tyhenry/CheapStepper).
  
## Passo a passo

1. Modificamos o modelo do Eixo Z do projeto [RPieces-TableTopXYZ](https://www.thingiverse.com/thing:2166533) para adequa-lo à altura da torre de Jenga.
2. Imprimimos os modelos 3D.
3. Implementamos funções para abrir, fechar e girar a garra, e para mover os eixos.
4. Implementamos funções para construir niveis pares, e niveis ímpares da torre, usando as funções citadas anteriormente.
5. Implementamos um programa que dadas as dimensões das peças, constrói uma torre de Jenga da altura desejada (máx 15 niveis).

Obs: as funções e o programa citados acima estão disponíveis no arquivo *jengabuilder.ino*

## Experimento

O robô pegará as peças em uma posição pré-definida utilizando a garra, a levará até o local da próxima peça da torre (evitando a colisão com as peças já posicionadas) e a girará se necessário.

O robô não mantém um estado interno das posições das peças colocadas, o seu ambiente é limitado à posição inicial da peça, à posição da garra e à posição final da peça, portanto depende de ajuda externa (para sempre ter uma peça disponível na posição inicial) e não é capaz de corrigir falhas ou imprevistos.

É esperado que o robô seja capaz de montar pelo menos 3 níveis da torre precisamente. Uma quantidade maior de níveis é possível, mas provavelmente terão menor precisão, uma vez que a acurácia do posicionamento das peças dos níveis anteriores se acumula ao longo da construção.

## Estado atual do projeto e resultados parciais

Por enquanto, apenas a garra e um eixo foram construídos. Com essas partes foi construída uma estrutura que demonstra a movimentação de uma peça em um eixo:

<img src="https://github.com/eijiuema/hackerspace2019-jengabuilder/blob/master/imagens/demo.gif">

## Autores
* Ágata Rangel Drigo
* Anderson Pinheiro Garrote
* André Matheus Bariani Trava
* Thiago Yussuki Uehara
* Gabriel Eiji Uema Martin

## Demais anotações e referências

A estrutura de eixos 3D foi baseada no projeto [RPieces-TableTopXYZ](https://www.thingiverse.com/thing:2166533).

A estrutura da garra foi baseada no projeto [Robotic Gripper / Clamp. Two Degrees of freedom. Servo controlled](https://www.thingiverse.com/thing:3648782).

Para o controle dos motores de passo foi usada a biblioteca [CheapStepper](https://github.com/tyhenry/CheapStepper).

## Imagens/screenshots
É necessário colocar pelo menos 3 imagens/screenshots do projeto, porém fiquem a vontade para colocar mais, a medida do que vocês acharem legal para ilustrar o projeto.

Para colocar imagens no Readme do Github, vocês podem usar o seguinte comando (abrir este Readme no modo raw ou como txt):

![Imagem](https://github.com/Infinitemarcus/Hackerspace-template/blob/master/exemplo.png)

É preferível que vocês usem imagens hospedadas no próprio GitHub do projeto. É só referenciar o link delas no comando acima.
