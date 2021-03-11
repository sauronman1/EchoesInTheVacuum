#include "CreditsScene.h"
#include "../Game Engine/GameObject/GameObject.h"
#include "../Game Engine/Essentials/TextureManager.h"
#include "../Game Engine/GameObject/Components/Sprite.h"
#include "../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../Game Engine/SDL Events/SDLEvent.h"

void CreditsScene::init() {
	GameObject* gb = new GameObject();

	TextureManager::get().loadTexture("background", "assets/background_02_static.png");

	gb->addComponent<Sprite>(Game::get().getRenderer(), "background");

	manager->addGameObject(gb);

}

void CreditsScene::update(float deltaTime)
{
}
