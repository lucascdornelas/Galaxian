# GALAXIAN 

## Trabalho Prático 1 - 🎮 COMPUTAÇÃO GRÁFICA
[![C Badge](https://img.shields.io/badge/-C-A8B9CC?style=flat-square&logo=C&logoColor=444)]()
[![OpenGL Badge](https://img.shields.io/badge/-OpenGL-5586A4?style=flat-square&logo=OpenGL&logoColor=111)]()

### Engenharia de Computação - CEFET/MG
#### Semestre 2020.1 (ERE)
### Professor: 
* **Glender Brás.**

---

## Desenvolvedores:
*  **Erick Henrique**
*  **Lucas Cota**


## **Previews:**

![Exemplo da gamaplay do jogo](https://raw.githubusercontent.com/lucascdornelas/Galaxian/main/Screenshots/Galaxian.gif)

#### Algumas Telas: 
* Gameplay: 
![Tela Gameplay](https://raw.githubusercontent.com/lucascdornelas/Galaxian/main/Screenshots/Player%20com%20alguns%20%C3%AAxitos%20durante%20a%20execu%C3%A7%C3%A3o.png)

* Game Over: 
![Tela Game-Over](https://raw.githubusercontent.com/lucascdornelas/Galaxian/main/Screenshots/Tela%20Game%20Over.png)

* Tutorial:
![Tela Tutorial](https://raw.githubusercontent.com/lucascdornelas/Galaxian/main/Screenshots/Tela%20Tutorial.png)

---

## Instruções para instalação dos arquivos adicionais:

### Este jogo foi implementado no ambiente Linux e para compilar ele no mesmo ambiente é necessário fazer a instalação das seguintes bibliotecas:
* FreeGlut
* Glew
* SOIL
* SDL

### **Para instalação em ambiente Linux:**
No o terminal e digite os seguintes comandos:
* **Certifique que esta tudo funcionando:** 
```
sudo apt-get update
```
```
sudo apt-get install build-essential
```
* **FreeGlut:**
```
sudo apt-get install freeglut3-dev
```
* **Glew:**
```
sudo apt-get install libglew-dev
```
* **SOIL:**
```
sudo apt install libsoil-dev
```
* **SDL:**
```
sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev
```

### Instruções para execução:
1. Acesse a pasta "Arquivos"

2. Acesse a pasta "MakeFile" e abra-a no Terminal

3. Digite o seguinte comando: "make run"
```
make run
```
---

### Implementações:
- Jogador andando
- Inimigos andando
- Cenário animado (Estrelas piscando aleatoriamente)
- Fase infinita (Toda vez que o jogador morrer ou ter êxito, basta apertar a tecla 'r' para reiniciar o jogo)
- Controle da nave via teclas 'a' e 'd'
- Controle da nave com o mouse
- Tela com razão de aspecto
- Telas de Tutorial, Pause, Reiniciar, GameOver e Congratulations implementadas, informando ações para o jogador
- Pontuação para o player a cada inimigo que ele consegue acertar um tiro, quanto mais próximo dele, maior é a pontuação. Esta exibida em um HUD ao canto da Tela
- Vidas para o player, a cada inimigo que consegue lhe acertar, é retirada uma vida. Esta exibida em um HUD ao canto da Tela
- Musica de fundo durante a execução do jogo

### Video do jodo disponível no YouTube: 
**[Clique Aqui](https://youtu.be/VE8vOh23Nrc)**


--- 

### Referencias: 

*Obs.: Todas as imagens utilizadas para a elaboração gráfica do jogo, está incluída na pasta "Referências", no arquivo "REFERÊNCIAS"*

---
