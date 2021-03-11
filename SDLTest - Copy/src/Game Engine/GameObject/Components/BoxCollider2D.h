#pragma once

#include <SDL.h>
#include <string>
#include "../GameObject.h"
#include "Component.h"

class BoxCollider2D : public Component{

    public:
        BoxCollider2D(SDL_Renderer* target, int width, int height): rTarget(target){
            box.w = width;
            box.h = height;
        }

        BoxCollider2D(SDL_Renderer* target,  int width, int height, std::string tag): rTarget(target), collisionTag(tag){
            box.w = width;
            box.h = height;
        }

        ~BoxCollider2D() = default;

        bool init() override final{
            transform = &gameObject->getComponent<Transform>();
            return true;
        }

        void draw() override final {
            SDL_SetRenderDrawColor(rTarget, 255, 214, 98, 255);
            SDL_RenderDrawRect(rTarget, &box);
        }

        void update(float deltaTime) override final {
            box.x = transform->position.x;
            box.y = transform->position.y;
        }

        std::string getColisionTag() const {
            return collisionTag;
        }

        SDL_Rect getRect() { return box; }
    private:
        friend class Collision2D;
        SDL_Rect box = {0,0,0,0};
        std::string collisionTag = "";
        Transform* transform = nullptr;
        SDL_Renderer* rTarget = nullptr;
};
