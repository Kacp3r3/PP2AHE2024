//Załączenie bilbioteki iostream - cin cout
#include <iostream>
#include <string>
//Nie musimy pisać std:: dzięki linijce poniżej
using namespace std;

/*
Wielo
Linijkowy
Komentarz
*/


int main()
{
	cout << "Hello World!" << endl; // Komentarz na koncu linii
	//Komentarz pod i nad kodem
	cout << "Hello" << " " << "World! \n";
	cout << "Hello" << " " << "World!" << endl;

	//typ nazwa = wartosc; - c++
	//nazwa = wartosc - python

	int i = 5; // Liczby całkowite Dodatnie i ujemne

	cout << "wartosc zmiennej i: " << i << endl;


	//Typy zmienno przecinkowe
	float f = 3.0f; //Liczby z przecinkiem
	double d = 3.; //Liczby z przecinkiem

	//Typ logiczny
	bool b = true;

	//Typy znakowe
	char c = 'F';
	string s = "Napis";


	cout << "Rozmiar int: " << sizeof(int) << endl;
	cout << "Rozmiar float: " << sizeof(float) << endl;
	cout << "Rozmiar double: " << sizeof(double) << endl;
	cout << "Rozmiar bool: " << sizeof(bool) << endl;
	cout << "Rozmiar char: " << sizeof(char) << endl;
	//cout << "Rozmiar string: " << sizeof(s) << endl;


	//Pobieranie znaków z konsoli
	//string imie;
	//int wiek;
	//cout << "Podaj mi swoje imie: ";
	//cin >> imie;
	//cout << "Podaj mi swoj wiek: ";
	//cin >> wiek;

	//cout << "Witaj " << imie << " masz " << wiek << "lat\n";

	int A = 10;
	int B = 20;
	int C = 30;

	//Wynikiem zdania logicznego jest wartość prawda fałsz
	// lewy operandu   znaku logicznego   prawy operand
	//    20                 >               5
	//                  true
	// > < >= <= == != !
	// && - and    || - or

	if ( A > C/* warunek */)
	{
		cout << "A jest wieksze od C\n";
	}
	else if ( A > B /* warunek */)
	{
		cout << "A jest wieksze od B\n";
	}
	else
	{
		cout << "A jest najmniejsza liczba\n";
	}

	if (A > B && A > C)
	{
		cout << "A jest najwieksze\n";
	}
	else if (B>A && B>C)
	{
		cout << "B jest najwieksze\n";
	}
	else if (C > A && C > B)
	{
		cout << "C jest najwieksze\n";
	}
	else
	{
		cout << "Więcej niz jedna liczba jest największa\n";
	}

	//Funkcja z języka C
	printf("Hello World!\n");

	int money = 60;

	printf("Mam przy sobie %d zl\n", money);


	int how_many_times = 5;
	/*cout << "Ile razy powtorzyc petle: ";
	cin >> how_many_times;*/

	for( int i = 0  /*Segment 1*/;  i < how_many_times   /*Segment 2*/;  i++ /* Segemnt 3*/)
	{
		cout << "Czekolada nr " << how_many_times- 1 - i << "\n";
	}

	for (int i = how_many_times-1  ; i>=0  ; i-- )
	{
		cout << "Czekolada nr " << i << "\n";
	}


	int xd = 15; 
	while (xd < 10 /*warunek zakonczenia petli*/)
	{
		cout << "while - i wynosi: " << xd << "\n";
		xd++;
	}

	//Pętla do while wykona sie zawsze przynajmniej jeden raz
	do
	{
		cout << "dowhile - i wynosi: " << xd << "\n";
		xd++;
	} while (xd < 10 /*warunek*/);


	char choice = 'A';
	for (int i = 0; i < 4; ++i)
	{
		switch (choice)
		{
		case 'A':
			cout << "Wybrales A\n";
			//Usuniecie break sprawia ze wykona sie tez case B break;

		case 'B':
			cout << "Wybrales B\n";
			break;

		case 67:
			cout << "Wybrales C\n";
			break;

		default:
			cout << "DEFAULT!!!\n";
		}

		choice++;
	}
	
	// break przerywa
	// continue, przerywa daną iteracje, ale nie cała petle

	cout << "Petla z break: \n";
	for (int i = 0; i < 5; ++i)
	{
		if (i == 3) break;
		cout << i << endl;
	}

	cout << "Petla z continue\n";
	for (int i = 0; i < 5; ++i)
	{
		if (i == 3) continue;
		cout << i << endl;
	}



	//Spytaj uzytkownika o rozmiar kwadratu i trojkat
	//Spytaj o znak z jakiego ma byc zrobiony
	//3 %
	// %%%
	// %%%
	// %%%

	// %
	// %%
	// %%%



	int length;
	char building_block;

	cout << "Podaj dlugosc boku: ";
	cin >> length;

	cout << "Z jakiego znaku zbudowac ksztalty: ";
	cin >> building_block;


	//Kwadrat
	cout << "\n";
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			cout << building_block;
		}
		cout << "\n";
	}

	//Trojkat
	cout << "\n";
	for (int i = 0; i < length; ++i)
	{
		for (int j = length-1-i; j < length; ++j)
		{
			cout << building_block;
		}
		cout << "\n";
	}

	return 0;
}
