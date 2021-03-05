#include "../src/Game.h"
#include "Game Engine/SDL Events/SDLEvent.h"

int main(int argc, char** argv){
  //  Timer& timer = Timer::get();
    Game& game = Game::get();
    SDLEvent& sdlEvent = SDLEvent::get();

    //timer.init();
    sdlEvent.init();
    game.init();

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 startingFrame;
    float frameTime;

    while(game.isRunning()){
        startingFrame = SDL_GetTicks();
        frameTime = SDL_GetTicks() - startingFrame;
        sdlEvent.handle();
        game.update(frameTime);
        game.render();
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    sdlEvent.clean();
    game.clean();

    return 0;
}

