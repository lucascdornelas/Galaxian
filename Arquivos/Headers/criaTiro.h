#ifndef _CRIATIRO_H_
#define __CRIATIRO_H_

typedef struct tiro
{
  float _PosX;//POSICIAO INICIAL EM x
  float _PosY; //POSICIAO INICIAL EM Y
  float _TamanhoTiro; //TAMANHO DO TIRO
  float _Velociade; //VELOCIDADE DO TIRO
  int Sentido; //sentido = 1 > cima | -1 > baixo
} Tiro;

#endif  
