#include "PredefinedSceneHelper.h"
#include "../Common/BackgroundEffect.h"

void PredefinedSceneHelper::addMainSceneAssets()
{
	TextureManager::get().loadTexture("background", "assets/background_02_static.png");
	TextureManager::get().loadTexture("play", "assets/main_button_1.png");
	TextureManager::get().loadTexture("music", "assets/main_button_2.png");
	TextureManager::get().loadTexture("logo", "assets/game_logo_small.png");
	TextureManager::get().loadTexture("toggleSymbol", "assets/button_arrow_right.png");
	TextureManager::get().loadTexture("playSymbol", "assets/control_fuel_icon_alarm.png");
	TextureManager::get().loadFont("gameFont", "assets/fonts/neuropol.ttf", 30);
	TextureManager::get().loadFont("gameFontLarge", "assets/fonts/neuropol.ttf", 60);
	SoundManager::Instance()->loadMusic("mainMusic", "assets/_Art/Audio/gameMusic.mp3");
	SoundManager::Instance()->setVolume(10); // Value from 0 to 120
	SoundManager::Instance()->playMusic("mainMusic");
}

void PredefinedSceneHelper::addMainSceneObjects(GameObjectManager* manager)
{
	GameObject* gb = new GameObject(), * playButtonObj = new GameObject(), * musicButtonObj = new GameObject(), * logoObj = new GameObject(), * playLabelObj = new GameObject(),
		* logoLable = new GameObject(), * playLable = new GameObject(), * toggleLable = new GameObject(), * toggleIndicator = new GameObject(), * playSymbol = new GameObject();

	gb->addComponent<Sprite>(Game::get().getRenderer(), "background");
	playButtonObj->addComponent<Sprite>(Game::get().getRenderer(), "play");
	musicButtonObj->addComponent<Sprite>(Game::get().getRenderer(), "music");
	logoObj->addComponent<Sprite>(Game::get().getRenderer(), "logo");
	logoLable->addComponent<UILabel>(Game::get().getRenderer(), "", 550, 60, "gameFontLarge");
	playLable->addComponent<UILabel>(Game::get().getRenderer(), "", 880, 440, "gameFont");
	toggleLable->addComponent<UILabel>(Game::get().getRenderer(), "", 880, 640, "gameFont");
	toggleIndicator->addComponent<Sprite>(Game::get().getRenderer(), "toggleSymbol");
	playSymbol->addComponent<Sprite>(Game::get().getRenderer(), "playSymbol");

	logoObj->getComponent<Transform>().position = Vector2<float>(850.0f, 140.0f);
	playButtonObj->getComponent<Transform>().position = Vector2<float>(750.0f, 390.0f);
	musicButtonObj->getComponent<Transform>().position = Vector2<float>(750.0f, 590.0f);
	toggleIndicator->getComponent<Transform>().position = Vector2<float>(790.0f, 620.0f);
	playSymbol->getComponent<Transform>().position = Vector2<float>(789.0f, 430.0f);
	playButtonObj->getComponent<Transform>().scale = Vector2<float>(0.4f, 0.4f);
	musicButtonObj->getComponent<Transform>().scale = Vector2<float>(0.5f, 0.5f);
	logoObj->getComponent<Transform>().scale = Vector2<float>(1.5f, 1.5f);
	playSymbol->getComponent<Transform>().scale = Vector2<float>(0.5f, 0.5f);

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
	manager->addGameObject(playSymbol);
}

void PredefinedSceneHelper::addGameSceneAssets(int enemyCount)
{
	SoundManager::Instance()->loadEffect("shootSound", "assets/_Art/Audio/singleShot.mp3");
	TextureManager::get().loadTexture("smallStarGroup1", "assets/_Art/BackgroundArt/SmallStarGroup.png");

	TextureManager::get().loadTexture("healthBar", "assets/_Art/PNG/points_powerup_lifes.png");
	TextureManager::get().loadTexture("loadingBar", "assets/_Art/PNG/loading.png");
	TextureManager::get().loadTexture("waveCounterBar", "assets/_Art/PNG/points_powerup_lifes_03.png");
	

	for (int i = 1;i <= enemyCount;i++) {
		TextureManager::get().loadTexture("enemy" + CommonFunctions::numToString(i), "assets/_Art/Enemies/enemy" + CommonFunctions::numToString(i) + ".png");
	}

	TextureManager::get().loadTexture("player", "assets/Ship.png");
	TextureManager::get().loadTexture("bullet", "assets/bullet_blaster_small_single.png");
	TextureManager::get().loadFont("gameFont", "assets/fonts/neuropol.ttf", 30);
	TextureManager::get().loadFont("gameFontSmall", "assets/fonts/neuropol.ttf", 19);
	TextureManager::get().loadFont("gameFontLarge", "assets/fonts/neuropol.ttf", 40);

}

void PredefinedSceneHelper::addGameSceneObjects(GameObjectManager* manager, ObjectPool* bulletPool, GameObject* playerObj, GameObject* scoreLabel, GameObject * healthLabel,
	GameObject* waveLabel, GameObject* cooldownLable)
{

	addGameSceneBackgroundObjects(manager);

	GameObject *healthImage = new GameObject();
	healthImage->addComponent<Sprite>(Game::get().getRenderer(), "healthBar");
	healthImage->getComponent<Transform>().position = {50,20};
	healthImage->getComponent<Transform>().rotation = 0;
	healthImage->getComponent<Transform>().scale = 0.5;
	manager->addGameObject(healthImage);



	GameObject* loadingImage = new GameObject();
	loadingImage->addComponent<Sprite>(Game::get().getRenderer(), "loadingBar");
	loadingImage->getComponent<Transform>().position = { 900,10 };
	loadingImage->getComponent<Transform>().rotation = 180;
	loadingImage->getComponent<Transform>().scale = 0.3;
	manager->addGameObject(loadingImage);


	GameObject* waveCounterImage = new GameObject();
	waveCounterImage->addComponent<Sprite>(Game::get().getRenderer(), "waveCounterBar");
	waveCounterImage->getComponent<Transform>().position = { 1700,20 };
	waveCounterImage->getComponent<Transform>().rotation = 0;
	waveCounterImage->getComponent<Transform>().scale = 0.5;
	manager->addGameObject(waveCounterImage);

	
	waveLabel->addComponent<UILabel>(Game::get().getRenderer(), "", 1010, 43, "gameFontSmall");
	waveLabel->getComponent<UILabel>().setText(" 1"); 
	manager->addGameObject(waveLabel);


	cooldownLable->addComponent<UILabel>(Game::get().getRenderer(), "", 1767, 70, "gameFontLarge");
	cooldownLable->getComponent<UILabel>().setText("9"); 
	manager->addGameObject(cooldownLable);




	healthLabel->addComponent<UILabel>(Game::get().getRenderer(), "", 105, 90, "gameFontSmall");
	healthLabel->getComponent<UILabel>().setText("100%"); 
	manager->addGameObject(healthLabel);

	scoreLabel->addComponent<UILabel>(Game::get().getRenderer(), "", 230, 75, "gameFont");
	scoreLabel->getComponent<UILabel>().setText(CommonFunctions::numToString(GameScore::get().getGameScore()));
	manager->addGameObject(scoreLabel);
	
	playerObj->addComponent<Ship>(bulletPool);
	playerObj->getComponent<Transform>().position = {100,500};


	for (auto const& gb : bulletPool->returnAllGameObjectList()) {
		gb->getComponent<Transform>().setPosition(Vector2<float>(-5000, -5000));
		gb->addComponent<Projectile>(bulletPool);
		gb->addComponent<Rigibody2D>(0, 15, 0);
		gb->addComponent<BoxCollider2D>(Game::get().getRenderer(), 40, 40, "Bullet");
		gb->addComponent<Sprite>(Game::get().getRenderer(), "bullet");
		gb->getComponent<Transform>().rotation = 90;

		manager->addGameObject(gb);
	}

	healthLabel->getComponent<UILabel>().setText("100%");

	manager->addGameObject(playerObj);


}


void PredefinedSceneHelper::addCreditSceneAssets()
{
	TextureManager::get().loadTexture("background", "assets/background_02_static.png");
	TextureManager::get().loadFont("title", "assets/fonts/neuropol.ttf", 60);
	TextureManager::get().loadFont("gameFont", "assets/fonts/neuropol.ttf", 30);
	TextureManager::get().loadFont("button", "assets/fonts/neuropol.ttf", 40);
}

void PredefinedSceneHelper::addCreditSceneObjects(GameObjectManager* manager)
{
	GameObject* gb = new GameObject(), * titleLable = new GameObject(), * highscoreLable = new GameObject(), 
		* quitObj = new GameObject(), * playerScoreLable = new GameObject(), * RetryObj = new GameObject();

	gb->addComponent<Sprite>(Game::get().getRenderer(), "background");
	titleLable->addComponent<UILabel>(Game::get().getRenderer(), "", 745, 60, "title");
	highscoreLable->addComponent<UILabel>(Game::get().getRenderer(), "", 760, 260, "gameFont");
	playerScoreLable->addComponent<UILabel>(Game::get().getRenderer(), "", 762, 320, "gameFont");
	RetryObj->addComponent<UILabel>(Game::get().getRenderer(), "", 700, 420, "button");
	quitObj->addComponent<UILabel>(Game::get().getRenderer(), "", 1100, 420, "button");

	titleLable->getComponent<UILabel>().setFontColor({ 255,32,21 });
	titleLable->getComponent<UILabel>().setText("HighScore");
	highscoreLable->getComponent<UILabel>().setFontColor({ 0,128,0 });
	highscoreLable->getComponent<UILabel>().setText("Highest Score: " + std::to_string(GameScore::get().getHighScore()));
	playerScoreLable->getComponent<UILabel>().setFontColor({ 128,128,0 });
	playerScoreLable->getComponent<UILabel>().setText("your Score: " + std::to_string(GameScore::get().getGameScore()));
	RetryObj->getComponent<UILabel>().setFontColor({ 255,255,255 });
	RetryObj->getComponent<UILabel>().setText("Retry");
	quitObj->getComponent<UILabel>().setFontColor({ 255,255,255 });
	quitObj->getComponent<UILabel>().setText("Quit");

	manager->addGameObject(gb);
	manager->addGameObject(titleLable);
	manager->addGameObject(highscoreLable);
	manager->addGameObject(playerScoreLable);
	manager->addGameObject(RetryObj);
	manager->addGameObject(quitObj);


}

void PredefinedSceneHelper::addGameSceneBackgroundObjects(GameObjectManager* manager)
{
	// No need for creating a pool for these coz they will be created one and lopp when their pos x is offset . not like Bullet and Enemy 
	// where we are destroying and fetching back . 

	// Fast coding as have to deliver the project :) . will make the background hard coded 

	float tempX = 0;
	float tempY = 50;
	for (int i = 0; i <= 6;i++) {
		if (i == 4) {
			tempY = 500;
			tempX = 0;
		}

		GameObject* star = new GameObject();
		star->addComponent<Sprite>(Game::get().getRenderer(), "smallStarGroup1");
		star->getComponent<Transform>().position = { tempX,tempY };
		star->addComponent<BackgroundEffect>(0,4,true);
		//star->getComponent<Transform>().scale = 2;

		manager->addGameObject(star);
		tempX += 600;

	}
//C:\Users\Gento_PC\OneDrive\Desktop\SpaceShooting - master\Assets\_Art\BackgroundArt
}