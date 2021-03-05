#pragma once
#include "../../GameObject/GameObjectManager.h"

class Scene {
public:
	Scene() = default;
	~Scene() = default;
	virtual void init(GameObjectManager* manager) { this->manager = manager; }
	virtual void update(float deltaTime) {}
	virtual void sceneClean() {}
protected:
	GameObjectManager* manager;
	bool sceneFinished;

private:
	
};