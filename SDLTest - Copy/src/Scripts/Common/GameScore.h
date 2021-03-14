#pragma once
#include <sstream> 
#include "../../Game Engine/Essentials/CommonFunctions.h"

class GameScore
{
private:
	 int score;
		static  GameScore* s_instance;
		int waveCounter;

public:

	GameScore() = default;
	~GameScore() = default;

	inline static GameScore& get() {
		
		if (s_instance == nullptr) {
			s_instance = new GameScore();
		}
		return *s_instance;
	}

	 void incrementGameScore(int addToScore) {score += addToScore;}
	 void initScore() {score = 0; waveCounter = 1;}
	 int getGameScore() {return score;}

	 int getHighScore();
	 void setHighScore();

	 int getWaveNumber();
	 void incrementWave();
};