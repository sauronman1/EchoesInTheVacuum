#pragma once
#include "../Game Engine/Essentials/SceneManagement/Scene.h"
#include "../Game Engine/GameObject/Components/UILabel.h"
class MainScene : public Scene
{
public:
	void init(GameObjectManager* manager) override;
	void update(float deltaTime) override;
	void sceneClean() override;

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
	GameObject* playSymbol;
};

