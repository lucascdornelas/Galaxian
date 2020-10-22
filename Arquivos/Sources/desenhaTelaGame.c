#include <GL/glew.h>
#include <GL/freeglut.h>
#include <time.h>
#include <math.h>
#include "../Headers/desenhaBackground.h"
#include "../Headers/tiro.h"
#include "../Headers/criaTiro.h"
#include "../Headers/desenhaEstrela.h"
#include "../Headers/desenhaTelaTutorial.h"
#include "../Headers/player.h"
#include "../Headers/criaSprite.h"
#include "../Headers/detectarColisao.h"
#include "../Headers/hudDisplay.h"
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

//Variaveis de controle
float posPlayerX = 17.0; //POSICIAL INICIAL DO PLAYER EM X

#define _LINHAS 5
#define _COLUNAS 9
Sprite navesInimigas[_LINHAS][_COLUNAS];

int contadorDeInimigosMortos = 0;

int controleEstrela = 0; //CONTROLE PARA ANIMAR A TELA
int tutorial; //VARIAVEL PARA DESENHAR A TELA DE TUTORIAL NO INICIO DO JOGO (1)
int statusPause; //PARA NAO ATUALIZAR QUANDO O P ESTIVER ATIVO (1)

#define _QuantidadeTirosPlayer 8
Tiro tirosPlayer[_QuantidadeTirosPlayer];

#define _QuantidadeTirosInimigos 20
Tiro tirosInimigo[_QuantidadeTirosInimigos];

int vidas;
float score;

Mix_Music *musicaDeFundo;
Mix_Music *musicaChampion;

void desenhaTelaGame()
{

  if(tutorial == 1) // SE AINDA NAO DESENHOU A TELA DE TUTORIAL
  {
    statusPause = 1; //PARA NAO ATUALIZAR O JOGO
    desenhaTelaTutorial();
    criandoVetorDeTiros(tirosPlayer);
    criandoVetorDeTiros(tirosInimigo);
    contadorDeInimigosMortos = 0;
    criandoInimigos();
    vidas = 3;
    score = 0;
    Mix_PlayMusic(musicaChampion,0);
    Mix_PlayMusic(musicaDeFundo,-1);
  }
  else
  {

    glClear(GL_COLOR_BUFFER_BIT);

    //Desenhos
    desenhabackground();
    desenhaPlayer(posPlayerX); //FUNÇÃO PARA REDESENHAR O PLAYER ENQUANTO ELE ESTIVER SE MOVENDO AO LONGO DO EIXO X
    desenhaTiro(tirosPlayer);
    desenhaTiro(tirosInimigo);
    desenhaInimigo();
    desenharEstrelas();

    detectaColisao();
    detectaColisaoDesfavoravel();
    display();
    glutSwapBuffers();
  }

}

void desenharEstrelas()
{
  int x,y;
  if(controleEstrela == 33)//DESENHANDO UMAS ESTRELAS ALEATORIAMENTE 1 VEZES POR SEGUNDO
  {
    srand(time(0)); // SORTEANDO DENTRO DA JANELA UMA POSICAO PARA A ESTRELA SER DESENHADA
    x = rand()%99;
    y = rand()%99;
    controleEstrela=0; // ZERANDO PARA REDESENHAR NOVAS ESTRELAS
    desenhaEstrela(x,y);

  }
}
