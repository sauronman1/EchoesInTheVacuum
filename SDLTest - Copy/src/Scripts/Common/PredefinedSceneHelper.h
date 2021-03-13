#pragma once
#include "../../Game.h"
#include "../../Game Engine/GameObject/GameObject.h"
#include "../../Game Engine/Essentials/TextureManager.h"
#include "../../Game Engine/GameObject/Components/Sprite.h"
#include "../../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../../Game Engine/SDL Events/SDLEvent.h"
#include "../../Game Engine/Essentials/SoundManager/SoundManager.h"
#include "../../Game Engine/GameObject/Components/UILabel.h"
#include "../../Game Engine/GameObject/Components/Projectile.h"
#include "../../Game Engine/GameObject/Components/BoxCollider2D.h"
#include "../../Scripts/Player/Ship.h"
#include "../../Scripts/Common/GameScore.h"




class PredefinedSceneHelper {
public:

	// Menu Scene
	static void addMainSceneAssets() {
		TextureManager::get().loadTexture("background", "assets/background_02_static.png");
		TextureManager::get().loadTexture("play", "assets/main_button_1.png");
		TextureManager::get().loadTexture("music", "assets/main_button_2.png");
		TextureManager::get().loadTexture("logo", "assets/game_logo_small.png");
		TextureManager::get().loadTexture("toggleSymbol", "assets/button_arrow_right.png");
		TextureManager::get().loadTexture("playSymbol", "assets/control_fuel_icon_alarm.png");
		TextureManager::get().loadFont("neuropol", "assets/fonts/neuropol.ttf", 30);
		TextureManager::get().loadFont("neuropolTitle", "assets/fonts/neuropol.ttf", 60);
		SoundManager::Instance()->loadMusic("mainMusic", "assets/_Art/Audio/gameMusic.mp3");
		SoundManager::Instance()->setVolume(10); // Value from 0 to 120
		SoundManager::Instance()->playMusic("mainMusic");
	 }
	static void addMainSceneObjects(GameObjectManager * manager) {

		GameObject* gb = new GameObject(), * playButtonObj = new GameObject(), * musicButtonObj = new GameObject(), * logoObj = new GameObject(), * playLabelObj = new GameObject(),
			* logoLable = new GameObject(), * playLable = new GameObject(), * toggleLable = new GameObject(), * toggleIndicator = new GameObject(), * playSymbol = new GameObject();

		gb->addComponent<Sprite>(Game::get().getRenderer(), "background");
		playButtonObj->addComponent<Sprite>(Game::get().getRenderer(), "play");
		musicButtonObj->addComponent<Sprite>(Game::get().getRenderer(), "music");
		logoObj->addComponent<Sprite>(Game::get().getRenderer(), "logo");
		logoLable->addComponent<UILabel>(Game::get().getRenderer(), "", 550, 60, "neuropolTitle");
		playLable->addComponent<UILabel>(Game::get().getRenderer(), "", 880, 440, "neuropol");
		toggleLable->addComponent<UILabel>(Game::get().getRenderer(), "", 880, 640, "neuropol");
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
	// Game Scene
	static void addGameSceneAssets(int enemyCount) {

		for (int i = 1;i <= enemyCount;i++) {
			TextureManager::get().loadTexture("enemy" + CommonFunctions::numToString(i), "assets/_Art/Enemies/enemy" + CommonFunctions::numToString(i) + ".png");
		}

		TextureManager::get().loadTexture("player", "assets/Ship.png");
		TextureManager::get().loadTexture("bullet", "assets/bullet_blaster_small_single.png");
		TextureManager::get().loadFont("score", "assets/fonts/neuropol.ttf", 30);
	}
	static void addGameSceneObjects(GameObjectManager* manager, ObjectPool * bulletPool, GameObject * playerObj,GameObject * scoreLabel) {


		playerObj->addComponent<Ship>(bulletPool);
		scoreLabel->addComponent<UILabel>(Game::get().getRenderer(), "", 880, 60, "score");
		scoreLabel->getComponent<UILabel>().setFontColor({ 0,128,0 });
		scoreLabel->getComponent<UILabel>().setText("score: " + std::to_string(GameScore::get().getGameScore()));
		manager->addGameObject(playerObj);
		manager->addGameObject(scoreLabel);

		
		for (auto const& gb : bulletPool->returnAllGameObjectList()) {
			gb->getComponent<Transform>().setPosition(Vector2<float>(-5000, -5000));
			gb->addComponent<Projectile>(bulletPool);
			gb->addComponent<Rigibody2D>(0, 6, 0);
			gb->addComponent<BoxCollider2D>(Game::get().getRenderer(), 50, 50, "Bullet");
			gb->addComponent<Sprite>(Game::get().getRenderer(), "bullet");
			gb->getComponent<Transform>().rotation = 90;

			manager->addGameObject(gb);
		}




	}

private:
};
