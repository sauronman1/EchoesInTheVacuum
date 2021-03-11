#pragma once
#include "../Common/NPC.h"
#include "../../Game Engine/GameObject/Components/Component.h"
#include "../../Game Engine/Essentials/Collision/Collision2D.h"
#include "../../Game Engine/Essentials/ObjectPool.h"

class Enemy : public Component, public NPC {

public:
	Enemy(ObjectPool* bPool);
	bool init() override final;
	void update(float deltaTime) override final;
	void onTriggerEnter2D(GameObject* other);

private:
	bool collided;
	Collision2D col;
	ObjectPool* bulletPool;

};