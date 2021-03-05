#pragma once
#include "Component.h"
#include "../GameObject.h"

class Projectile : public Component {

public:
    Projectile() = default;
    ~Projectile() = default;

    Projectile(GameObject* projectile, float speed) {
        do {
            projectile->getComponent<Transform>().translate(Vector2<float>(speed, 0));
        } while (projectile->getComponent<Transform>().position.x < 1200);
    }
    
private:
    float speed;
};