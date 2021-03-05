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

Game* Game::s_instance = nullptr;
GameObjectManager* manager = new GameObjectManager();

Game::Game(){
    running = false;
    window = nullptr;
    renderer = nullptr;
}

Game::~Game(){}

void Game::init(){
    if(SDL_Init(SDL_INIT_VIDEO)!= 0) std::cerr << SDL_GetError() << std::endl;

    auto wflags = (SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_ALLOW_HIGHDPI);
    window = SDL_CreateWindow("Space Shooting", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, wflags);
    if (!window) {
        CommonFunctions::printErrorMessage(SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window, -1, (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
    if (!renderer) {
        CommonFunctions::printErrorMessage(SDL_GetError());
    }
    MainScene* mainScene = new MainScene();
    SceneManager::get().init(manager, mainScene);


    //Sleep(8000);
    /*TextureManager::get().clean();
    SceneManager::get().setCurrentScene(mainScene);*/

    clearColor = DARK;
    running = true;
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    SDL_RenderClear(renderer);
    manager->draw();
    SDL_RenderPresent(renderer);
}

void Game::update(float deltaTime){
    manager->update(deltaTime);
    SceneManager::get().update(deltaTime);
    


}

void Game::clean(){
    TextureManager::get().clean();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::quit(){
    running = false;
}




