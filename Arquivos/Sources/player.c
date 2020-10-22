#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Headers/criaSprite.h"

float _TamanhoNave = 15.0; //TAMANHO NAVE PLAYER comprimento x largura
#define posPlayerY 10.0 // POSICAO INICIAL DO PLAYER EM Y = 10.0
Sprite navePlayer;

int vidas = 3;

float score = 0;
float multiplicadorScore = 0.01;

GLuint idSpritePlayer;

void desenhaPlayer(float posX)
{
    navePlayer = criaSprite(posX, posPlayerY, _TamanhoNave, _TamanhoNave);

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idSpritePlayer);

    Vetor2d A, B, C, D;
    A.x = -navePlayer.tamanho.x / 2;
    A.y = navePlayer.tamanho.y / 2;

    B.x = navePlayer.tamanho.x / 2;
    B.y = navePlayer.tamanho.y / 2;

    C.x = -navePlayer.tamanho.x / 2;
    C.y = -navePlayer.tamanho.y / 2;

    D.x = navePlayer.tamanho.x / 2;
    D.y = -navePlayer.tamanho.y / 2;

    glPushMatrix();
        glTranslatef(navePlayer.posicao.x, navePlayer.posicao.y, 0.0);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);
            glVertex2f(C.x, C.y);

            glTexCoord2f(1, 0);
            glVertex2f(D.x, D.y);

            glTexCoord2f(1, 1);
            glVertex2f(B.x, B.y);

            glTexCoord2f(0, 1);
            glVertex2f(A.x, A.y);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

int solicitaYPlayer()
{
    return navePlayer.tamanho.y + navePlayer.tamanho.y/2;
}
