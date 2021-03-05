#include "GameScene.h"
#include "../Game.h"
#include "../Game Engine/GameObject/GameObject.h"
#include "../Game Engine/Essentials/TextureManager.h"
#include "../Game Engine/GameObject/Components/Sprite.h"
#include "../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../Game Engine/SDL Events/SDLEvent.h"

void GameScene::init(GameObjectManager* manager)
{
	GameObject* gb = new GameObject();
	TextureManager::get().loadTexture("nebula", "assets/Space-Free-PNG-Image.png");
	gb->addComponent<Sprite>(Game::get().getRenderer(), "nebula");
	manager->addGameObject(gb);
	
}

void GameScene::sceneClean() {

}

void GameScene::update(float deltaTime)
{

}
