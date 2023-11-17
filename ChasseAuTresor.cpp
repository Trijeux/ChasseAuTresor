#include "Game.h"

void main()
{
	bool gameover;

	do
	{
		Game game;

		gameover = game.GameLoop();
	}
	while (!gameover);
}