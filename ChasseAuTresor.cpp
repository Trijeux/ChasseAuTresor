#include <iostream>
#include <string>
#include <thread>

#include "Map.h"
#include "InputPlayer.h"

//Jeux
int main()
{

	std::string temp;
	int result = (WIDTH * HEIGHT) / 2;
	bool(treasurefound);
	int a = 0;
	random();
	draw_game();

	do
	{
		treasurefound = compar(coordonnees());
		draw_game();
		a++;
		if (a >= result)
		{
			std::cout << "Tu as perdu retente ta chance" << std::endl;
			treasurefound = true;
		}
	} while (treasurefound == false);


	std::cout << "appuyez sur entre pour quitter" << std::endl;
	std::cin.ignore();
	return EXIT_SUCCESS;
}