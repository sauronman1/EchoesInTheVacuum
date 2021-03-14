#pragma once
#include "../../Game Engine/GameObject/Components/Transform.h"
#include "../Common/GameScore.h"
class BackgroundEffect : public Component
{

public:
    BackgroundEffect( float rotSpeed, float movSpeed, bool resPos) {
        rotationSpeed = rotSpeed;
        movementSpeed = movSpeed;
        resetPosition = resPos;
    }

    bool init() override final {
        transform = &gameObject->getComponent<Transform>();
        return true;
    }

    void update(float deltaTime) override final {
        if (rotationSpeed !=0) {
            transform->rotation = transform->rotation + (10 * rotationSpeed * GameScore::get().getWaveNumber()  * deltaTime);
        }
        if (movementSpeed!=0) {
            speedChange = movementSpeed * 10 * GameScore::get().getWaveNumber();
            transform->translate(Vector2<float>(-speedChange, 0) * deltaTime);
        }
        if (resetPosition) {
            if (gameObject->getComponent<Transform>().position.x < -250) {
                gameObject->getComponent<Transform>().position = { offScreen.x,gameObject->getComponent<Transform>().position.y };
            }
        }
    }
private:
    Vector2<float> offScreen = { 1900,0 };
    float rotationSpeed;
    float movementSpeed;
    bool resetPosition;
    Transform* transform = nullptr;
    float speedChange;
    float rotationChange;
};