#pragma once
#include "../Common/NPC.h"
#include "../../Game Engine/GameObject/Components/Component.h"

class Ship : public NPC, Component {
public:
	void update(float deltaTime) override final {}
};

