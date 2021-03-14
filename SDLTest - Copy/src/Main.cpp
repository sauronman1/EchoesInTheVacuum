#include "../src/Game.h"
#include "Game Engine/SDL Events/SDLEvent.h"
int main(int argc, char** argv){
  // Checking for any missed memory leak
 //   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Game& game = Game::get();
    SDLEvent& sdlEvent = SDLEvent::get();

    //timer.init();
    sdlEvent.init();
    game.init();

    const int FPS = 120;
    const int frameDelay = 1000 / FPS;
    Uint32 startingFrame = 0;
    float frameTime;

    while(game.isRunning()){
        frameTime = SDL_GetTicks() - startingFrame;
        startingFrame = SDL_GetTicks();
        sdlEvent.handle();
        game.update(frameTime / 1000);
        game.render();
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
         
    }

    sdlEvent.clean();
    delete &sdlEvent;
    game.clean();
    delete &Game::get();

    return 0;
}

