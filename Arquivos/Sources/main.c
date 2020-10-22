#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "../Headers/setup.h"
#include "../Headers/atualizaCena.h"
#include "../Headers/desenhaTelaGame.h"
#include "../Headers/movimentoMouse.h"
#include "../Headers/redimensionada.h"
#include "../Headers/teclaEspecial.h"
#include "../Headers/teclaPressionada.h"
#include "../Headers/musica.h"
#include "../Headers/desenhaTelaCongratulations.h"

Mix_Music *musicaDeFundo;
Mix_Music *musicaChampion;

int verificadorMusica = 1;

int main(int argc, char** argv)
{
   inicializarMusica();
   carregarMusica();

   glutInit(&argc, argv);
   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("GALAXIAN");
   setup();

   // Registra callbacks para eventos
   glutDisplayFunc(desenhaTelaGame);
   glutReshapeFunc(redimensionada);
   glutKeyboardFunc(teclaPressionada);
   glutSpecialFunc(teclaEspecial);
   glutPassiveMotionFunc(movimentoMouse);
   glutTimerFunc(33, atualizaCena, 0);

   //INICIALIZANDO A MÚSICA DE FUNDO
   //Mix_PlayMusic(musicaDeFundo, -1);

   glutMainLoop();
   return 0;
}
