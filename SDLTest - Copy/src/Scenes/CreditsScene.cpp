#include "CreditsScene.h"
#include "../Game Engine/GameObject/GameObject.h"
#include "../Game Engine/Essentials/TextureManager.h"
#include "../Game Engine/GameObject/Components/Sprite.h"
#include "../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../Game Engine/SDL Events/SDLEvent.h"
#include "../Game Engine/Essentials/CommonFunctions.h"
void CreditsScene::init() {
	CommonFunctions::printConsoleMessage("Final Scene Loaded");
	Game::get().unPauseGame();

	GameObject* gb = new GameObject();

	TextureManager::get().loadTexture("background", "assets/background_02_static.png");

	gb->addComponent<Sprite>(Game::get().getRenderer(), "background");

	manager->addGameObject(gb);

}

void CreditsScene::update(float deltaTime)
{
}
