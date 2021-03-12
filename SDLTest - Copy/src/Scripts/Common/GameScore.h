#pragma once
#include <sstream> 
#include "../../Game Engine/Essentials/CommonFunctions.h"

class GameScore
{
private:
	 int score;
		static  GameScore* s_instance;

public:

	GameScore() = default;
	~GameScore() = default;

	inline static GameScore& get() {
		
		if (s_instance == nullptr) {
			s_instance = new GameScore();
		}
		return *s_instance;
	}



	 void incrementGameScore(int addToScore) {
		score += addToScore;
	}
	 void initScore() {
		score = 0;
	}
	 int getGameScore() {
		return score;
	}

	 int getHighScore()
	{
		int x = 0; // return 0 if no score there.

		std::string scoreText = CommonFunctions::readFirstLineOnly("test.xml");

		if (scoreText.find("\n") != std::string::npos) {
			int pos = scoreText.find("\n");
			scoreText = scoreText.substr(0, pos);
		}

		std::stringstream geek(scoreText);
		geek >> x;

		return x;
	}
	 void setHighScore() {
		if (score > getHighScore()) {
			CommonFunctions::writeToFile(CommonFunctions::numToString(score), "test.xml");
		}
	}
};