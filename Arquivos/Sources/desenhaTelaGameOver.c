#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Headers/escreveTexto.h"
#include "../Headers/redimensionada.h"
#include "../Headers/criaSprite.h"
#include "../Headers/criaInimigo.h"

float vertical;
float horizontal;
float razaoJanela;

int statusPause;

#define _LINHAS 5
#define _COLUNAS 9

Sprite navesInimigas[_LINHAS][_COLUNAS];



void desenhaTelaGameOver()
{
     statusPause = 1;
     
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,1.0,0.0);//AMARELO
     escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24,"GAME OVER BABY", 28+ horizontal/100 + razaoJanela, 80+ vertical/100 + razaoJanela, 0);

     glColor3f(1.0,0.0,0.0);//VERMELHO
     escreveTexto(GLUT_BITMAP_HELVETICA_18,"INSIRA OUTRA FICHA", 30+ horizontal/100 + razaoJanela, 50+ vertical/100 + razaoJanela, 0);

     escreveTexto(GLUT_BITMAP_HELVETICA_18,"PRESSIONE R PARA REINICIAR",22.6 + horizontal/100 + razaoJanela,20+ vertical/100 + razaoJanela,0);

    if(statusPause == 1)
    {
        statusPause *= -1; 
        for(int i=0; i<_LINHAS;i++)
        {
            for(int j=0; j<_COLUNAS;j++)
            {
                navesInimigas[i][j].posicao.y =-80; // PARA NÃO DESENHAR OS INIMOS NA JANELA
            }
        }
    }
}
