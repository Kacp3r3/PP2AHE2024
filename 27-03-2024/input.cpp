#include <iostream>


#include <conio.h> //getch i kbhit

#include <chrono> //literały s ms itp

#include <thread> //this_thread::sleep_for

using namespace std;
using namespace std::chrono_literals;

int main()
{

	int input{ 0 };
	while (input != 27 /* 27 == klawisz escape */)
	{
		if (_kbhit())
		{
			input = _getch();
			std::cout << "Wcisnales: " << input << "\n";
		}
		else
		{
			//std::cout << ".";
			std::this_thread::sleep_for(0.1s);
		}
	}



	return 0;
}