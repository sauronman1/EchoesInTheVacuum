#pragma once
#include <iostream>

 class CommonFunctions
{

public:
	// Overloating Numeric to String Parsing 
	static std::string numToString(int number);
	static std::string numToString(float number);
	static std::string numToString(double number);

	// Print to Console
	static void printConsoleMessage(std::string messageToPrint);
	static void printErrorMessage(std::string messageToPrint);

	static std::string readFromFile(std::string filePath);
	static std::string readFirstLineOnly(std::string filePath);
	static void writeToFile(std::string textToWrite, std::string filePath);
};

