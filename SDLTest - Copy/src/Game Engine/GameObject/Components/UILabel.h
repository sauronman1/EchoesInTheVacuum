#pragma once

#include <SDL.h>
#include <string>

#include "../GameObject.h"
#include "Component.h"
#include "../../Essentials/TextureManager.h"

const std::string ARIAL = "Arial";
constexpr SDL_Color DEFAULT_LABEL_COLOR = {255, 255, 255, 255};

class UILabel: public Component {

    public:
        UILabel() = default;
        ~UILabel() = default;

        UILabel(SDL_Renderer* rtarget, std::string value, int x, int y){
            shape.x = x;
            shape.y = y;
            text = value;
            renderTarget = rtarget;
        }

        UILabel(SDL_Renderer* rtarget, std::string value, int x, int y, std::string font){
            shape.x = x;
            shape.y = y;
            text = value;
            fontFamilly = font;
            renderTarget = rtarget;
        }

        UILabel(SDL_Renderer* rtarget, std::string value,  int x, int y, std::string font, SDL_Color& color){
            shape.x = x;
            shape.y = y;
            text = value;
            fontColor = color;
            fontFamilly = font;
            renderTarget = rtarget;
        }

        void draw() override {
            SDL_RenderCopy(renderTarget, texture, nullptr, &shape);
        }

        void setText(std::string value){
            SDL_Surface* surface = TTF_RenderText_Blended(TextureManager::get().getFont(fontFamilly), value.c_str(), fontColor);
            texture = SDL_CreateTextureFromSurface(renderTarget, surface);
            SDL_QueryTexture(texture, nullptr, nullptr, &shape.w, &shape.h);
            SDL_FreeSurface(surface);
        }

        void setFontColor(const SDL_Color color = DEFAULT_LABEL_COLOR){
            fontColor = color;
        }

    private:
        SDL_Rect shape = {0,0,0,0};
        SDL_Texture* texture = nullptr;
        SDL_Renderer* renderTarget = nullptr;
        SDL_Color fontColor = DEFAULT_LABEL_COLOR;

        std::string text = "";
        std::string fontFamilly = ARIAL;
};
