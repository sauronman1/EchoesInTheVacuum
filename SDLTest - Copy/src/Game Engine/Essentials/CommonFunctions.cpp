#include "CommonFunctions.h"
#include <string>
#include <iostream>


void CommonFunctions::printConsoleMessage(std::string messageToPrint)
{
	std::cout << messageToPrint << std::endl;

}

void CommonFunctions::printErrorMessage(std::string messageToPrint)
{
	std::cerr << messageToPrint << std::endl;

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



