#include <iostream>
#include <string>
#include <thread>
#include "Map.h"
#include "InputPlayer.h"

//Jeux
int main()
{
	std::cout << "Bonjour, bienvenu dans la chasse au tresor" << std::endl;
	std::cout << "votre but est de trouver le tresor en choisisant la ligne et la colonne" << std::endl;
	std::cout << "Quand vous avez un 0 c'est que le coffre n'ai pas a cote (horizontal et vertical)" << std::endl;
	std::cout << "et si il y a un 1 c'est qui est a cote" << std::endl;
	std::string temp;
	constexpr int tries = (WIDTH * HEIGHT) / 2;
	bool treasureFound;
	int a = 0;
	random();
	draw_game();

	do
	{
		std::cout << "il te reste " << tries - a << " vie" << std::endl;
		treasureFound = Compar(Coordinate());

		if (!treasureFound)
		{
			system("cls");
		}
		

		draw_game();

		a++;
		if (a >= tries)
		{
			std::cout << "Tu as perdu retente ta chance" << std::endl;
			treasureFound = true;
		}
	} while (treasureFound == false);


	std::cout << "appuyez sur entre pour quitter" << std::endl;
	std::cin.ignore();
	return EXIT_SUCCESS;
}