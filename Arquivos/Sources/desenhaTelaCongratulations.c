#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "../Headers/escreveTexto.h"
#include "../Headers/redimensionada.h"


float vertical;
float horizontal;
float razaoJanela;
int statusPause;
int verificadorDeMusica;

Mix_Music *musicaChampion;
Mix_Music *musicaDeFundo;

int verificador = 1;

void desenhaTelaCongratulations()
{
     if(verificador == 1)
     {
          Mix_PlayMusic(musicaChampion, 0);
          Mix_PlayMusic(musicaChampion, -1);
          verificador = 0;
     }
     
     verificadorDeMusica = 0;
     statusPause = 1;
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,1.0,1.0);//BRANCO
     escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24,"WE ARE THE CHAMPIONS", 33.3 + (horizontal/100 + razaoJanela), 25+vertical/100 + razaoJanela, 0);


     glColor3f(1.0,1.0,0.0);//AMARELO
     escreveTexto(GLUT_BITMAP_HELVETICA_18,"DESENVOLVIDO POR: Erick Henrique e Lucas Cota", 6.5 + (horizontal/100 * razaoJanela*razaoJanela), 10+vertical/100 * razaoJanela, 0);
     glutSwapBuffers();
     glutSwapBuffers();
}
