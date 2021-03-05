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
        void refresh();
        void addGameObject(GameObject* player);
        void eraseGameObject(GameObject* player);
        GameObject* cloneGameObject(GameObject* player);

    private:
        std::vector<std::unique_ptr<GameObject>> gameObjects;
};

