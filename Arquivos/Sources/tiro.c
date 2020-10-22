#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Headers/criaSprite.h"
#include "../Headers/setup.h"
#include "../Headers/criaTiro.h"
#include "../Headers/player.h"

#define quantTiroPlayer 8
Tiro vetorDeTiros[quantTiroPlayer];

#define posPlayerY 10
float posPlayerX;

int j = 0;
void desenhaTiro(Tiro * tiro)
{
  for(int i = 0; i < quantTiroPlayer; i++)
  {
    Vetor2d A, B, C, D;

    A.x = tiro[i]._PosX-tiro[i]._TamanhoTiro / 2;
    A.y = tiro[i]._PosY+tiro[i]._TamanhoTiro / 2;

    B.x = tiro[i]._PosX+tiro[i]._TamanhoTiro / 2;
    B.y = tiro[i]._PosY+tiro[i]._TamanhoTiro / 2;

    C.x = tiro[i]._PosX-tiro[i]._TamanhoTiro / 2;
    C.y = tiro[i]._PosY-tiro[i]._TamanhoTiro / 2;

    D.x = tiro[i]._PosX+tiro[i]._TamanhoTiro / 2;
    D.y = tiro[i]._PosY-tiro[i]._TamanhoTiro / 2;

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
      glTexCoord2f(0, 0);
      glVertex2f(C.x, C.y);

      glTexCoord2f(1, 0);
      glVertex2f(D.x, D.y);

      glTexCoord2f(1, 1);
      glVertex2f(B.x, B.y);

      glTexCoord2f(0, 1);
      glVertex2f(A.x, A.y);
    glEnd();
    glutPostRedisplay();

    if(tiro[i].Sentido == 1)
    {
      tiro[i]._PosY += tiro[i]._Velociade;
    }else if(tiro[i].Sentido == -1)
    {
      tiro[i]._PosY -= tiro[i]._Velociade;
    }
  }
}

void criandoVetorDeTiros(Tiro * tiros)
{
    for(int i = 0; i < quantTiroPlayer; i++)
    {
        tiros[i]._PosX = -5; //PARA NAO TER CHANCE DE COMEÇAR A ATIRAR DENTRO DA JANELA
        tiros[i]._PosY = 0;
        tiros[i].Sentido = 0;
        tiros[i]._TamanhoTiro = 0.7;
        tiros[i]._Velociade = 1;
    }
}

void modificarTirosPlayer(Tiro * tiros, int sentido)
{
  for(int i = 0; i < quantTiroPlayer; i++)
  {
    float naoIniciado = -5.0;
    if(tiros[i]._PosX == naoIniciado)
    {
      tiros[i]._PosX = posPlayerX;
      tiros[i]._PosY = posPlayerY;
      tiros[i].Sentido = sentido;
      i = quantTiroPlayer;
    }else if(i == quantTiroPlayer - 1)
    {
      tiros[j]._PosX = posPlayerX;
      tiros[j]._PosY = posPlayerY;
      tiros[j].Sentido = sentido;
      j++;

      if(j==quantTiroPlayer)
        j=0;
    }
  }
}

void modificarTirosInimigo(Tiro * tiros, int sentido, Sprite nave)
{
  for(int i = 0; i < quantTiroPlayer; i++)
  {
    if(tiros[i]._PosX == -5)
    {
      tiros[i]._PosX = nave.posicao.x;
      tiros[i]._PosY = nave.posicao.y;
      tiros[i].Sentido = sentido;

      i=quantTiroPlayer;
    }

    else if(i == quantTiroPlayer - 1)
    {
      tiros[j]._PosX = nave.posicao.x;
      tiros[j]._PosY = nave.posicao.y;
      tiros[j].Sentido = sentido;
      j++;

      if(j==quantTiroPlayer)
      j=0;
    }
  }
}
