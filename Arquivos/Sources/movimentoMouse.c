#include "../Headers/criaSprite.h"
#include "../Headers/teclaPressionada.h"

Vetor2d posicaoMouse;//MOVIMENTACAO DO MOUSE, APROVEITANDO O CODIGO STRUCT V2D
int statusPause;
void movimentoMouse(int x, int y)
{
    if(statusPause == -1)
    {
      float xPosition;
      xPosition = (float)x/5.0;

      if(xPosition<=7.0)
      {
        xPosition=7.0;
      }
      if(xPosition>=93.0)
      {
        xPosition=93.0;
      }

      posicaoMouse.x = xPosition;
      posicaoMouse.y = y;
    }

}
