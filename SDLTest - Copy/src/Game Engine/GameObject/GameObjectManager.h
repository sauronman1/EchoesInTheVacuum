#pragma once

#include <vector>
#include <memory>
#include"../../Game Engine/Essentials/CommonFunctions.h"
class GameObject;

class GameObjectManager {
    public:
        GameObjectManager() = default;
        ~GameObjectManager() = default;

        void draw();
        void update(float deltaTime);
        void addGameObject(GameObject* gameObj);
        void eraseGameObject(GameObject* gameObj);
        GameObject* cloneGameObject(GameObject* gameObj);
        inline void cleanGameObject() { gameObjects.clear(); };

private:
        std::vector<std::unique_ptr<GameObject>> gameObjects;

};

