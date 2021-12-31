#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(int argc, const char* argv[]) {

	srand(time(NULL));

	int iFailed = 0;

	string sWord[] = { "DOG", "BIRD", "SHARK", "CAT", "ZEBRA", "BURRO", "CROCODILE", "SNAKE", "FISH", "MONKEY" };
	string sRandom_Word = sWord[rand() % 10];
	string sRandom_FreeSpace;

	for (int i = 0; i < sRandom_Word.length(); i++)
	{
		sRandom_FreeSpace.append("*");	//I tried to use _ instead of - but you can't see the free spaces even if you put a space between the latters

	}

	cout << "You are looking for fallowing word: " << sRandom_FreeSpace << endl;

	while (sRandom_FreeSpace.find("*") != string::npos && iFailed < 10)
	{

		char cInput;
		cin >> cInput;

		if (sRandom_Word.find(cInput) == string::npos)
		{

			iFailed++;

		}
		else
		{

			for (int i = 0; i < sRandom_Word.length(); i++)
			{
				if (sRandom_Word[i] == cInput)
				{

					sRandom_FreeSpace[i] = cInput;

				}

			}


		}
		cout << "You are looking for fallowing word: " << sRandom_FreeSpace << endl;
		cout << "You still have " << (10 - iFailed) << " tries" << endl;

	}

	if (sRandom_FreeSpace.find("*") == string::npos)
	{

		cout << endl << "Congratulations! You won! |o|";

	}
	else
	{

		cout << "Oh... You lost. More lucky next time...";

	}



	cout << endl << endl << endl;
	cout << "Program ends here" << endl << endl;

	return 0;
}