#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Map.h"

int Chest[WIDTH * HEIGHT];
int GamePlayer[WIDTH * HEIGHT];

//random
void random()
{
	srand(time(0));
	int idxRandom = rand() % (WIDTH * HEIGHT);
	Chest[idxRandom] = 1;
	/*while (true)
	{
		srand(time(0));
		int idxRandom = rand() % (WIDTH * HEIGHT);
		Chest[idxRandom] = 1;
		std::cout << idxRandom << std::endl;
	}*/
}

bool CheckTresorAtCoodone(int x, int y)
{
	if (x < 0 || x >= HEIGHT)
	{
		return 0;
	}
	if (y < 0 || y >= HEIGHT)
	{
		return 0;
	}
	return Chest[(x)*HEIGHT + (y)];
}

//Dessin
void draw_game()
{
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int column = 0; column < WIDTH; column++)
		{
			int caseState = GamePlayer[row * WIDTH + column];
			if (caseState == 0)
			{
				std::cout << '-';
			}
			else if (caseState == 1)
			{
				int adjTresor = 0;
				if (CheckTresorAtCoodone(row, column - 1))
				{
					adjTresor++;
				}
				if (CheckTresorAtCoodone(row, column + 1))
				{
					adjTresor++;
				}
				if (CheckTresorAtCoodone(row - 1, column))
				{
					adjTresor++;
				}
				if (CheckTresorAtCoodone(row + 1, column))
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