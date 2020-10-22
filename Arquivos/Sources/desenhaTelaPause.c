#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Headers/escreveTexto.h"
#include "../Headers/desenhaTelaGame.h"
#include "../Headers/redimensionada.h"

float vertical;
float horizontal;
float razaoJanela;

int statusPause = -1;

void desenhaTelaPause()//DESENHAR ALGUMAS PALAVRAS NA TELA DE PAUSE
{
  if((statusPause == 1 ))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);//AMARELO
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24,"PAUSE", 42+ horizontal/100 , 90+ vertical/100, 0);//PAUSE TOPO
    escreveTexto(GLUT_BITMAP_HELVETICA_18,"CONTINUE ->P", 37+ horizontal/100 , 60+ vertical/100 , 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_18,"REINICIAR ->R", 37+ horizontal/100 , 40+ vertical/100 , 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_18,"SAIR ->ESC", 39.5+ horizontal/100 , 20+ vertical/100 , 0);
    glutSwapBuffers();
  }
  else
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);//BRANCO
    desenhaTelaGame();
  }
}
