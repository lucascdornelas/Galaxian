#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <time.h>
#include "../Headers/criaSprite.h"
#include "../Headers/criaTiro.h"
#include "../Headers/player.h"
#include "../Headers/tiro.h"
#include "../Headers/criaInimigo.h"
#include "../Headers/desenhaTelaGame.h"
#include "../Headers/desenhaTelaPause.h"
#include "../Headers/teclaEspecial.h"
#include "../Headers/teclaPressionada.h"
#include "../Headers/movimentoMouse.h"
#include "../Headers/escreveTexto.h"

int controleEstrela; //PARA FAZER ANIMAÇÕES DE ESTRELA
int statusPause; //PARA NAO ATUALIZAR QUANDO O P ESTIVER ATIVO (1)

float posPlayerX;

int direcaoDoInimigo = 1;
#define _LINHAS 5
#define _COLUNAS 9

Sprite navesInimigas[_LINHAS][_COLUNAS];

int controleTiro = -1;
#define quantTiroPlayer 10
Tiro tirosPlayer[quantTiroPlayer];

Vetor2d posicaoMouse;

#define _QuantidadeTirosInimigos 20
Tiro tirosInimigo[_QuantidadeTirosInimigos];

int timer = 0;

float score;
float multiplicadorScore;

void atualizaCena(int valorQualquer)
{
      if(statusPause != 1)
      {
        controleEstrela++;
        controlePlayer();
        movimentoInimigos();
        controleTiroInimigos();
        glutPostRedisplay();
      }
    glutTimerFunc(33, atualizaCena, 0);//33
}

void controleTiroInimigos()
{
  //SORTEAR INIMIGO ALEATORIO PARA ATIRAR
  timer++;
  if(timer == 33)
  {
      srand(time(0));
      int i = rand() % _LINHAS;
      int j = rand() % _COLUNAS;
      timer = 0;

      if(navesInimigas[i][j].status == 1)
      {
          modificarTirosInimigo(tirosInimigo, -1, navesInimigas[i][j]);
      }
      else
      {
        controleTiroInimigos();
      }
  }
}

void movimentoInimigos()
{
  //INIMIGO ANDANDO PARA A DIREITA
  if(direcaoDoInimigo == 1)
  {
    if(navesInimigas[0][8].posicao.x < 95)
    {
      for(int i = 0; i < _LINHAS ; i++)
      {
        for( int j = 0; j < _COLUNAS ; j++)
        {
            navesInimigas[i][j].posicao.x += 0.6;
        }
      }
    }
    else
    {
      for(int i = 0; i < _LINHAS ; i++)
      {
        for( int j = 0; j < _COLUNAS ; j++)
        {
            navesInimigas[i][j].posicao.y-= 0.6;
        }
      }
      direcaoDoInimigo *= -1;
    }
  }
  //INIMIGO ANDANDO PARA A ESQUERDA
  else
  {
    if(navesInimigas[0][0].posicao.x > 5)
    {
      for(int i = 0; i < _LINHAS ; i++)
      {
        for( int j = 0; j < _COLUNAS ; j++)
        {
            navesInimigas[i][j].posicao.x-= 0.6;
            multiplicadorScore += 0.01;
        }
      }
    }
    else
    {
      for(int i = 0; i < _LINHAS ; i++)
      {
        for( int j = 0; j < _COLUNAS ; j++)
        {
            navesInimigas[i][j].posicao.y-= 0.6;
        }
      }
      direcaoDoInimigo *= -1;
    }
  }
}

void controlePlayer()
{
  //SE APERTAR O ESPAÇO
  if(controleTiro == 1)
  {
    modificarTirosPlayer(tirosPlayer ,1);
    desenhaTiro(tirosPlayer);
    controleTiro = -1;
  }
  //MOUSE CONTROLANDO O PLAYER
  if(posicaoMouse.x != 0)
  {
      posPlayerX = posicaoMouse.x;
      posicaoMouse.x = 0;
  }
}
