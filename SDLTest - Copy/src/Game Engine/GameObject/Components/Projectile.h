#pragma once
#include "Component.h"
#include "../GameObject.h"
#include "Rigibody2D.h"

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