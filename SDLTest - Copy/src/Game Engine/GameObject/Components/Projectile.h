#pragma once
#include "Component.h"
#include "../GameObject.h"
#include "Rigibody2D.h"

class Projectile : public Component {

public:
    Projectile() = default;
    ~Projectile() = default;

    Projectile(float speed, ObjectPool* bPool) {
        flySpeed = speed;
        projectileObj = gameObject;
        projectileObj->addComponent<Rigibody2D>(0, flySpeed, 0);
        bulletPool = bPool;
    }

    void update(float deltaTime) override final {
        //stop bullet
    //gameobject setenabled false
    //bulletpool --> returnGameObject(this)
    }
    
private:
    float flySpeed;
    GameObject* projectileObj;
    ObjectPool* bulletPool;
};