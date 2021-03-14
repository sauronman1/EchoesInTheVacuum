#include "Game.h"
#include <iostream>
#include <Windows.h>

#include "../src/Game Engine/Essentials/TextureManager.h"
#include "../src/Game Engine/GameObject/GameObjectManager.h"
#include "../src/Game Engine/GameObject/GameObject.h"
#include "../src/Game Engine/Essentials/CommonFunctions.h"
#include "Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "Scenes/GameScene.h"
#include "Scenes/MainScene.h"
#include "Game Engine/Essentials/SoundManager/SoundManager.h"
#include "Scripts/Common/GameScore.h"

Game* Game::s_instance = nullptr;
GameObjectManager* manager = new GameObjectManager();

Game::Game(){
    running = false;
    window = nullptr;
    renderer = nullptr;
    isPaused = false;
}

Game::~Game(){}

void Game::init(){
    if(SDL_Init(SDL_INIT_VIDEO)!= 0) std::cerr << SDL_GetError() << std::endl;

    auto wflags = (SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_ALLOW_HIGHDPI);
    window = SDL_CreateWindow("Space Shooting", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, wflags);
    if (!window) {
        CommonFunctions::printErrorMessage(SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        CommonFunctions::printErrorMessage(SDL_GetError());
    }
    srand(time(NULL));

    TextureManager::get().clean();
    Game::get().pauseGame();
    SceneManager::get().init(manager);


    clearColor = { 0, 0, 28 };
    running = true;
}

void Game::render(){

    if (!isPaused) {
        SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        SDL_RenderClear(renderer);
        manager->draw();
        SDL_RenderPresent(renderer);
    }
}

void Game::update(float deltaTime){
    if (!isPaused) {
        manager->update(deltaTime);
        SceneManager::get().update(deltaTime);
    }


}

void Game::clean(){
    SceneManager::get().removeScene();
    manager->cleanGameObject();
    delete manager;
    SoundManager::Instance()->cleanSounds();
    delete SoundManager::Instance();
    TextureManager::get().clean();
    delete &TextureManager::get();
    delete &SceneManager::get();
    delete&  GameScore::get();


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::quit(){
    running = false;
}




