#pragma once
#include "../../Game Engine/GameObject/Components/Transform.h"
class BackgroundEffect : public Component
{
public:
    BackgroundEffect(bool isRotating, bool isMoving, float rotSpeed, float movSpeed) {
        rotationSettings = isRotating;
        movementSettings = isMoving;
        rotationSpeed = rotSpeed;
        movementSpeed = movSpeed;
    }

    bool init() override final {
        transform = &gameObject->getComponent<Transform>();
        return true;
    }

    void update(float deltaTime) override final {
        if (rotationSettings) {
            transform->rotation += 10* rotationSpeed * deltaTime;
        }
        if (movementSettings) {
            transform->translate(Vector2<float>(-movementSpeed * 10, 0) * deltaTime);
        }
    }
private:
    bool rotationSettings;
    bool movementSettings;
    float rotationSpeed;
    float movementSpeed;
    Transform* transform = nullptr;
};