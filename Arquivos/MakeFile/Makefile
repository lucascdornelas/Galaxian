CC=gcc
OPCOES_COMPILADOR=-I. -lglut -lGLU -lGLEW -lGL -lSOIL -lm -lSDL -lSDL_mixer
TODOS_ARQUIVOS_PONTOH =
TODOS_ARQUIVOS_OBJ = musica.o carregaTextura.o setup.o desenhaConfirmacao.o desenhaEstrela.o desenhaBackground.o escreveTexto.o desenhaTelaGameOver.o desenhaTelaCongratulations.o criaSprite.o criaTiro.o player.o tiro.o criaInimigo.o detectarColisao.o desenhaTelaTutorial.o desenhaTelaGame.o desenhaTelaPause.o teclaEspecial.o teclaPressionada.o movimentoMouse.o hudDisplay.o atualizaCena.o redimensionada.o main.o

%.o: ../Sources/%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o ../Sources/main $^ $(OPCOES_COMPILADOR)

run: all
	./../Sources/main

clean:
	rm *.o main
