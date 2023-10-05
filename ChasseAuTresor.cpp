#include <iostream>
#include <thread>
#include "Map.h"
#include "InputPlayer.h"

//Jeux
int main()
{
#pragma region Variable Local
	bool treasureFound = false;
	int tries = 0;
#pragma endregion

#pragma region Start
	// Start of the game
	std::cout << "Bonjour, bienvenu dans la chasse au tresor" << std::endl;
	std::cout << "votre but est de trouver le tresor en choisissant la ligne et la colonne" << std::endl;

	// Put the return in the variable
	int dificulty = Dificulty();
	int triesMax = dificulty;

	//Rule
	std::cout << "Quand vous avez un 0 c'est que le coffre n'ai pas a cote (horizontal et vertical)" << std::endl;
	std::cout << "et si il y a un 1 c'est qui est a cote" << std::endl;

	random();
	draw_game();
#pragma endregion

#pragma region Game
	do
	{
		// Give the number tries to the player
		std::cout << "il te reste " << triesMax - tries << " vie" << std::endl;

		// Give true or false to the variable
		treasureFound = Compar(Coordinate());

		// Clean the console if the treasure was not found
		if (!treasureFound)
		{
			system("cls");
		}

		draw_game();

		// +1 to the number of turns passed
		tries++;

		// If the number of rounds has passed, the player has lost.
		if (tries >= triesMax)
		{
			std::cout << "Tu as perdu retente ta chance" << std::endl;
		}
	} while (treasureFound == false && tries < triesMax);
#pragma endregion

#pragma region Release
	// For the Release
	std::cout << "appuyez sur entrer pour quitter" << std::endl;
	std::cin.ignore();
#pragma endregion

	return EXIT_SUCCESS;
}