## TP1 - GALAXIAN
### Este jogo foi implementado em ambiente Linux.

### COMPUTAÇÃO GRÁFICA

### Engenharia de Computação

### Centro Federal de Educação Tecnológica de Minas Gerais - CEFET/MG

#### Semestre 2020.1 (ERE)

### Desenvolvedores:
*  **Erick Henrique Dutra de Souza.**
*  **Lucas Cota Dornelas.**

### Professor: 
* **Glender Brás.**

*Todas as imagens utilizadas para a elaboração gráfica do jogo, está incluída na pasta "Referências", no arquivo "REFERÊNCIAS"*

## Preview:

![Gamaplay do jogo]("./Screensshots/Galaxian.gif")

Instruções para instalação dos arquivos adicionais:
Este jogo é implementado em ambiente Linux, para implementação em outros sistemas operacionais, é necessário fazer a instalação das seguintes bibliotecas:
FreeGlut
Glew
SOIL
SDL

Para instalação em ambiente Linux:
Abra o terminal e digite os seguintes comandos:
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install freeglut3-dev                                                                       //FreeGlut
sudo apt-get install libglew-dev                                                                         //Glew           
sudo apt install libsoil-dev                                                                             //SOIL   
sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev             //SDL


Instruções para execução:
1- Acesse a pasta "Arquivos"
2- Acesse a pasta "MakeFile" e abra-a no Terminal
3- Digite o seguinte comando: "make run"

Implementações extras:
-Jogador andando
-Inimigos andando
-Cenário animado (Estrelas piscando aleatoriamente)
-Fase infinita (Toda vez que o jogador morrer ou ter êxito, basta apertar a tecla 'r' para reiniciar o jogo)
-Controle da nave via teclas 'a' e 'd'
-Controle da nave com o mouse
-Tela com razão de aspecto
-Telas de Tutorial, Pause, Reiniciar, GameOver e Congratulations implementadas, informando ações para o jogador
-Pontuação para o player a cada inimigo que ele consegue acertar um tiro, quanto mais próximo dele, maior é a pontuação. Esta exibida em um HUD ao canto da Tela
-Vidas para o player, a cada inimigo que consegue lhe acertar, é retirada uma vida. Esta exibida em um HUD ao canto da Tela
-Musica de fundo durante a execução do jogo

Video do jodo disponível no YouTube: https://youtu.be/VE8vOh23Nrc
