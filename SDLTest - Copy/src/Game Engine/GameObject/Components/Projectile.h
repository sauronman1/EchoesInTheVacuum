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
        projectileObj->addComponent<Rigibody2D>(0, flySpeed, 0);
    }

    void update(float deltaTime) override final {
    }
    
private:
    float flySpeed;
    GameObject* projectileObj;
};