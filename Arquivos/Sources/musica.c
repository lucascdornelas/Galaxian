#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>      

      
Mix_Music *musicaDeFundo = NULL;
Mix_Music *musicaChampion = NULL;

void inicializarMusica()
{
    SDL_Init( SDL_INIT_AUDIO);
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 1024 ); //- inicializa SDL_Mixer
    atexit(Mix_CloseAudio);
}

void carregarMusica()
{
    musicaDeFundo = Mix_LoadMUS("../Music/Galaxian.mp3");
    musicaChampion = Mix_LoadMUS("../Music/queen-we-are-the-champions-chorus-only.mp3");
}
