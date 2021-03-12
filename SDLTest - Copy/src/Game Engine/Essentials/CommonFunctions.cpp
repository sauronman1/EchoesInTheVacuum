#include "CommonFunctions.h"
#include <iostream>
#include <fstream>
#include <string>

void CommonFunctions::printConsoleMessage(std::string messageToPrint)
{
	std::cout << messageToPrint << std::endl;

}

void CommonFunctions::printErrorMessage(std::string messageToPrint)
{
	std::cerr << messageToPrint << std::endl;

}

std::string CommonFunctions::readFromFile(std::string filePath)
{
	std::string output = "";
	std::string line;
	std::ifstream myfile(filePath);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::cout << line << '\n';
			output = output + line + "\n";
		}
		myfile.close();
		return output;
	}
	else std::cout << "Unable to open file";
	return "";
}

std::string CommonFunctions::readFirstLineOnly(std::string filePath)
{
	std::string output = "";
	std::string line;
	std::ifstream myfile(filePath);
	if (myfile.is_open())
	{
		if (getline(myfile, line))
		{
			output = output + line + "\n";
		}
		myfile.close();
		return output;
	}
	else printConsoleMessage("Unable to open file");
	return "";
}

void CommonFunctions::writeToFile(std::string textToWrite, std::string filePath)
{
	std::ofstream myfile(filePath);
	if (myfile.is_open())
	{
		myfile << textToWrite+ "\n";
		myfile.close();
	}
	else printConsoleMessage("Unable to open file");

}




std::string CommonFunctions::numToString(int number)
{

	return std::to_string(number);
}


std::string CommonFunctions::numToString(float number)
{
	return std::to_string(number);
}

std::string CommonFunctions::numToString(double number)
{
	return std::to_string(number);
}



