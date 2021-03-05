#pragma once

#include "../../Game.h"
#include <vector>
#include <memory>
#include "Components/Component.h"
#include "Components/Transform.h"
#include "Components/ComponentTypes.h"

class GameObject {
    public:
        inline GameObject(){
            this->addComponent<Transform>(0,0);
        }

        inline virtual ~GameObject(){}

        inline void draw(){
            for(auto& component : components) component->draw();
        }

        inline void update(float deltaTime){
            for(auto& component : components) component->update(deltaTime);
        }

        inline bool iSActive() const {
            return active;
        }

        inline void destroy(){
            active = false;
        }

        template<typename T>
        inline bool hasComponent() const {
            return compBitset[getComponentTypeID<T>()];
        }

        template<typename T, typename... TArgs>
        inline T& addComponent(TArgs&&... args){
            T* comp(new T(std::forward<TArgs>(args)...));
            comp->gameObject = this;
            std::unique_ptr<Component> uniquePtr { comp };
            components.emplace_back(std::move(uniquePtr));

            if(comp->init()){
                compArray[getComponentTypeID<T>()] = comp;
                compBitset[getComponentTypeID<T>()] = true;
                return *comp;
            }

            return *static_cast<T*>(nullptr);
        }

        template<typename T>
        inline T& getComponent() const {
            auto ptr(compArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }

    private:
        bool active = true;
        ComponentArray compArray;
        ComponentBitset compBitset;
        std::vector<std::unique_ptr<Component>> components;
};


