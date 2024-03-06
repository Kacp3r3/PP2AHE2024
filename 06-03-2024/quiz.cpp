#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	fstream quiz;
	quiz.open("quiz.txt", std::ios::in);

	if (quiz.is_open())
	{
		int score = 0;
		int user_answer;
		std::string dummy;
		while(!quiz.eof())
		{
			for (int i = 0; i < 5; ++i)
			{
				std::string line;
				std::getline(quiz, line);
				cout << line << '\n';
			}

			int good_answer;
			quiz >> good_answer;
			getline(quiz, dummy);

			cout << "Twoja odpowiedz(1-4): ";
			cin >> user_answer;


			if (user_answer == good_answer)
			{
				score += 1;
			}
		}

		cout << "Twoj wynik: " << score << '\n';
	}
	else
	{
		cout << "Nie znaleziono pliku z pytaniami!\n";
	}

	return 0;
}