#include<iostream>
#include<cstdlib>

using namespace std;

enum CharacterType {Capital = 1 , Small = 2 , Digit = 3 , Special = 4};

short ValidateNumberInRange(short From, short To)
{
	short Number;
	do
	{
		cout << "ENTER A NUMBER BETWEEN " << From << " & " << To << "\n";
		cin >> Number;

	} while (Number < From || Number > To);

	return Number;
}

short RandomNumber(short From, short To)
{
	short RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

short ReadPositiveNumber(string Message)
{
	short Number;
	do
	{
		cout << Message << "\n";
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

char GenerateRandomCharacter(CharacterType CharacterType)
{
	switch (CharacterType)
	{
	case Capital:
		return RandomNumber(65 , 90);
	case Small:
		return RandomNumber(97 , 123);
	case Digit:
		return RandomNumber(48 , 57);
	case Special:
		return RandomNumber(33 , 47);
	}
}

string GenerateRandomPassword(short PasswordLength , CharacterType CharacterType)
{
	string Password = "";

	for (int i = 0; i < PasswordLength; i++)
	{
		Password += GenerateRandomCharacter(CharacterType);
	}

	return Password;
}

void PrintPasswordCharacterTypeMenu()
{
	cout << "PASSWORD CHARACTERS TYPE\n" <<
		"-----------------------------\n" <<
		"CAPITAL LETTER : 1\n" <<
		"SMALL LETTER : 2\n" <<
		"DIGIT : 3\n" <<
		"SPECIAL CHARACTER : 4\n" <<
		"-----------------------------\n";
}

CharacterType ReadUserChoice()
{
	return (CharacterType)(ValidateNumberInRange(1, 4));
}

bool DoYouWantToContinue()
{
	string Choice;
	do
	{
		cout << "DO YOU WANT TO CONTINUE[Y/N]\n";

		cin >> Choice;

	} while (Choice != "Y" && Choice != "y" && Choice != "N" && Choice != "n");

	if (Choice == "Y" || Choice == "y")
	{
		system("cls");
		return 1;
	}

	else
	{
		cout << "GOOD BYE :)\n";
		return 0;
	}
}

void StartRandomPasswordGenerator()
{
	cout << "WELCOME TO RANDOM PASSWORD GENERATOR\n";

	do
	{

		cout << "------------------------------------\n";

		short Length = ReadPositiveNumber("ENTER PASSWORD LENGTH");
		
		PrintPasswordCharacterTypeMenu();

		CharacterType CharacterType = ReadUserChoice();

		string Password = GenerateRandomPassword(Length, CharacterType);

		cout << "YOUR PASSWORD : " << Password << "\n";

		cout << "------------------------------------\n";

	} while (DoYouWantToContinue());
}

int main()
{
	srand((unsigned)time(NULL));

	StartRandomPasswordGenerator();

	return 0;
}