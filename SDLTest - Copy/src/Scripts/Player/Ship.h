#pragma once
#include "../Common/NPC.h"
#include "../../Game Engine/GameObject/Components/Component.h"

class Ship : public NPC, Component {
public:
	bool init() override final {}
	void update(float deltaTime) override final {}
private:
	float timer = 0;
	float moveSpeed = 2;
};

