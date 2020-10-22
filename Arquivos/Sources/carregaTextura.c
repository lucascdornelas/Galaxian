#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>

GLuint carregaTextura(const char* arquivo) //CARREGA TODAS TEXTURAS UTILIZADAS NO JOGO
{
    GLuint idTextura = SOIL_load_OGL_texture(arquivo,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    if (idTextura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}
