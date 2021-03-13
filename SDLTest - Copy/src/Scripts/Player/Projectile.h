#pragma once
#include "../../Game Engine/GameObject/Components/Component.h"
#include "../../Game Engine/GameObject/GameObject.h"
#include "../../Game Engine/Essentials/ObjectPool.h"
#include "../../Game Engine/GameObject/Components/Rigibody2D.h"


class Projectile : public Component {

public:
    Projectile() = default;
    ~Projectile() = default;

    Projectile(ObjectPool* bPool) {
        bulletPool = bPool;
    }

    void update(float deltaTime) override final {
        if (gameObject->getComponent<Transform>().position.x > 1920)
            bulletPool->returnGameObject(gameObject);
    }
    
private:
    ObjectPool* bulletPool;
};