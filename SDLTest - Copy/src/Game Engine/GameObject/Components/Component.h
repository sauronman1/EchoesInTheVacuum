#pragma once

class GameObject;

class Component {
    public:
        Component() = default;
        ~Component() = default;

        GameObject* gameObject;
        virtual bool init(){return true;}
        virtual void draw(){}
        virtual void update(float deltaTime){}
};
