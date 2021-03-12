#pragma once
#include <sstream> 
#include "../../Game Engine/Essentials/CommonFunctions.h"

class GameScore
{
private:
	static int score;
public:
	static void incrementGameScore(int addToScore) {
		score += addToScore;
	}
	static void initScore() {
		score = 0;
	}
	static int getGameScore() {
		return score;
	}

	static int getHighScore()
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
	static void setHighScore(int score) {
		if (score > getHighScore()) {
			CommonFunctions::writeToFile(CommonFunctions::numToString(score), "test.xml");
		}
	}
};