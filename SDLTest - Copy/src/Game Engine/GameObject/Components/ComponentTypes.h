#pragma once

#include <array>
#include <bitset>
#include <iostream>

class GameObject;
class Component;

//unsigned int for component type
using ComponentTypeID = std::size_t;

inline ComponentTypeID getUniqueID(){
    static ComponentTypeID lastID = 0u;
    return lastID++;
}

// return component type by making sure the type name is a component
template<typename T>
inline ComponentTypeID getComponentTypeID() noexcept {
    static_assert(std::is_base_of<Component, T>::value, "Component not base on 'Component'!");
    static const ComponentTypeID typeID = getUniqueID();
    return typeID;
}

// max number of entities we can create
constexpr std::size_t MAX_ENTITIES = 5000;

// max number of component per entity
constexpr std::size_t MAX_COMPONENTS = 32;

// bit set to know active components
using ComponentBitset = std::bitset<MAX_COMPONENTS>;

// array to store entity components
using ComponentArray = std::array<Component*, MAX_COMPONENTS>;












