#pragma once
#include "../../Game Engine/GameObject/Components/Component.h"
#include "../../Game Engine/GameObject/GameObject.h"
#include "../../Game Engine/GameObject/GameObjectManager.h"

class MenuCanvas: public Component
{
public:
	MenuCanvas() = default;
	~MenuCanvas() = default;
	void update(float deltaTime) override final;
	bool init() override final;
private:
	bool isClicked;

};

