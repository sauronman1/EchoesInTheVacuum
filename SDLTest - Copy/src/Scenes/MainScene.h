#pragma once
#include "../Game Engine/Essentials/SceneManagement/Scene.h"
#include "../Game Engine/GameObject/Components/UILabel.h"
class MainScene : public Scene
{
public:
	MainScene(GameObjectManager* manager) {
		this->manager = manager;
	};
	void init() override;
	void update(float deltaTime) override;

private:
	bool isClicked = false;
	GameObject* playButtonObj;
	GameObject* logoObj;
	GameObject* musicButtonObj;
	GameObject* playLabelObj;
	GameObject* logoLable;
	GameObject* playLable;
	GameObject* toggleLable;
	GameObject* toggleIndicator;
};

