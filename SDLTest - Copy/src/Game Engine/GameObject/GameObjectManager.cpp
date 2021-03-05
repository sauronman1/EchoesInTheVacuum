#include "GameObjectManager.h"
#include"GameObject.h"
#include <algorithm>
#include <memory>
#include <iostream>

void GameObjectManager::draw(){
    for (auto& gameObj : gameObjects) {
        if(gameObj.get()->isActive())
        gameObj->draw();
    }
}

void GameObjectManager::update(float deltaTime){
    for (auto& gameObj : gameObjects) {
        if (gameObj.get()->isActive())
        gameObj->update(deltaTime);
    }
}

void GameObjectManager::addGameObject(GameObject* gameObj){
    std::unique_ptr<GameObject> uniquePtr{ gameObj };
    gameObjects.emplace_back(std::move(uniquePtr));
}

GameObject* GameObjectManager::cloneGameObject(GameObject* gameObj){
    return nullptr;
}

void GameObjectManager::eraseGameObject(GameObject* gameObj){
    delete gameObj;
}


