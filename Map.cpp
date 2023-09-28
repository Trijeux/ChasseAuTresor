#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Map.h"

int coffre[WIDTH * HEIGHT];
int affichage_plateau[WIDTH * HEIGHT];

//random
void random()
{
	srand(time(0));
	int idxRandom = rand() % WIDTH * HEIGHT;
	coffre[idxRandom] = 1;
	/*while (true)
	{
		srand(time(0));
		int idxRandom = rand() % (WIDTH * HEIGHT);
		coffre[idxRandom] = 1;
		std::cout << idxRandom << std::endl;
	}*/
}

bool check_tresor_at_coodone(int x, int y)
{
	if (x < 0 || x >= HEIGHT)
	{
		return 0;
	}
	if (y < 0 || y >= HEIGHT)
	{
		return 0;
	}
	return coffre[(x)*HEIGHT + (y)];
}

//Dessin
void draw_game()
{
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int column = 0; column < WIDTH; column++)
		{
			int case_state = affichage_plateau[row * WIDTH + column];
			if (case_state == 1)
			{
				std::cout << '-';
			}
			else if (case_state == 0)
			{
				int adjTresor = 0;
				if (check_tresor_at_coodone(row, column - 1))
				{
					adjTresor++;
				}
				if (check_tresor_at_coodone(row, column + 1))
				{
					adjTresor++;
				}
				if (check_tresor_at_coodone(row - 1, column))
				{
					adjTresor++;
				}
				if (check_tresor_at_coodone(row + 1, column))
				{
					adjTresor++;
				}
				std::cout << adjTresor;
			}
			else
			{
				std::cout << 'X';
			}
		}
		std::cout << '\n';
	}
}