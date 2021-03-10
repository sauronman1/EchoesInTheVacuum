#pragma once
#include "../Common/NPC.h"
#include "../../Game Engine/GameObject/Components/Component.h"

class Enemy : public Component, NPC {

public:
	void update(float deltaTime) override final {}

};