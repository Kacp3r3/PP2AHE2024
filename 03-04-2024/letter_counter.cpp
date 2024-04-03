#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	system("chcp 1250");
	std::fstream fileIn;
	std::map<char, int> characters;

	fileIn.open("bibpl3.txt", std::ios::in);

	if (fileIn.is_open())
	{
		char tmp;
		while (!fileIn.eof())
		{
			fileIn >> tmp;
			characters[tmp]++;
		}
	}
	else
	{
		cout << "Nie udalo sie otworzyc pliku\n";
	}

	fileIn.close();

	int B = 15;

	//  []   () { Kod mojeje funckji lambda   }
	auto moja_lambda = [&B]() { B = 10; };

	std::vector<std::pair<char, int>> pairs;

	for (auto& it : characters) {
		pairs.push_back(it);
	}

	std::sort(pairs.begin(), pairs.end(),
		[]
		(std::pair<char,int>& lhs, std::pair<char, int>& rhs) 
		{
			return lhs.second > rhs.second;
		});


	for (auto [letter, count] : pairs)
	{
		std::cout << letter << ":" << count << "\n";
	}

	return 0;
}