#include <iostream>
#include <set>
#include <map>
#include <utility>

using namespace std;


void printBits(unsigned int n)
{
	const int Bits = 8 * sizeof n;
	char tmp[Bits + 1];

	for (int i = 0; i < Bits; ++i)
	{
		tmp[Bits - i - 1] = '0' + n % 2;
		n /= 2;
	}

	tmp[Bits] = 0;
	std::cout << tmp;
}


void showOperation(unsigned int a, unsigned int b, unsigned int result, char op)
{
	std::cout << "   ";
	printBits(a);
	std::cout << " (" << a << ")\n " << op << ' ';
	printBits(b);
	std::cout << " (" << b << ")\n = ";
	printBits(result);
	std::cout << " (" << result << ")\n\n";
}


int main()
{
	std::set<int> unique;

	unique.insert(5);
	unique.insert(15);
	unique.insert(25);

	std::cout << "Rozmair set: " << unique.size() << "\n";
	unique.insert(5);
	unique.insert(5);
	unique.insert(5);
	unique.insert(15);
	unique.insert(25);

	std::cout << "Rozmair set: " << unique.size() << "\n";



	std::map<char, int> letterCounter;

	std::string line = "ala ma kota i dwa psy slonce swieci lalala";

	for (char letter : line)
	{
		if (letterCounter.find(letter) == letterCounter.end())
		{
			letterCounter[letter] = 1;
		}
		else
		{
			letterCounter[letter] += 1;
		}
	}

	for (auto element : letterCounter)
	{
		std::cout << element.first << ": " << element.second << "\n";
	}



	std::pair<int, int> myPair;
	myPair.first = 15;
	myPair.second = 30;




	//P3
	//2 2
	// 128 250 12 12 250 0
	// 128 250 12 12 250 0

	// 0-255  - 1 Bajt
	// int    - 4 bajt

	int R = 0b11110000; //240
	int G = 0b00111100; //60
	int B = 0b00001111; //15



	int pixel = R << 16 | G << 8 | B;

	//11110000 << 16
	//11110000 00000000 00000000

	//00111100 << 8
	//00111100 00000000

	//00001111
	//00001111

	//11110000 00000000 00000000
	//         00111100 00000000
	//					00001111 OR
	//11110000 00111100 00001111

	cout << R << "\n";
	cout << G << "\n";
	cout << B << "\n";
	cout << pixel << "\n";








	int a = 0b00001111;
	showOperation(0b00001111, a << 4, a << 8, '?');







	return 0;
}