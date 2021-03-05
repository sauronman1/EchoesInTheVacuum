#pragma once

#include "SDL.h"
#include <vector>
#include "../Math/Vector2.h"
#include <map>
#include "../Essentials/CommonFunctions.h"

enum MouseButton{LEFT=0, MIDDLE=1, RIGHT=2};

class SDLEvent {
    public:
        SDLEvent() = default;
        ~SDLEvent() = default;

        void init();
        void clean();
        void handle();

        inline Uint32 getEventType() const {
            return event.type;
        }


        inline Vector2<float> getMouseMotionVect() const {
                return (mouseCurrPosition - mousePreviousPosition);
        }

        inline Vector2<float> getMousePos() const {
                return mouseCurrPosition;
        }

        inline bool getButtonDown(MouseButton button) const {
                return mouseButtonState[button];
        }

        inline static SDLEvent& get(){
            if(s_instance == nullptr){
                s_instance = new SDLEvent();
            }
            return *s_instance;
        }

        void addKeyboardKey(Sint32 oneKey);

        float getKeyValue(Sint32 oneKey) {
            if (keyboardKeys.find(oneKey) != keyboardKeys.end()) {
                return keyboardKeys[oneKey];
            }
            else {
                addKeyboardKey(oneKey);
            }
            return 0;
        }

    private:
        void mouseUp();
        void mouseDown();
        void mouseMotion();


        std::map<Sint32, int> keyboardKeys;
        SDL_Event event;
        static SDLEvent* s_instance;
        std::vector<bool> mouseButtonState;
        Vector2<float> mouseCurrPosition, mousePreviousPosition;
};
