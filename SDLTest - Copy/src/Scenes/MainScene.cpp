#include "MainScene.h"
#include "GameScene.h"
#include "../Game.h"
#include "../Game Engine/GameObject/GameObject.h"
#include "../Game Engine/Essentials/TextureManager.h"
#include "../Game Engine/GameObject/Components/Sprite.h"
#include "../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../Game Engine/SDL Events/SDLEvent.h"
#include "../Game Engine/Essentials/SoundManager/SoundManager.h"

void MainScene::init(GameObjectManager* manager)
{	
	GameObject* gb = new GameObject();
	playButtonObj = new GameObject();
	musicButtonObj = new GameObject();
	logoObj = new GameObject();
	playLabelObj = new GameObject();
	logoLable = new GameObject();
	playLable = new GameObject();
	toggleLable = new GameObject();
	toggleIndicator = new GameObject();

	TextureManager::get().loadTexture("background", "assets/background_02_static.png");
	TextureManager::get().loadTexture("play", "assets/main_button_1.png");
	TextureManager::get().loadTexture("music", "assets/main_button_2.png");
	TextureManager::get().loadTexture("logo", "assets/game_logo_small.png");
	TextureManager::get().loadTexture("toggleSymbol", "assets/button_arrow_right.png");
	TextureManager::get().loadFont("neuropol", "assets/fonts/neuropol.ttf", 30);
	TextureManager::get().loadFont("neuropolTitle", "assets/fonts/neuropol.ttf", 60);
	SoundManager::Instance()->loadMusic("mainMusic", "assets/_Art/Audio/gameMusic.mp3");
	SoundManager::Instance()->setVolume(10); // Value from 0 to 120
	SoundManager::Instance()->playMusic("mainMusic");

	gb->addComponent<Sprite>(Game::get().getRenderer(), "background");
	playButtonObj->addComponent<Sprite>(Game::get().getRenderer(), "play");
	musicButtonObj->addComponent<Sprite>(Game::get().getRenderer(), "music");
	logoObj->addComponent<Sprite>(Game::get().getRenderer(), "logo");
	logoLable->addComponent<UILabel>(Game::get().getRenderer(), "", 550, 60, "neuropolTitle");
	playLable->addComponent<UILabel>(Game::get().getRenderer(), "", 880, 440, "neuropol");
	toggleLable->addComponent<UILabel>(Game::get().getRenderer(), "", 880, 640, "neuropol");
	toggleIndicator->addComponent<Sprite>(Game::get().getRenderer(), "toggleSymbol");

	logoObj->getComponent<Transform>().position = Vector2<float>(850.0f, 140.0f);
	playButtonObj->getComponent<Transform>().position = Vector2<float>(750.0f,390.0f);
	musicButtonObj->getComponent<Transform>().position = Vector2<float>(750.0f, 590.0f);
	toggleIndicator->getComponent<Transform>().position = Vector2<float>(790.0f, 620.0f);
	playButtonObj->getComponent<Transform>().scale = Vector2<float>(0.4f, 0.4f);
	musicButtonObj->getComponent<Transform>().scale = Vector2<float>(0.5f, 0.5f);
	logoObj->getComponent<Transform>().scale = Vector2<float>(1.5f, 1.5f);
	logoLable->getComponent<UILabel>().setFontColor({ 255,32,21 });
	logoLable->getComponent<UILabel>().setText("Echoes in the Vacuum");
	playLable->getComponent<UILabel>().setFontColor({ 0,128,0 });
	playLable->getComponent<UILabel>().setText("Play Game");
	toggleLable->getComponent<UILabel>().setFontColor({ 0,128,0 });
	toggleLable->getComponent<UILabel>().setText("Toggle Music");

	manager->addGameObject(gb);
	manager->addGameObject(playButtonObj);
	manager->addGameObject(musicButtonObj);
	manager->addGameObject(logoObj);
	manager->addGameObject(playLabelObj);
	manager->addGameObject(logoLable);
	manager->addGameObject(playLable);
	manager->addGameObject(toggleLable);
	manager->addGameObject(toggleIndicator);

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

	if (SDLEvent::get().getButtonDown(LEFT) == true && isClicked == false) {
		isClicked = true;
		if (SDLEvent::get().getMousePos().x > 750 && SDLEvent::get().getMousePos().x < 1200 && SDLEvent::get().getMousePos().y > 350 && SDLEvent::get().getMousePos().y < 470) {
			std::cout << SDLEvent::get().getMousePos() << std::endl;
			sceneFinished = false;
			GameScene* mainScene = new GameScene();
			SceneManager::get().setCurrentScene(mainScene);

		}
		if (SDLEvent::get().getMousePos().x > 750 && SDLEvent::get().getMousePos().x < 1180 && SDLEvent::get().getMousePos().y > 550 && SDLEvent::get().getMousePos().y < 680) {
			std::cout << SDLEvent::get().getMousePos() << std::endl;
			SoundManager::Instance()->toggleMusic();
			toggleIndicator->SetEnabled(!toggleIndicator->isActive());

		}
	}
	else if (SDLEvent::get().getButtonDown(LEFT) == false && isClicked == true) {
		isClicked = false;
	}
}
