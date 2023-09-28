#include <iostream>
#include <string>
#include <thread>

#include "Map.h"
#include "InputPlayer.h"

//Jeux
int main()
{

	std::string temp;
	constexpr int result = (WIDTH * HEIGHT) / 2;
	bool treasureFound;
	int a = 0;
	random();
	draw_game();

	do
	{
		
		treasureFound = Compar(Coordinate());
		draw_game();
		
		a++;
		if (a >= result)
		{
			std::cout << "Tu as perdu retente ta chance" << std::endl;
			treasureFound = true;
		}
	} while (treasureFound == false);


	std::cout << "appuyez sur entre pour quitter" << std::endl;
	std::cin.ignore();
	return EXIT_SUCCESS;
}