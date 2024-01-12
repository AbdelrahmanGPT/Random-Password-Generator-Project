#include<iostream>
#include<cstdlib>
#include"ABODAstd.h"

using namespace std;

enum CharacterType {Capital = 1 , Small = 2 , Digit = 3 , Special = 4};

char GenerateRandomCharacter(CharacterType CharacterType)
{
	switch (CharacterType)
	{
	case Capital:
		return RandomNumber(65 , 90);
	case Small:
		return RandomNumber(97 , 122);
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