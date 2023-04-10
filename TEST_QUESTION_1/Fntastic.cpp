// Fntastic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>

void ConvertString(std::string& str)
{
	std::unordered_map<char, int> meetingsMap;

	const char c_UniqueLetter = '(';
	const char c_CommonLetter = ')';

	for (char& ele : str)
	{
		if (isupper(ele))
		{
			ele = tolower(ele);
		}

		meetingsMap[ele]++;
	}

	for (const char ele : str)
	{
		char displayChar = meetingsMap[ele] > 1 ? c_CommonLetter : c_UniqueLetter;
		std::cout << displayChar;
	}

}

int main()
{
	std::string test = "Success";
	ConvertString(test);

	std::cin.get();
	return 0;
}

