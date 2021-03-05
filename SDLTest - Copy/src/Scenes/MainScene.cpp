#include "MainScene.h"
#include "GameScene.h"
#include "../Game.h"
#include "../Game Engine/GameObject/GameObject.h"
#include "../Game Engine/Essentials/TextureManager.h"
#include "../Game Engine/GameObject/Components/Sprite.h"
#include "../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../Game Engine/SDL Events/SDLEvent.h"

void MainScene::init(GameObjectManager* manager)
{	
	GameObject* gb = new GameObject();
	playButtonObj = new GameObject();
	musicButtonObj = new GameObject();
	logoObj = new GameObject();
	playLabelObj = new GameObject();

	TextureManager::get().loadTexture("background", "assets/background_02_static.png");
	TextureManager::get().loadTexture("play", "assets/main_button_1.png");
	TextureManager::get().loadTexture("music", "assets/main_button_2.png");
	TextureManager::get().loadTexture("logo", "assets/game_logo_small.png");

	gb->addComponent<Sprite>(Game::get().getRenderer(), "background");
	playButtonObj->addComponent<Sprite>(Game::get().getRenderer(), "play");
	musicButtonObj->addComponent<Sprite>(Game::get().getRenderer(), "music");
	logoObj->addComponent<Sprite>(Game::get().getRenderer(), "logo");
	playLabelObj->addComponent<UILabel>(Game::get().getRenderer(), "Play", 10, 10);

	logoObj->getComponent<Transform>().position = Vector2<float>(850.0f, 100.0f);
	playButtonObj->getComponent<Transform>().position = Vector2<float>(750.0f,350.0f);
	musicButtonObj->getComponent<Transform>().position = Vector2<float>(750.0f, 550.0f);
	playButtonObj->getComponent<Transform>().scale = Vector2<float>(0.4f, 0.4f);
	musicButtonObj->getComponent<Transform>().scale = Vector2<float>(0.5f, 0.5f);
	logoObj->getComponent<Transform>().scale = Vector2<float>(1.5f, 1.5f);

	manager->addGameObject(gb);
	manager->addGameObject(playButtonObj);
	manager->addGameObject(musicButtonObj);
	manager->addGameObject(logoObj);
	manager->addGameObject(playLabelObj);
	
	//sceneClean();
	//SceneManager::get().goToNextScene(1);


}

void MainScene::sceneClean() {
	manager->eraseGameObject(playButtonObj);
	manager->eraseGameObject(musicButtonObj);

}
void MainScene::update(float deltaTime)
{
	if (sceneFinished == true) { return; }

	if (SDLEvent::get().getButtonDown(LEFT) == true) {
		if (SDLEvent::get().getMousePos().x > 750 && SDLEvent::get().getMousePos().x < 1200 && SDLEvent::get().getMousePos().y > 350 && SDLEvent::get().getMousePos().y < 470) {
			std::cout << SDLEvent::get().getMousePos() << std::endl;
			sceneFinished = false;
			sceneClean();
			GameScene* mainScene = new GameScene();
			SceneManager::get().setCurrentScene(mainScene);

		}
	}
}
