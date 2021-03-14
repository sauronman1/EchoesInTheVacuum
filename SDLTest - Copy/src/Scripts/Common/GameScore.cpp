#include "GameScore.h"
GameScore* GameScore::s_instance = nullptr;

int GameScore::getWaveNumber()
{
	return waveCounter;
}

void GameScore::incrementWave()
{
	waveCounter++;
}

int GameScore::getHighScore()
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

void GameScore::setHighScore()
{
	if (score > getHighScore()) {
		CommonFunctions::writeToFile(CommonFunctions::numToString(score), "test.xml");
	}
}
