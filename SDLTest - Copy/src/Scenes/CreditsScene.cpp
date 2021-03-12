#include "CreditsScene.h"
#include "../Game Engine/GameObject/GameObject.h"
#include "../Game Engine/Essentials/TextureManager.h"
#include "../Game Engine/GameObject/Components/Sprite.h"
#include "../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../Game Engine/SDL Events/SDLEvent.h"
#include "../Game Engine/Essentials/CommonFunctions.h"
#include "../Game Engine/GameObject/Components/UILabel.h"
#include "../Scripts/Common/GameScore.h"

void CreditsScene::init() {
	CommonFunctions::printConsoleMessage("Final Scene Loaded");
	Game::get().unPauseGame();

	GameObject* gb = new GameObject();
	titleLable = new GameObject();
	highscoreLable = new GameObject();
	RetryObj = new GameObject();
	quitObj= new GameObject();
	playerScoreLable = new GameObject();

	TextureManager::get().loadTexture("background", "assets/background_02_static.png");
	TextureManager::get().loadFont("title", "assets/fonts/neuropol.ttf", 60);
	TextureManager::get().loadFont("score", "assets/fonts/neuropol.ttf", 30);
	TextureManager::get().loadFont("button", "assets/fonts/neuropol.ttf", 30);

	gb->addComponent<Sprite>(Game::get().getRenderer(), "background");
	titleLable->addComponent<UILabel>(Game::get().getRenderer(), "", 745, 60, "title");
	highscoreLable->addComponent<UILabel>(Game::get().getRenderer(), "", 760, 260, "score");
	playerScoreLable->addComponent<UILabel>(Game::get().getRenderer(), "", 762, 320, "score");

	titleLable->getComponent<UILabel>().setFontColor({ 255,32,21 });
	titleLable->getComponent<UILabel>().setText("HighScore");
	highscoreLable->getComponent<UILabel>().setFontColor({ 0,128,0 });
	highscoreLable->getComponent<UILabel>().setText("Highest Score: " + std::to_string(GameScore::get().getHighScore()));
	playerScoreLable->getComponent<UILabel>().setFontColor({ 128,128,0 });
	playerScoreLable->getComponent<UILabel>().setText("your Score: " + std::to_string(GameScore::get().getGameScore()));
	manager->addGameObject(gb);
	manager->addGameObject(titleLable);
	manager->addGameObject(highscoreLable);
	manager->addGameObject(playerScoreLable);
}

void CreditsScene::update(float deltaTime)
{
	if (sceneFinished == true) { return; }

	if (SDLEvent::get().getButtonDown(LEFT) == true && isClicked == false) {
		isClicked = true;
	//	if (SDLEvent::get().getMousePos().x > 750 && SDLEvent::get().getMousePos().x < 1200 && SDLEvent::get().getMousePos().y > 350 && SDLEvent::get().getMousePos().y < 470) 
			std::cout << "Go to New Scene" << std::endl;
			sceneFinished = false;
			Game::get().pauseGame();
			SceneManager::get().goToNextScene(1);
			return;

		}

}
