#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include "../Headers/escreveTexto.h"
#include "../Headers/setup.h"
#include "../Headers/desenhaTelaPause.h"
#include "../Headers/redimensionada.h"

float vertical;
float horizontal;
float razaoJanela;

GLuint idMouse, idSetas, idAD, idSpace, idTeste;
int tutorial = 1;

void desenha(GLuint textura, int xInicial, int yInicial, int xFinal, int yFinal)
{
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura);
        glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);
        glVertex2f(xInicial, yInicial); // v3---v2
        glTexCoord2f(1, 0);
        glVertex2f(xFinal, yInicial); // |     |
        glTexCoord2f(1, 1);
        glVertex2f(xFinal, yFinal); // |     |
        glTexCoord2f(0, 1);
        glVertex2f(xInicial, yFinal); // v0---v1
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void desenhaTelaTutorial()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,1.0,1.0);//BRANCO
     escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24,"TUTORIAL", 36.2 + (horizontal/100 * razaoJanela), 93 + vertical/100 * razaoJanela, 0);
     escreveTexto(GLUT_BITMAP_HELVETICA_18,"MOVIMENTACAO", 34.7 + horizontal/100, 80 + vertical/100 + razaoJanela, 0);
     desenha(idMouse, 10, 65, 30, 75);
     desenha(idSetas, 40, 65, 60, 75);
     desenha(idAD, 70, 65, 90, 75);
     escreveTexto(GLUT_BITMAP_HELVETICA_18,"ATIRAR", 42.3 + (horizontal/100 + 0), 50 + vertical/100 * razaoJanela, 0);
     desenha(idSpace, 40, 40, 60, 49);
     escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24,"PRESSIONE ENTER", 28.3 + (horizontal/100 * razaoJanela), 25+vertical/100 * razaoJanela, 0);
     //glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,1.0,0.0);//AMARELO
     escreveTexto(GLUT_BITMAP_HELVETICA_18,"DESENVOLVIDO POR: Erick Henrique e Lucas Cota", 6.5 + (horizontal/100 * razaoJanela*razaoJanela), 10+vertical/100 * razaoJanela, 0);
     glutSwapBuffers();
}
