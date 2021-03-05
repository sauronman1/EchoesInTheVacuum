#include "GameObjectManager.h"
#include"GameObject.h"
#include <algorithm>
#include <memory>
#include <iostream>

void GameObjectManager::draw(){
    for(auto& gameObj : gameObjects) gameObj->draw();
}

void GameObjectManager::update(float deltaTime){
    for(auto& gameObj : gameObjects) gameObj->update(deltaTime);
}

void GameObjectManager::addGameObject(GameObject* gameObj){
    std::unique_ptr<GameObject> uniquePtr{ gameObj };
    gameObjects.emplace_back(std::move(uniquePtr));
}

void GameObjectManager::refresh(){

}

GameObject* GameObjectManager::cloneGameObject(GameObject* gameObj){
    return nullptr;
}

void GameObjectManager::eraseGameObject(GameObject* gameObj){

}


