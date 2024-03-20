#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread> // aby uzywac std::this_thread::sleep_for
#include <chrono>



using namespace std::chrono_literals; // Uzywanie s ms itp
using namespace std;


const int WIDTH = 90;
const int HEIGHT = 15;

HANDLE console;
COORD snakePos;
COORD direction;
COORD scorePos;
COORD fruitPos;
int score = 0;


void draw_area()
{
	COORD pos;
	pos.X = 0;
	pos.Y = 0;

	SetConsoleCursorPosition(console, pos);

	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (i == 0 || j == 0 || (j == WIDTH - 1) || (i == HEIGHT - 1))
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
}


void move_snake()
{
	SetConsoleCursorPosition(console, snakePos);
	cout << " ";

	snakePos.X += direction.X;
	snakePos.Y += direction.Y;
	SetConsoleCursorPosition(console, snakePos);
	cout << "@";
}

void updateScore()
{
	SetConsoleCursorPosition(console, scorePos);
	cout << score;
}

void updateDirection(char user_input)
{
	switch (user_input)
	{
		case 'a':
		case 'A':
		{
			if (snakePos.X <= 1)
			{
				direction.X = 0;
			}
			else
			{
				direction.X = -1;
			}
			direction.Y = 0;
			break;
		}
		case 'd':
		case 'D':
		{
			if (snakePos.X >= WIDTH-2)
			{
				direction.X = 0;
			}
			else
			{
				direction.X = 1;
			}
			direction.Y = 0;
			break;
		}
		case 'w':
		case 'W':
		{

			direction.X = 0;
			if (snakePos.Y <=1)
			{
				direction.Y = 0;
			}
			else
			{
				direction.Y = -1;
			}
			break;
		}
		case 's':
		case 'S':
		{
			direction.X = 0;
			if (snakePos.Y >= HEIGHT-2)
			{
				direction.Y = 0;
			}
			else
			{
				direction.Y = 1;
			}

			break;
		}
		case 'p':
		case 'P':
		{
			score++;
			updateScore();
		}
		default:
			break;
	}
}

void generateFruit()
{
	do
	{
		fruitPos.X = rand() % (WIDTH - 2) + 1;
		fruitPos.Y = rand() % (HEIGHT - 2) + 1;

	} while (fruitPos.X == snakePos.X && fruitPos.Y == snakePos.Y);

	SetConsoleCursorPosition(console, fruitPos);
	cout << "&";
}

void checkSnakeFruitPosition()
{
	if (snakePos.X == fruitPos.X && snakePos.Y == fruitPos.Y)
	{
		score++;
		updateScore();
		generateFruit();
	}
}



int main()
{
	srand(time(NULL));

	//Uzyskanie handle do konsoli
	console = GetStdHandle(STD_OUTPUT_HANDLE);  

	//Ustawienie koloru tekstu na niebieski i tła na czarny
	SetConsoleTextAttribute(console, 1);

	draw_area();


	snakePos.X = WIDTH / 2;
	snakePos.Y = HEIGHT / 2;
	SetConsoleCursorPosition(console, snakePos);
	cout << "@";

	//Wynik w lewym dolnym "rogu"
	scorePos.X = 0;
	scorePos.Y = HEIGHT;
	SetConsoleCursorPosition(console, scorePos);
	cout << "Wynik: " << score;
	scorePos.X = 7;


	generateFruit();




	char user_input = 0;

	while (user_input != 27)
	{
		if (_kbhit())
		{
			user_input = _getch();
		}

		updateDirection(user_input);
		move_snake();
		checkSnakeFruitPosition();
		std::this_thread::sleep_for(0.25s);
	}


	COORD end;
	end.X = 0;
	end.Y = HEIGHT + 1;
	SetConsoleCursorPosition(console, end);
	return 0;
}


//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//// you can loop k higher to see more color choices
//for (int k = 1; k < 255; k++)
//{
//	// pick the colorattribute k you want
//	SetConsoleTextAttribute(hConsole, 1);
//	cout << k << " I want to be nice today!" << endl;
//}