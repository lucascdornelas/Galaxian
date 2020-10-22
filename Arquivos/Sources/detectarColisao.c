#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <math.h>
#include "../Headers/criaSprite.h"
#include "../Headers/tiro.h"
#include "../Headers/criaTiro.h"
#include "../Headers/player.h"
#include "../Headers/desenhaTelaGameOver.h"

#define _LINHAS 5
#define _COLUNAS 9
Sprite navesInimigas[_LINHAS][_COLUNAS];

#define _QuantidadeTirosPlayer 8
Tiro tirosPlayer[_QuantidadeTirosPlayer];
Sprite navePlayer;

#define _QuantidadeTirosInimigos 20
Tiro tirosInimigo[_QuantidadeTirosInimigos];

int contadorDeInimigosMortos;

int vidas;
float score;

float multiplicadorScore;


// COLISAO ENTRE O TIRO DO PLAYER E OS INIMIGOS
double distanciaEntre(Sprite nave, Tiro tiro)
{
  double somaDosQuadradosDiferenca = pow((nave.posicao.x - tiro._PosX), 2) + pow((nave.posicao.y - tiro._PosY), 2);
  double raizSoma = sqrt(somaDosQuadradosDiferenca);
  return raizSoma;
}

void detectaColisao()
{
  for(int i = 0; i < _LINHAS; i++)
  {
    for(int j = 0; j < _COLUNAS; j++)
    {
      for(int t = 0; t < _QuantidadeTirosPlayer; t++)
      {
        if(distanciaEntre(navesInimigas[i][j], tirosPlayer[t]) < navesInimigas[i][j].tamanho.x/2 && navesInimigas[i][j].status == 1)
        {
          tirosPlayer[t]._PosX = -5;
          navesInimigas[i][j].status = 0;
          contadorDeInimigosMortos++;
          score += navesInimigas[i][j].posicao.y*multiplicadorScore;
        }

      }
    }
  }
}

// COLISAO ENTRE O TIRO DO INIMIGO COM O PLAYER

void detectaColisaoDesfavoravel()
{
  if(vidas == 0)
  {
    desenhaTelaGameOver();
  }

  for(int i = 0; i < _QuantidadeTirosInimigos; i++)
  {
    if(distanciaEntre(navePlayer, tirosInimigo[i])  < navePlayer.tamanho.y/2)
    {
      vidas--;
      tirosInimigo[i]._PosY = -50;
    }
  }
}
