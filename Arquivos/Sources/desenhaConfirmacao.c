#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Headers/escreveTexto.h"
#include "../Headers/redimensionada.h"

float vertical;
float horizontal;
float razaoJanela;

int controleExit = -1; //CONTROLE PARA SAIR DO JOGO
int controleR = 1; //CONTROLE PARA REINICIAR O JOGO

void desenhaConfirmacao()
{
  if((controleExit == 1))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);//AMARELO
    escreveTexto(GLUT_BITMAP_HELVETICA_18, "DESEJA REALMENTE SAIR? Y/N", 21+ horizontal/100 + razaoJanela, 50+ vertical/100 + razaoJanela, 0);
    glutSwapBuffers();
  }
  if((controleR == -1) && (controleExit != 1))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);//AMARELO
    escreveTexto(GLUT_BITMAP_HELVETICA_18, "DESEJA REALMENTE REINICIAR? Y/N", 17+ horizontal/100 + razaoJanela, 50+ vertical/100 + razaoJanela, 0);
    glutSwapBuffers();
  }
}
