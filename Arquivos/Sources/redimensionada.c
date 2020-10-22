#include <GL/glew.h>
#include <GL/freeglut.h>

float razaoJanela;
float larguraMundo = 100.0;//MUNDO (X)
float alturaMundo = 100.0;//MUNDO (Y)
// largura e altura sao iguais pois nosso mundo é quadrado
float vertical, horizontal; //BARRAS PRETAS


void redimensionada(int lar, int alt)//largura e altura
{
    razaoJanela = ((float)lar/(float)alt);

    if (razaoJanela < 1) //se razao da janela é menor que a razao do mundo(1), iremos colocar barras pretas verticais, para disfarçar a tela
    {
        vertical = ((float)alt - (float)lar)/2;//(altura - largura)/2
        glViewport(0, vertical, lar, lar);
    }

    if (razaoJanela > 1) //se razao do mundo(1) é menor que a razao da janela, iremos colocar barras pretas horizontais, para disfarçar a tela
    {
        horizontal = ((float)lar - (float)alt)/2;//(largura - altura)/2
        glViewport(horizontal, 0, alt, alt);
    }
    
    else //se a janela for um quadrado perfeito
    {
        glViewport(0, 0, lar, alt);
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
