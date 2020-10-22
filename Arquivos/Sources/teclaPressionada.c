#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "../Headers/desenhaTelaGame.h"
#include "../Headers/desenhaTelaPause.h"
#include "../Headers/desenhaConfirmacao.h"
#include "../Headers/teclaEspecial.h"
#include "../Headers/tiro.h"
#include "../Headers/desenhaTelaTutorial.h"


int controleExit;//CONTROLE PARA SAIR DO JOGO
int statusPause;//STATUS DA TECLA DE PAUSE
int controleR;//CONTROLE DE REINICIAR O JOGO
int controleY = -1; //CONTROLE YES
int controleN = 1; //CONTROLE NOT
int controleTiro;

int tutorial; //VARIAVEL PARA DESENHAR A TELA DE TUTORIAL NO INICIO DO JOGO (1)

float posPlayerX; //POSICIAL INICIAL DO PLAYER EM X


void teclaPressionada(unsigned char key, int x, int y)
{
    // vê qual tecla foi pressionada
    switch(key)
    {
    case 27:      // Tecla "ESC"
        if(controleExit == -1)
        {
          controleExit *=(-1);
          glutDisplayFunc(desenhaConfirmacao);
          glutPostRedisplay();
          break;
        }

    case 'a':
        if(posPlayerX > 7.5)//0 + (larguraDaNave/ 2)
        {
            posPlayerX--;
        }
        glutPostRedisplay();
        break;

    case 'd':
        if(posPlayerX < 92.5)//100 - (larguraDaNave/ 2)
        {
            posPlayerX++;
        }
        glutPostRedisplay();
        break;

    case 'p'://PAUSE 
        statusPause *=(-1);//PARA SABER QUANDO APERTOU E DPS DE APERTAR A TELA PAUSE

        glutDisplayFunc(desenhaTelaPause);
        glutPostRedisplay();
        break;

    case 'r':
    if(controleR == 1)
    {
      if(statusPause == -1) // PARA IDENTIFICAR SE A TECLA P ESTÁ COM SINAL -1, QUE É PAUSADO, CASO ESTEJA PAUSADO, O JOGO REINCIARÁ PAUSADO
      {
        statusPause *=(-1);
      }
      controleR *=(-1);
      statusPause *=(-1);

      glutDisplayFunc(desenhaConfirmacao);
      glutPostRedisplay();
      break;
    }

    case 'y'://AQUI ESTA AS CONDIÇÕES PARA REINICIAR E SAIR JUNTAS
    controleY *=(-1);
    if((controleY == 1) && (controleExit == 1))
    {
      exit(0);
      break;
    }
    if((controleY == 1) && (controleR == -1) && (controleExit != 1))
    {
      posPlayerX = 50.0;
      tutorial *= -1;
      glutDisplayFunc(desenhaTelaGame);
      glutPostRedisplay();
      controleY *=(-1);
      controleR *=-(1);
      break;
    }

    case 'n':
    if((controleN == 1) && ((controleExit == 1) || (controleR == -1)))
    {
      if(controleExit == 1)
      {
        controleExit *=-1;
      }
      if(controleR == -1)
      {
        controleR *=-1;
      }
      glutDisplayFunc(desenhaTelaGame);
      glutPostRedisplay();
      break;
    }

    case 32: //tecla ESPAÇO
    if(statusPause == 1) //NAO ATIRAR DURANTE O PAUSE
    {
      break;
    }
      controleTiro = 1; //APERTOU A TECLA DE ESPAÇO
      glutDisplayFunc(desenhaTelaGame);
      glutPostRedisplay();
      break;


    case 13: //tecla ENTER
        statusPause *=-1; // PARA O JOGO NAO RODAR ENQUANTO ESTIVER NA TELA TUTORIAL
        tutorial = -1; //PARA SAIR DO TUTORIAL
        glutPostRedisplay();
        break;
        default:
        break;
    }
}
