#pragma once

#include "../GameObject.h"
#include "../../Math/Vector2.h"
#include "Component.h"

class Transform : public Component {

public:
    Vector2<float> scale = Vector2<float>(1.0f,1.0f);
    Vector2<float> position = Vector2<float>();
    float rotation = 0.0f;

    Transform() = default;

    Transform(float x, float y){
        position = Vector2<float>(x,y);
    }

    Transform(float x, float y, float scalex, float scaley){
        position.x = x;
        position.y = y;
        scale.x = scalex;
        scale.y = scaley;
    }

    Transform(float x, float y, float scalex, float scaley, float rotation){
        position.x = x;
        position.y = y;
        scale.x = scalex;
        scale.y = scaley;
        this->rotation = rotation;
    }

    void translate(Vector2<float> v){
        position += v;
    }
};
