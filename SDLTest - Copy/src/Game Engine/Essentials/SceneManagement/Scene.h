#pragma once
#include "../../GameObject/GameObjectManager.h"

class Scene {
public:
	Scene() = default;
	~Scene() = default;
	Scene(GameObjectManager* manager)  { this->manager = manager; };
	virtual void init() {};
	virtual void update(float deltaTime) {}
	bool sceneFinished;

protected:
	GameObjectManager* manager;

private:
	
};