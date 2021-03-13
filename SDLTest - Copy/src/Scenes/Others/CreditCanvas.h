#pragma once
#include "../../Game Engine/GameObject/Components/Component.h"
#include "../../Game Engine/GameObject/GameObject.h"

class CreditCanvas : public Component
{
public:
	CreditCanvas() = default;
	void update(float deltaTime) override final;
	bool init() override final;

private:
	bool isClicked;
};

