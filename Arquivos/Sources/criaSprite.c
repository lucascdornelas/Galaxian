typedef struct vetor2d
{
    float x, y;
}   Vetor2d;

typedef struct sprite
{
  int status;
  Vetor2d posicao;
  Vetor2d tamanho;
} Sprite;

Sprite criaSprite(float posX, float posY, float tamX, float tamY)
{
    Sprite s;
    s.status = 1;
    s.posicao.x = posX;
    s.posicao.y = posY;
    s.tamanho.x = tamX;
    s.tamanho.y = tamY;
    return s;
}
