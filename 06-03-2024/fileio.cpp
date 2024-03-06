#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	//Przyklad zapisywania danych do pliku
	fstream file;
	//std::ios::in do odczytu
	//std::ios::out do zapisu ( usunie istniejacy plik )
	//std::ios::app do nadpisywania
	//std::ios::binary otwarcia pliku w trybie binarnym

	file.open(/*Nazwa pliku*/"example.txt", /*Tryb*/std::ios::out);

	//Udalo sie otworzyc plik
	if (file.is_open())
	{
		file << 25 << " " << 50 << " " << 75 << " ";
	}
	//Nie udalo sie otworzyc pliku
	else
	{
		cout << "Nie udalo sie otworzyc pliku :(\n";
	}

	file.close();

	//Odczytywanie danych z pliku
	fstream file_read;
	file_read.open("opowiesc.txt", std::ios::in);
	//Udalo sie otworzyc plik
	if (file_read.is_open())
	{
		std::string word;
		while(!file_read.eof())
		{
			file_read >> word;
			cout << word << " ";
		}
	}
	//Nie udalo sie otworzyc pliku
	else
	{
		cout << "Plik nie istienieje :(";
	}

	file_read.close();


	std::cout << "\n\n";

	//Odczytywanie danych z pliku
	fstream file_read_lines;
	file_read_lines.open("opowiesc.txt", std::ios::in);
	//Udalo sie otworzyc plik
	if (file_read_lines.is_open())
	{
		//Wczytanie całej linii z pliku ze spacjami
		std::string line;
		while (std::getline(file_read_lines, line))
		{
			cout << line << '\n';
		}
	}
	//Nie udalo sie otworzyc pliku
	else
	{
		cout << "Plik nie istienieje :(";
	}

	file_read_lines.close();




	//Przyklad nadpisywania pliku
	fstream file_write;

	//2 binarnie   10
	//8 binarnie 1000
	// 2 | 8     1010
	file_write.open(/*Nazwa pliku*/"append_me.txt", std::ios::out | std::ios::app);

	//Udalo sie otworzyc plik
	if (file_write.is_open())
	{
		file_write << 25 << " " << 50 << " " << 75 << " \n";
	}
	//Nie udalo sie otworzyc pliku
	else
	{
		cout << "Nie udalo sie otworzyc pliku :(\n";
	}

	file_write.close();

	return 0;
}