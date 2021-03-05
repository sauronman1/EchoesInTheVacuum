#include "SDLEvent.h"
#include "../../Game.h"

SDLEvent* SDLEvent::s_instance = nullptr;

void SDLEvent::init(){
    mouseCurrPosition.toZero();
    mousePreviousPosition.toZero();
    mouseButtonState = {false, false, false};
}

void SDLEvent::handle(){

    mousePreviousPosition = mouseCurrPosition;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT: Game::get().quit(); break;
            case SDL_MOUSEMOTION: mouseMotion(); break;
            case SDL_MOUSEBUTTONDOWN: mouseDown(); break;
            case SDL_MOUSEBUTTONUP: mouseUp(); break;
        }

        if (event.type == SDL_KEYDOWN) {
            for (auto it = keyboardKeys.begin(); it != keyboardKeys.end(); it++) {
                if (keyboardKeys.find(it->first) != keyboardKeys.end()) {
                    if (event.key.keysym.sym == it->first) {
                        it->second = 1;
                    }
                }
            }
        }

        if (event.type == SDL_KEYUP) {
            for (auto it = keyboardKeys.begin(); it != keyboardKeys.end(); it++) {
                if (keyboardKeys.find(it->first) != keyboardKeys.end()) {
                    if (event.key.keysym.sym == it->first) {
                        it->second = 0;
                    }
                }
            }
        }


    }
}

void SDLEvent::addKeyboardKey(Sint32 oneKey)
{
    if (keyboardKeys.find(oneKey) == keyboardKeys.end()) {
        keyboardKeys.emplace(oneKey, 0);
    }
}

void SDLEvent::mouseUp(){
    if(event.button.button == SDL_BUTTON_LEFT) mouseButtonState[LEFT] = false;
    if(event.button.button == SDL_BUTTON_RIGHT) mouseButtonState[RIGHT] = false;
    if(event.button.button == SDL_BUTTON_MIDDLE) mouseButtonState[MIDDLE] = false;
}

void SDLEvent::mouseDown(){
    if(event.button.button == SDL_BUTTON_LEFT) mouseButtonState[LEFT] = true;
    if(event.button.button == SDL_BUTTON_RIGHT) mouseButtonState[RIGHT] = true;
    if(event.button.button == SDL_BUTTON_MIDDLE) mouseButtonState[MIDDLE] = true;
}

void SDLEvent::mouseMotion(){
    mouseCurrPosition.x = event.motion.x;
    mouseCurrPosition.y = event.motion.y;
}

void SDLEvent::clean(){
    mouseButtonState.clear();
    mouseButtonState.shrink_to_fit();
}

