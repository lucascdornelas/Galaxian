#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Headers/criaSprite.h"
#include "../Headers/player.h"
#include "../Headers/setup.h"
#include "../Headers/desenhaTelaGameOver.h"
#include "../Headers/desenhaTelaCongratulations.h"

//TAMANHO NAVE INIMIGO comprimento x largura
#define tamanhoNaveInimigos 8

//Posição inicial dos inimigos, 5 linhas e 9 colunas
#define _LINHAS 5
#define _COLUNAS 9
#define posInimigoX 5
#define posInimigoY 95

//TEXTURA INIMIGO
GLuint idSpriteInimigos[0];

//PARA VERIFICAR SE O JOGADOR GANHOU A PARTIDA
int contadorDeInimigosMortos;

Sprite navesInimigas[_LINHAS][_COLUNAS];

void criandoInimigos()
{
  float y = posInimigoY;
  for(int i = 0; i < _LINHAS; i++)
  {
    float x = posInimigoX;
    for(int j = 0; j < _COLUNAS; j++)
    {
      navesInimigas[i][j] = criaSprite(x, y, tamanhoNaveInimigos, tamanhoNaveInimigos);
      x+=(10);
    }
    y-=(9+5/3);
  }
}

void desenhaInimigo()
{
  for(int i = 0; i < _LINHAS; i++)
  {
    for(int j = 0; j < _COLUNAS; j++)
    {
      if(contadorDeInimigosMortos == _LINHAS * _COLUNAS)
      {
        desenhaTelaCongratulations();
      }
      if(navesInimigas[i][j].status == 1)
      {
        if(navesInimigas[i][j].posicao.y < (solicitaYPlayer())) // SE O INIMIGO CHEGAR NO PLAYER
        {
          desenhaTelaGameOver();
        }
        glColor4f(1.0, 1.0, 1.0, 1.0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idSpriteInimigos[0]);
        glPushMatrix();

        Vetor2d A, B, C, D;

        A.x = -navesInimigas[i][j].tamanho.x / 2;
        A.y = navesInimigas[i][j].tamanho.y / 2;

        B.x = navesInimigas[i][j].tamanho.x / 2;
        B.y = navesInimigas[i][j].tamanho.y / 2;

        C.x = -navesInimigas[i][j].tamanho.x / 2;
        C.y = -navesInimigas[i][j].tamanho.y / 2;

        D.x = navesInimigas[i][j].tamanho.x / 2;
        D.y = -navesInimigas[i][j].tamanho.y / 2;

        glTranslatef(navesInimigas[i][j].posicao.x, navesInimigas[i][j].posicao.y, 0.0);
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
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
      }
    }
  }
}
