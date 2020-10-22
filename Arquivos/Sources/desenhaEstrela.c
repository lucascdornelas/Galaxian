#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include "../Headers/setup.h"

GLuint idEstrela;

void desenhaEstrela(int x, int y)
{
    glColor3f(1.0, 1.0, 1.0);//BRANCO
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
     // Habilita o uso de texturas
    glEnable(GL_TEXTURE_2D);
    // Começa a usar a textura que criamos
    glBindTexture(GL_TEXTURE_2D, idEstrela);
        glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);
        glVertex2f(x, y); // v3---v2
        glTexCoord2f(1, 0);
        glVertex2f(x+2, y); // |     |
        glTexCoord2f(1, 1);
        glVertex2f(x+2, y+2); // |     |
        glTexCoord2f(0, 1);
        glVertex2f(x, y+2); // v0---v1
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
