#pragma once

#include "Component.h"
#include "../../Math/Vector2.h"
#include "Transform.h"

constexpr float GRAVITY = 10.0f;

class Rigibody2D : public Component {

    public:
        Rigibody2D() = default;

        Rigibody2D(float gravity_scale) {
            gravityScale = gravity_scale;
        }

        Rigibody2D(float gravity_scale, float force_x, float force_y) {
            gravityScale = gravity_scale;
            force = Vector2<float>(force_x, force_y);
        }

        Rigibody2D(float gravity_scale, float force_x, float force_y, float drag_x, float drag_y) {
            gravityScale = gravity_scale;
            drag = Vector2<float>(drag_x, drag_y);
            force = Vector2<float>(force_x, force_y);
        }

        bool init() override final {
                transform = &gameObject->getComponent<Transform>();
                return true;
        }

        void update(float deltaTime) override final {
            velocity.x = force.x + drag.x;
            velocity.y = force.y + drag.y + gravityScale*GRAVITY;
            transform->translate(velocity);
        }

        void ChangeForce(Vector2<float> F){
            force = F;
        }

        void NoForce() {
            force = { 0,0 };
        }

    private:
        float gravityScale = 1.0f;
        Vector2<float> drag = Vector2<float>();
        Vector2<float> force = Vector2<float>();
        Vector2<float> velocity = Vector2<float>();

        Transform* transform = nullptr;
};
