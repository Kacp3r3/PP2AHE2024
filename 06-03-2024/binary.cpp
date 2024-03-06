#include <iostream>
#include <fstream>
#include <string>

using namespace std;


std::string encrypt(char letter)
{
	std::string rv;

	if (letter == '\n')
	{
		rv += "\n";
		return rv;
	}

	for (int i = 0; i < 8; ++i)
	{
		int a = 12;
		int abinary = 0b1100;
		int ahex = 0xC;

		//Przesuniecie bitowe
		// 1100
		// 1100 >> 2
		// 0011 >> 1
		// 0001

		// 01
		// 10 &
		// 00

		// 01
		// 01 &
		// 01

		//Jednolinijkowy If
		char bit = (letter & 1) == 1 ? '1' : '0';

		letter = letter >> 1;

		rv = bit + rv;
	}

	return rv;
}


int main()
{
	std::string file_content;

	fstream read;
	read.open("opowiesc.txt", std::ios::in);
	if (read.is_open())
	{
		string line;
		while (std::getline(read, line))
		{
			file_content += line;
			file_content += "\n";
		}
	}

	cout << "Tekst do zakodowania \n" << file_content << '\n';

	read.close();

	fstream write;
	write.open("encrypted.txt", std::ios::out);

	if (write.is_open())
	{
		for (int i = 0; i < file_content.length(); ++i)
		{
			std::string binary = encrypt(file_content[i]);
			write << binary << " ";
		}
	}

	write.close();

}