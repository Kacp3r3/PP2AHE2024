#include <iostream>

//Biblioteka z funkcji od czasu
#include <ctime>
using namespace std;

//  Opis modulo
//   10 / 3  = 3 1/3
//   10 % 3  = 1
//   3 + 3 + 3 = 9
//   10 - 9 = 1
//
//	27 % 5 = 2
//
//  X % n = <0;n-1>
// 
//  % 5 = 0,1,2,3,4
//  


//typ_zwracay nazwa(typ_arg1 arg1, typ_arg2 arg2)

//Deklaracja funkcji potega
int potega(int, int);


//Funkcja dostaje kopie
void func(int x, int y)
{
	x = 5;
	y = 5;

	cout << "Inside func: " << x << " " << y << endl;
}

//& sprawia ze funkcja dostaje orginalne zmienne
void func_ref(int& x, int& y)
{
	x = 5;
	y = 5;

	cout << "Inside func: " << x << " " << y << endl;
}

//Wskazniki na orginalne zmienne
void func_pointer(int* x, int* y)
{
	*x = 2;
	*y = 1;

	cout << "Inside func: " << *x << " " << *y << endl;
}

void fill(int arr[], int size, int val)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = val;
	}
}


int main()
{
	int a = 5;
	int b = 10;

	cout << a << " " << b << endl;
	func(a, b);
	cout << a << " " << b << endl;

	cout << "Func ref" << endl;
	cout << a << " " << b << endl;
	func_ref(a, b);
	cout << a << " " << b << endl;

	cout << "Func pointer" << endl;
	cout << a << " " << b << endl;
	func_pointer(&a, &b);
	cout << a << " " << b << endl;


	const int SIZE_TAB = 10;
	int tab[SIZE_TAB];

	fill(tab, SIZE_TAB, 100);

	for (int i = 0; i < SIZE_TAB; ++i)
	{
		cout << tab[i] << " ";
	}





	const int SIZE = 30;
	int numbers[SIZE];

	//Ustawienie ziarna dla generatora liczb pseudolosowych
	srand(time(NULL));

	for (int i = 0; i < SIZE; ++i)
	{
		//Losowanie liczby
		//numbers[i] = rand() % 100; // 0-99
		numbers[i] = rand() % 100 + 1; // 1-100
	}

	for (int i = 0; i < SIZE; ++i)
	{
		cout << numbers[i] << " ";
	}


	cout << "\n" << numbers << endl;

	// & - adres zmiennej
	// * - zerknij pod adres
	int foo = 12;
	int* pointer = &foo;

	cout << "Wartosc zmiennej foo: " << foo << endl;
	cout << "Adres zmiennej foo: " << &foo << endl;
	cout << "Wartosc zmiennej pointer: " << pointer << endl;
	cout << "Adres zmiennej pointer: " << &pointer << endl;
	cout << "Wartosc zmiennej wskazywanej przez pointer: " << *pointer << endl;


	short grades[] = { 5,4,3,2,1 };

	cout << endl;
	cout << "Adres pierwszego elementu: " << grades << endl;
	cout << "Adres drugiego elementu: " << grades+1 << endl;
	cout << "Adres trzeciego elementu: " << grades+2 << endl;
	cout << endl;
	cout << "Adres pierwszego elementu: " << &grades[0] << endl;
	cout << "Adres drugiego elementu: " << &grades[1] << endl;
	cout << "Adres trzeciego elementu: " << &grades[2] << endl;

	//Dynamicznie zaalokowana tablica
	int* dynamic_array = new int[6];

	//Wyzerowanie zawartosci tablicy
	for (int i = 0; i < 6; ++i)
	{
		dynamic_array[i] = 0;
	}

	//A tu z uzyciem fukncji memset
	std::memset(dynamic_array, 0, 6);


	//Przyklad wycieku pamieci
	/*for (;;)
	{
		int* tmp = new int[10];
		delete[] tmp; //Usuniecie tego delete crashuje program
	}*/
	
	//Delete z [] dla tablic
	delete[] dynamic_array;


	//Delete bez [] dla pojedynczych zmiennych
	int* number = new int;
	delete number;


	std::string str; // biblioteka string dodaje za nas na koncu 0 \0
	char str_old[] = "Ala ma kota"; // "" dodają za nas na koncu 0 \0
	char str_old2[] = { 'A', 'l', 'a', ' ', 'm', '\0', ' ', 'k', 'o', 't', 'a', '\0'};

	str += "Ala";
	str += " ma kota";

	cout << str << endl;
	cout << str_old << endl;
	cout << str_old2 << endl;
	cout << str_old2 + 6 << endl;



	return 0;
}

//Definicja funkcji potega
int potega(int a, int x)
{
	int rv = a;
	for (int i = 1; i < x; ++i)
	{
		rv *= a;
	}

	return rv;
}
