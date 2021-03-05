#pragma once

#include <string>
#include <SDL.h>

#include "../GameObject.h"
#include "Component.h"
#include "../../Essentials/TextureManager.h"

class Sprite : public Component {

    public:
        Sprite() = default;
        ~Sprite() = default;
        Sprite(SDL_Renderer* target, std::string textureid): rTarget(target), textureID(textureid) {}

        bool init() override {
            transform = &entity->getComponent<Transform>();
            texture = TextureManager::get().getTexture(textureID);
            SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

            dstRect.x = transform->position.x;
            dstRect.y = transform->position.y;
            dstRect.w = width*transform->scale.x;;
            dstRect.h = height*transform->scale.y;;

            srcRect.x = 0;
            srcRect.y = 0;
            srcRect.w = width;
            srcRect.h = height;
            return true;
        }

        void draw() override {
            SDL_RenderCopyEx(rTarget, texture, &srcRect, &dstRect, 0, nullptr, textureFlip);
        }

        void update(float deltaTime) override {
            dstRect.x = static_cast<int>(transform->position.x);
            dstRect.y = static_cast<int>(transform->position.y);
            dstRect.w = static_cast<int>(width*transform->scale.x);
            dstRect.h = static_cast<int>(height*transform->scale.y);
        }

        int getWidth() const {
            return static_cast<int>(width*transform->scale.x);
        }

        int getHeight() const {
            return static_cast<int>(height*transform->scale.y);
        }

    private:
        int width = 0;
        int height = 0;
        SDL_Rect srcRect = {0,0,0,0};
        SDL_Rect dstRect = {0,0,0,0};
        Transform* transform = nullptr;;

        std::string textureID = "";
        SDL_Texture* texture = nullptr;
        SDL_Renderer* rTarget = nullptr;
        SDL_RendererFlip textureFlip = SDL_FLIP_NONE;

};
