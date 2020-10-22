#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Headers/player.h"

float _TamanhoNave;
float posPlayerX;

void teclaEspecial(int key, int x, int y)//IDENTIFICAR QUE ESTA PRESSIONANDO SETA PARA DIREITA E SETA PARA ESQUERDA
{
  switch (key)
  {
    case GLUT_KEY_RIGHT:
    if(posPlayerX < 100 - (_TamanhoNave/2.0))//TEMOS TAMANHO A DIREITA MAXIMO, LARGURA TOTAL DA JANELA ('100')- TAMANHO DA NAVE / 2, POIS A NAVE É DESENHADA EM SEU PONTO CENTRAL
    {
      posPlayerX+=2;
    }
    glutPostRedisplay();
    break;

    case GLUT_KEY_LEFT:
    if(posPlayerX > 0 + (_TamanhoNave/2.0))//TEMOS TAMANHO A ESQUERDA MAXIMO, LARGURA MINIMA DA JANELA ('0')+ TAMANHO DA NAVE / 2, POIS A NAVE É DESENHADA EM SEU PONTO CENTRAL
    {
      posPlayerX-=2;
    }
    glutPostRedisplay();
    break;

    default:
    break;
  }
}
