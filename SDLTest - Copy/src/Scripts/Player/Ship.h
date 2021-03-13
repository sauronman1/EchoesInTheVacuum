#pragma once
#include "../Common/NPC.h"
#include "../../Game Engine/GameObject/Components/Component.h"
#include "../../Game Engine/Essentials/ObjectPool.h"

class Ship :public Component  , public NPC {
public:
	Ship(ObjectPool* bPool);
	bool init() override final;
	void update(float deltaTime) override final;
private:
	float timer;
	float coolDown ;
	float moveSpeed;
	bool isClicked ;
	ObjectPool* bulletPool;
};

