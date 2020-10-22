#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include "../Headers/carregaTextura.h"
#include <stdio.h>

GLuint idBackground, idSpritePlayer, idSpriteInimigos[2], idEstrela, idMouse, idSetas, idAD, idSpace;

void setup()//CARREGA TODAS AS TEXTURAS
{
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    idBackground = carregaTextura("../Img/background2.png");
    idSpritePlayer = carregaTextura("../Img/spritePlayer.png");
    idEstrela = carregaTextura("../Img/star.png");
    idSpriteInimigos[0] = carregaTextura("../Img/calc2.png");
    idMouse = carregaTextura("../Img/mouse.png");
    idSetas = carregaTextura("../Img/setas.png");
    idAD = carregaTextura("../Img/ad.png");
    idSpace = carregaTextura("../Img/space.png");

}
