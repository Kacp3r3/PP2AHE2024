#include <iostream>
#include <fstream>
using namespace std;

/*

https://www.nco.ncep.noaa.gov/pmb/docs/on388/
https://www.nco.ncep.noaa.gov/pmb/docs/on388/
https://www.nco.ncep.noaa.gov/pmb/docs/on388/
https://www.nco.ncep.noaa.gov/pmb/docs/on388/

Do czytania bajtów z pliku najlepiej użyć metody read(tablica, rozmiar);

*/
int main()
{
	fstream grib;
	//Otwarcie pliku w trybie do odczytu oraz trybie binarnym, koniecznie użyć binarnego or - | do złączenia tych flag
	grib.open("all.grib", std::ios::in | std::ios::binary);

	if (!grib.is_open())
	{
		cout << "Nie udalo sie otworzyc pliku!\n";
		return -1;
	}


	uint32_t start_section_0=0;

	uint8_t byte;
	uint8_t byte2;
	uint8_t byte3;
	uint8_t byte4;


	//Szukamy "GRIB" w pliku
	while (!grib.eof())
	{
		grib >> byte;
		//Jeżeli znalazłem G
		if (byte == 'G')
		{
			//Wczytaj kolejne 3 bajty
			grib >> byte2 >> byte3 >> byte4;
			if (byte2 == 'R' && byte3 == 'I' && byte4 == 'B')
			{
				//I jeżeli są rowne RIB to znalazłem słowo GRIB
				cout << "Znalazlem GRIB na pozycji: " << (uint32_t)grib.tellg() - 4 << "\n";
				//Start sekcji 0 to aktualna pozycja (tellg)  - 4 bajty ( dlugosc słowa GRIB)
				start_section_0 = (uint32_t)grib.tellg() - 4;
				break;
			}
		}
	}

	//Szukamy 7777 oznaczajacego koniec pliku
	while (!grib.eof())
	{
		grib >> byte;
		if (byte == '7')
		{
			grib >> byte2 >> byte3 >> byte4;
			if (byte2 == '7' && byte3 == '7' && byte4 == '7')
			{
				cout << "Znalazlem 7777 na pozycji: " << (uint32_t)grib.tellg() - 4 << "\n";
				break;
			}
		}
	}

	//Seekg - Przesun kursor na zadaną pozycje w pliku
	grib.seekg(start_section_0 + 4);
	std::cout << "Current pos: " << grib.tellg() << "\n";
	uint32_t message_len = 0;

	//Wczytujemy kolejno trzy bajty i umieszczamy je w 4 bajtowej zmiennej
	for (int i = 0; i < 3; ++i)
	{
		uint8_t tmp;
		grib >> tmp;

		//Z odpowiednim binarnym przesunięciem o wielokrotnosc 8, co daje nam kolejno 16, 8 , 0;
		// B1 = 11110000
		// B2 = 00111100
		// B3 = 00001111
		// Messagelen = B1 << 16 | B2 << 8 | B3
		// 11110000 00000000 00000000 B1 << 16
		// 00000000 00111100 00000000 B2 << 8
		// 00000000 00000000 00001111 B3 << 0
		// 11110000 00111100 00001111 Messagelen - wynik

		message_len |= (static_cast<uint32_t>(tmp) << (8 * (2 - i)));
	}

	cout << "Dlugosc wiadomosci: " << message_len << "\n";


	//Pomijamy jeden byte
	grib >> byte;


	uint32_t start_section_1 = grib.tellg();

	//Wczytujemy kolejno trzy bajty i umieszczamy je w 4 bajtowej zmiennej
	uint32_t section_1_length = 0;
	for (int i = 0; i < 3; ++i)
	{
		uint8_t tmp;
		grib >> tmp;

		//Z odpowiednim binarnym przesunięciem o wielokrotnosc 8, co daje nam kolejno 16, 8 , 0;
		section_1_length |= (static_cast<uint32_t>(tmp) << (8 * (2 - i)));
	}

	cout << "Dlugosc sekcji 1 : " << section_1_length << "\n";

	//Pomijamy jeden byte
	grib >> byte;

	uint8_t center_id;
	grib >> center_id;

	cout << "Center id: " << (int)center_id;

	uint8_t process_id;
	grib >> process_id;
	cout << "Process id: " << (int)process_id;

	grib.seekg(start_section_1+12);

	char byte_char;


	//grib >> byte >> byte2 >> byte3 >> byte4;



	
	//PRAWIDŁOWY SPOSOB NA ODCZYTYWANIE DANYCH Z PLIKU BINARNEGO
	grib.read(&byte_char, 1);
	cout << "\nYear: " << int(byte_char) << "\n";
	grib.read(&byte_char, 1);
	cout << "Month: " << int(byte_char) << "\n";
	grib.read(&byte_char, 1);
	cout << "Day: " << int(byte_char) << "\n";
	grib.read(&byte_char, 1);
	cout << "Hour: " << int(byte_char) << "\n";
	grib.read(&byte_char, 1);
	cout << "Minutes: " << int(byte_char) << "\n";
	
	return 0;
}