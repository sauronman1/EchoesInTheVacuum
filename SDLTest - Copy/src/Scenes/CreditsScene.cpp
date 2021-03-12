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
	/*titleLable = new GameObject();
	highscoreLable = new GameObject();
	RetryObj = new GameObject();
	quitObj= new GameObject();*/

	TextureManager::get().loadTexture("background", "assets/background_02_static.png");
	/*TextureManager::get().loadFont("title", "assets/fonts/neuropol.ttf", 60);
	TextureManager::get().loadFont("score", "assets/fonts/neuropol.ttf", 30);
	TextureManager::get().loadFont("button", "assets/fonts/neuropol.ttf", 30);*/

	gb->addComponent<Sprite>(Game::get().getRenderer(), "background");
	/*titleLable->addComponent<UILabel>(Game::get().getRenderer(), "", 550, 60, "title");
	highscoreLable->addComponent<UILabel>(Game::get().getRenderer(), "", 550, 260, "score");

	titleLable->getComponent<UILabel>().setFontColor({ 255,32,21 });
	titleLable->getComponent<UILabel>().setText("HighScore");
	highscoreLable->getComponent<UILabel>().setFontColor({ 0,128,0 });
	highscoreLable->getComponent<UILabel>().setText("Highest Score: " + GameScore::get().getHighScore());*/

	manager->addGameObject(gb);
	//manager->addGameObject(titleLable);
	//manager->addGameObject(highscoreLable);
}

void CreditsScene::update(float deltaTime)
{
	if (sceneFinished == true) { return; }

}
