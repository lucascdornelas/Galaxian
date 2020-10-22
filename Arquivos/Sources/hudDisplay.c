#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include "../Headers/escreveTexto.h"

float score;
int vidas;
float multiplicadorScore;

char scoreDisplay[100];
char vidasDisplay[50];

    void display()
    {
        //EXIBINDO O DISPLAY
        glColor3f(1.0,1.0,1.0);//BRANCO
        sprintf(scoreDisplay, "%.0f",score);
        sprintf(vidasDisplay, "%d", vidas);
        escreveTexto(GLUT_BITMAP_HELVETICA_18,"score", 75, 3, 0);
        escreveTexto(GLUT_BITMAP_HELVETICA_18,scoreDisplay, 85, 3, 0);//DISPLAY
        escreveTexto(GLUT_BITMAP_HELVETICA_18,"vidas", 2, 3, 0);
        escreveTexto(GLUT_BITMAP_HELVETICA_18,vidasDisplay, 12, 3, 0);//DISPLAY
        glutSwapBuffers();
    }
