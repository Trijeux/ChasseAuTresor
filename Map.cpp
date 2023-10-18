#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Map.h"

//Map 
int Chest[WIDTH * HEIGHT];
int GamePlayer[WIDTH * HEIGHT];


void random()
{
	//while (true)
	//{
		// Creates a random seed
		srand(time(0));
		// Create a random number of the size of the map
		int idxRandom = rand() % (WIDTH * HEIGHT);
		// Place the chest on the map
		Chest[idxRandom] = 1;
		//std::cout << idxRandom << std::endl;
	//}
}

void draw_game()
{
	// Draw line by line
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int column = 0; column < WIDTH; column++)
		{
			int caseState = GamePlayer[row * WIDTH + column];
			if (caseState == 0)
			{
				std::cout << '-';
			}
			// Check if there is a safe nearby
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