#include <algorithm>
#include <iostream>
#include <string>
#include "Map.h"
#include "InputPlayer.h"


int Coordinate()
{
#pragma region Variable Local
	bool validInput = true;
	bool validNumber = false;

	//Input Player
	std::string inputString;

	//Row x
	unsigned int x = 0;

	//Column y
	unsigned int y = 0;
#pragma endregion

#pragma region Input Row Column
	//Input Row
	do
	{
		do
		{
			validInput = true;
			validNumber = false;
			std::cout << "entre ligne (un numero) entre " << 1 << "-" << WIDTH << std::endl;
			std::getline(std::cin, inputString);

			// Check if it's a number or not
			if (inputString.length() == 0 || !std::all_of(inputString.begin(), inputString.end(), ::isdigit))
			{
				std::cout << inputString << " n'est pas un nombre" << std::endl;
				validInput = false;
			}
			if (validInput)
			{
				// Checks if number is between 1 and array size
				x = std::stoi(inputString);
				if (x > WIDTH || x  < 1)
				{
					validNumber = true;
					std::cout << "Ce n'est pas un chiffre entre 1-" << WIDTH << std::endl;
				}
			}
		} while (validNumber);

	} while (!validInput);

	//Input Column
	do
	{
		do
		{
			validInput = true;
			validNumber = false;
			std::cout << "entre colonne (un numero) entre " << 1 << "-" << HEIGHT << std::endl;
			std::getline(std::cin, inputString);

			// Check if it's a number or not
			if (inputString.length() == 0 || !std::all_of(inputString.begin(), inputString.end(), ::isdigit))
			{
				std::cout << inputString << " n'est pas un nombre" << std::endl;
				validInput = false;
			}

			if (validInput)
			{
				// Checks if number is between 1 and array size
				y = std::stoi(inputString);
				if (y > WIDTH || y < 1)
				{
					validNumber = true;
					std::cout << "Ce n'est pas un chiffre entre 1-" << WIDTH << std::endl;
				}
			}
		}
		while (validNumber);
	} while (!validInput);

	//Return coordinates
	return (x - 1) * HEIGHT + (y - 1);
#pragma endregion
}


bool Compar(int indexresult)
{
	// Check if at the coordinate there is the treasure chest
	if (Chest[indexresult] == tile::TreasureChest)
	{
		system("cls");
		GamePlayer[indexresult] = 2;
		std::cout << "        ..::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::..        " << std::endl;
		std::cout << "    .-#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#=.    " << std::endl;
		std::cout << "  .+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+.  " << std::endl;
		std::cout << ".:%@@@@+--#@@@========================================================================@@@#--+@@@@%:." << std::endl;
		std::cout << ".@@@@+:::-#@@@========================================================================@@@#-:::+@@@@:" << std::endl;
		std::cout << "*@@@+::::-#@@@========================================================================@@@#-::::+@@@*" << std::endl;
		std::cout << "@@@%=::::-#@@@========================================================================@@@#-::::-%@@@" << std::endl;
		std::cout << "@@@#-::::-#@@@################+==========*################*==========+################@@@#-::::-#@@@" << std::endl;
		std::cout << "@@@#-::::-#@@@@@@@@@@@@@@@@@@@@*========@@@@@@@@@@@@@@@@@@@@========+@@@@@@@@@@@@@@@@@@@@#-::::-#@@@" << std::endl;
		std::cout << "@@@#-::::-#@@@%###############*==========##################+=========+###############%@@@#-::::-#@@@" << std::endl;
		std::cout << "@@@#-::::-#@@@========================================================================@@@#-::::-#@@@" << std::endl;
		std::cout << "@@@#-::::-#@@@========================================================================@@@#-::::-#@@@" << std::endl;
		std::cout << "@@@#-::::-#@@@========================================================================@@@#-::::-#@@@" << std::endl;
		std::cout << "@@@#-::::-#@@@========================================================================@@@#-::::-#@@@" << std::endl;
		std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
		std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
		std::cout << "@@@%====================================#@@@+==========+@@@#====================================%@@@" << std::endl;
		std::cout << "@@@#-::::::::::::::::::::::::::::::::::-*@@@=::::::::::=@@@*-::::::::::::::::::::::::::::::::::-#@@@" << std::endl;
		std::cout << "@@@#-::::::::::::::::::::::::::::::::::-*@@@=::::::::::=@@@*-::::::::::::::::::::::::::::::::::-#@@@" << std::endl;
		std::cout << "@@@#-:::::::::-%%%%%%%%%%%%%%%%%%%%%%%%%@@@@=:::-##=:::=@@@@%%%%%%%%%%%%%%%%%%%%%%%%%-:::::::::-#@@@" << std::endl;
		std::cout << "@@@#-:::::::::#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=::-%@@%-::=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%:::::::::-#@@@" << std::endl;
		std::cout << "@@@#-::::::::#@@@%+=====================*@@@=:::-==-:::=@@@*=====================+%@@@#::::::::-#@@@" << std::endl;
		std::cout << "@@@#-::::=@@@@@@@=======================+@@@@=::::::::=@@@@+=======================@@@@@@@=::::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@@@==========================+@@@@@@-::-%@@@@%+==========================@@@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+=============================#@@@@@@@@@@@@%=============================+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+================================#@@@@@@#================================+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@@@@@@@@@@@@@=====#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%===========%@@@@@@@@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@@@@@@@@@@@@#=====+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*===========*@@@@@@@@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+========================================================================+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+========================================================================+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+========================================================================+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+========================================================================+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+======+****************========+*************========+**************====+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+=====#@@@@@@@@@@@@@@@@@+=======@@@@@@@@@@@@@@#======+@@@@@@@@@@@@@@@%===+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+======*###############*========+*###########*========+*############*+===+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@+========================================================================+@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::*@@@%*======================================================================+#@@@*-:::-#@@@" << std::endl;
		std::cout << "@@@#-::::+@@@@@@#==================================================================#@@@@@@+::::-#@@@" << std::endl;
		std::cout << "@@@#-:::::-=+@@@@%================================================================#@@@@+=-:::::-#@@@" << std::endl;
		std::cout << "@@@#-::::::::-%@@@@@@@@@@@@@@@@@@@@@@@@@@@#=====*@@*=====#@@@@@@@@@@@@@@@@@@@@@@@@@@@@-::::::::-#@@@" << std::endl;
		std::cout << "@@@#-:::::::::+@@@@@@@@@@@@@@@@@@@@@@@@@@@%=:::-*@@*-:::-%@@@@@@@@@@@@@@@@@@@@@@@@@@@+:::::::::-#@@@" << std::endl;
		std::cout << "@@@#-::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::-#@@@" << std::endl;
		std::cout << "@@@#-::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::-#@@@" << std::endl;
		std::cout << "@@@#-::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::-#@@@" << std::endl;
		std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
		std::cout << "%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%" << std::endl;
		std::cout << "Tu as trouve le Tresor tu as gagne" << std::endl;
		return true;
	}
	GamePlayer[indexresult] = 1;
	std::cout << "Rien trouve" << std::endl;
	return false;

}


int Dificulty()
{
#pragma region Variable Local
	int dificulty;
	int dificultyNumber;
	std::string dificultychoose;
	bool inputFalse = true;
	bool validInput = true;
#pragma endregion

	std::cout << "Choisi ta difficulte pour le jeu : (1)facile 15 essai, (2)normal 10 essai, (3)Difficile 5 essai" << std::endl;

#pragma region Input Difficulty
	// Check if it's a number or not
	do
	{
		do
		{
			std::getline(std::cin, dificultychoose);

			validInput = true;

			if (dificultychoose.length() == 0 || !std::all_of(dificultychoose.begin(), dificultychoose.end(), ::isdigit))
			{
				system("cls");
				std::cout << dificultychoose << " n'est pas un chiffre! entre : (1)facile 15 essai, (2)normal 10 essai, (3)Difficile 5 essai" << std::endl;
				validInput = false;
			}

			if (validInput)
			{
				dificultyNumber = std::stoi(dificultychoose);
			}
		}
		while (!validInput);

		//Checks if the number is between 1 and 3
		if (dificultyNumber < 1 || dificultyNumber > 3)
		{
			system("cls");
			std::cout << "entrer invalide entre : (1)facile 15 essai, (2)normal 10 essai, (3)Difficile 5 essai" << std::endl;
		}
		else
		{
			inputFalse = false;
		}
	} while (inputFalse);
#pragma endregion

	// Set the number of tests according to the chosen difficulty and print the choice
	if (dificultyNumber == 1) dificulty = 15;
	if (dificultyNumber == 2) dificulty = 10;
	if (dificultyNumber == 3) dificulty = 5;
	system("cls");
	if (dificultyNumber == 1) std::cout << "Mode Facile" << std::endl;
	if (dificultyNumber == 2) std::cout << "Mode Normal" << std::endl;
	if (dificultyNumber == 3) std::cout << "Mode Difficile" << std::endl;

	return dificulty;
}