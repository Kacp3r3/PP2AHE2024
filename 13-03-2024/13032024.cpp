#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


template<typename T>
T razydwa(T a)
{
	return 2 * a;
}


int main3232232()
{
	cout << razydwa<int>(5) << "\n";
	cout << razydwa(2.5f) << "\n";
	cout << razydwa(5u) << "\n";
	cout << razydwa('a') << "\n";


	int liczby[10]; // Statyczna tablica

	int* liczby_dynamicznie = new int[20];
	delete[] liczby_dynamicznie; // Dynamiczna tablica


	std::vector<int> myVec;

	myVec.push_back(50);
	myVec.push_back(25);
	myVec.push_back(10);

	//myVec.pop_back(); Usun ostatni element
	std::cout << "Rozmiar vektora: " << myVec.size() << '\n'; //Aktualny rozmiar len(nazwa_listy)

	// myVec[0]  // 50

	for (int vecElement : myVec)
	{
		cout << vecElement << " ";
	}
	cout << "\n";


	try
	{
		
		/*int input;

		cin >> input;

		if (input == 5)
		{
			throw std::exception("Bad number");
		}*/
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}

	myVec.clear();
	std::cout << "Rozmiar vektora: " << myVec.size() << '\n';


	std::fstream image;

	image.open("letterj.pbm", std::ios::in);

	if (image.is_open())
	{
		std::string fileType;
		std::string comment;
		int widht, height;
		int pixelValue;
		std::vector<int> pixels;

		std::getline(image, fileType);
		std::getline(image, comment);
		image >> widht >> height;

		for (int i = 0; i < widht * height; ++i)
		{
			image >> pixelValue;
			pixels.push_back(pixelValue);
		}

		std::cout << "Szerokosc: " << widht << " Wysokosc: " << height << '\n';
		for (int i=0; i<pixels.size(); ++i)
		{
			cout << pixels[i] << " ";
			if ((i+1) % 6 == 0) cout << "\n";
		}
		cout << "\n";


		/*int zeroCounter = 0;
		int oneCounter = 0;

		for (int pixel : pixels)
		{
			if (pixel == 0) zeroCounter++;
			else oneCounter++;
		}

		cout << "0 - " << zeroCounter << " | 1 - " << oneCounter << "\n";*/

		const int SIZE = 2;
		int counter[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			counter[i] = 0;
		}

		for (int pixel : pixels)
		{
			counter[pixel] += 1;
		}

		for (int i = 0; i < SIZE; ++i)
		{
			std::cout << i << " - " << counter[i] << "\n";
		}

	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku :(\n";
	}

	//razydwa("str");
	return 0;
}



/*

Podaj nazwe pliku: nazwa.xyz

Szerokosc obrazu: 200
Wysokosco brazu: 500
Najczęściej wystepujacy pixel to  0-1/0-255/3x0-255  i wystapił 400 razy
Liczba unikalnych kolorow:  500

Czy chcesz wczytać kolejny plik(tak/nie): nie
*/