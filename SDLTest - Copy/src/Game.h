#pragma once

#include <SDL.h>

constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;
constexpr SDL_Color DARK = {30, 30, 30, 255};

class Game {
    public:
        Game();
        ~Game();

        void quit();
        void init();
        void clean();

        void render();
        void update(float deltaTime);

        inline static Game& get(){
            if(s_instance == nullptr){
                s_instance = new Game();
            }
            return *s_instance;
        }

        inline bool isRunning() {
            return running;
        }

        inline void pauseGame() {
            isPaused = true;
        }

        inline void unPauseGame() {
            isPaused = false;
        }

        inline SDL_Renderer* getRenderer(){
            return renderer;
        }

    private:
        bool running;
        SDL_Window* window;
        SDL_Color clearColor;
        SDL_Renderer* renderer;
        static Game* s_instance;
        bool isPaused = false;
};
