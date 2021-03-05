#pragma once
#include "../Game Engine/Essentials/SceneManagement/Scene.h"
class GameScene : public Scene
{
public:
	void init(GameObjectManager* manager) override;
	void update(float deltaTime) override;
	void sceneClean() override;
private:
	bool isClicked = false;
	GameObject* playerObj;
	float moveSpeed;
};

