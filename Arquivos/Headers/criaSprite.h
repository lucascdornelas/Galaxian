#ifndef _SPRITE_H_
#define _SPRITE_H_

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

Sprite criaSprite(float ,float ,float ,float );

#endif  // _SPRITE_H_
