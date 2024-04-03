#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	std::map<int, int> numbers;

	//Wylosowane 1000 liczb
	for (int i = 0; i < 100000; ++i)
	{
		numbers[rand() % 100 + 1]++;
	}

	std::cout << numbers.size() << std::endl;

	int height = numbers.size();

	int width = 0;
	for (auto [number, count] : numbers)
	{
		if (width < count) width = count;
	}


	std::fstream ppmOut;
	ppmOut.open("graph.ppm", std::ios::out);

	if (ppmOut.is_open())
	{
		/*
		P3
		#opcjonalnie komentarz
		100 100
		255
		123 32 123 
		*/
		ppmOut << "P3\n" << "#Wykres utworzony przez Xyz\n";
		ppmOut << width << " " << height << "\n";
		ppmOut << 255 << "\n";

		for (auto [number, count] : numbers)
		{
			int R = rand() % 255 + 1;
			int G = rand() % 255 + 1;
			int B = rand() % 255 + 1;
			for (int i = 0; i < width; ++i)
			{
				if (i < count)
				{
					ppmOut << R << " " << G << " " << B << " ";
				}
				else
				{
					ppmOut << 255 << " " << 255 << " " << 255 << " ";
				}
			}
			ppmOut << "\n";
		}
	}
	else
	{
		std::cout << "Nie udalo sie utworzyc pliku!" << std::endl;
	}

	ppmOut.close();


	/*
	wartosc   separator wartosc sepearator
	231;12312;3123123
	123123;123123;31231
	
	liczba;ilosc_wystapien;
	1;150;
	2;300;
	3;50;
	...
	...
	*/

	std::fstream csv;
	csv.open("losowe.csv", std::ios::out);

	if (csv.good())
	{
		csv << "liczba;ilosc_wystapien;\n";
		for (auto [liczba, count] : numbers)
		{
			csv << liczba << ";" << count << ";\n";
		}

	}
	else
	{
		cout << "Nie udalo sie utworzyc losowe.csv\n";
	}
	csv.close();



	return 0;
}

