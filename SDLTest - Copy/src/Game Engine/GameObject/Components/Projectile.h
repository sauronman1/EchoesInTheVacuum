#pragma once
#include "Component.h"
#include "../GameObject.h"
#include "Rigibody2D.h"

class Projectile : public Component {

public:
    Projectile() = default;
    ~Projectile() = default;

    Projectile(GameObject* projectile, float speed) {
        flySpeed = speed;
        projectileObj = projectile;
    }

    void update(float deltaTime) override final {
        projectileObj->getComponent<Transform>().translate(Vector2<float>(10 * flySpeed * deltaTime, 0));
    }
    
private:
    float flySpeed;
    GameObject* projectileObj;
};