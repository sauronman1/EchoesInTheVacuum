#pragma once
#include "../../Game Engine/GameObject/Components/Component.h"
#include "../../Game Engine/GameObject/GameObject.h"

class MenuCanvas: public Component
{
public:
	MenuCanvas() = default;
	MenuCanvas(GameObject* toggleB) : toggleB(toggleB) {}
	~MenuCanvas() = default;
	void update(float deltaTime) override final;

private:
	GameObject* toggleB;
};

