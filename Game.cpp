#include "Game.h"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include "InputPlayer.h"
#include "Map.h"

Game::Game()
{
	// Start of the game
	std::cout << "Bonjour, bienvenu dans la chasse au tresor" << std::endl;
	std::cout << "votre but est de trouver le tresor en choisissant la ligne et la colonne" << std::endl;

	// Put the return in the variable
	dificulty_ = Dificulty();
	tries_max_ = dificulty_;

	//Rule
	std::cout << "Quand vous avez un 0 c'est que le coffre n'ai pas a cote (horizontal et vertical)" << std::endl;
	std::cout << "et si il y a un 1 c'est qui est a cote" << std::endl;

	random();
	draw_game();
}

Game::~Game()
{
	system("cls");
	//std::cout << "Game Over" << std::endl;
}

bool Game::GameLoop()
{
	do
	{
		// Give the number tries_ to the player
		std::cout << "il te reste " << tries_max_ - tries_ << " vie" << std::endl;

		// Give true or false to the variable
		treasure_found_ = Compar(Coordinate());

		// Clean the console if the treasure was not found
		if (!treasure_found_)
		{
			system("cls");
		}

		draw_game();

		// +1 to the number of turns passed
		tries_++;

		// If the number of rounds has passed, the player has lost.
		if (tries_ >= tries_max_)
		{
			std::cout << "Tu as perdu retente ta chance" << std::endl;
		}

	} while (treasure_found_ == false && tries_ < tries_max_);

	bool gameover = GameOver();

	return gameover;
}

void Game::random()
{
	//while (true)
	//{
		// Creates a random seed
	srand(time(0));
	// Create a random number of the size of the map
	int idxRandom = rand() % (WIDTH * HEIGHT);
	// Place the chest on the map
	chest_[idxRandom] = 1;
	//std::cout << idxRandom << std::endl;
//}
}

void Game::draw_game()
{
	// Draw line by line
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int column = 0; column < WIDTH; column++)
		{
			int case_state = game_player_[row * WIDTH + column];
			if (case_state == 0)
			{
				std::cout << '-';
			}
			// Check if there is a safe nearby
			else if (case_state == 1)
			{
				int adj_tresor = 0;
				if (CheckTresorAtCoodone(row, column - 1))
				{
					adj_tresor++;
				}
				if (CheckTresorAtCoodone(row, column + 1))
				{
					adj_tresor++;
				}
				if (CheckTresorAtCoodone(row - 1, column))
				{
					adj_tresor++;
				}
				if (CheckTresorAtCoodone(row + 1, column))
				{
					adj_tresor++;
				}
				std::cout << adj_tresor;
			}
			else
			{
				std::cout << 'X';
			}
		}
		std::cout << '\n';
	}
}

bool Game::CheckTresorAtCoodone(int x, int y)
{
	if (x < 0 || x >= HEIGHT)
	{
		return 0;
	}
	if (y < 0 || y >= HEIGHT)
	{
		return 0;
	}
	return chest_[(x)*HEIGHT + (y)];
}

int Game::Coordinate()
{
#pragma region Variable Local
	//Input Player
	std::string input_string;

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
			valid_input_ = true;
			valid_number_ = false;
			std::cout << "entre ligne (un numero) entre " << 1 << "-" << WIDTH << std::endl;
			std::getline(std::cin, input_string);

			// Check if it's a number or not
			if (input_string.length() == 0 || !std::all_of(input_string.begin(), input_string.end(), ::isdigit))
			{
				std::cout << input_string << " n'est pas un nombre" << std::endl;
				valid_input_ = false;
			}
			if (valid_input_)
			{
				// Checks if number is between 1 and array size
				x = std::stoi(input_string);
				if (x > WIDTH || x < 1)
				{
					valid_number_ = true;
					std::cout << "Ce n'est pas un chiffre entre 1-" << WIDTH << std::endl;
				}
			}
		} while (valid_number_);

	} while (!valid_input_);

	//Input Column
	do
	{
		do
		{
			valid_input_ = true;
			valid_number_ = false;
			std::cout << "entre colonne (un numero) entre " << 1 << "-" << HEIGHT << std::endl;
			std::getline(std::cin, input_string);

			// Check if it's a number or not
			if (input_string.length() == 0 || !std::all_of(input_string.begin(), input_string.end(), ::isdigit))
			{
				std::cout << input_string << " n'est pas un nombre" << std::endl;
				valid_input_ = false;
			}

			if (valid_input_)
			{
				// Checks if number is between 1 and array size
				y = std::stoi(input_string);
				if (y > WIDTH || y < 1)
				{
					valid_number_ = true;
					std::cout << "Ce n'est pas un chiffre entre 1-" << WIDTH << std::endl;
				}
			}
		} while (valid_number_);
	} while (!valid_input_);

	//Return coordinates
	return (x - 1) * HEIGHT + (y - 1);
#pragma endregion
}

bool Game::Compar(int indexresult)
{
	// Check if at the coordinate there is the treasure chest
	if (chest_[indexresult] == Tile::kTreasureChest)
	{
		system("cls");
		game_player_[indexresult] = 2;
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
	game_player_[indexresult] = 1;
	std::cout << "Rien trouve" << std::endl;
	return false;

}

int Game::Dificulty()
{
	std::cout << "Choisi ta difficulte pour le jeu : (1)facile 15 essai, (2)normal 10 essai, (3)Difficile 5 essai" << std::endl;

#pragma region Input Difficulty
	// Check if it's a number or not
	do
	{
	do
	{
		std::getline(std::cin, dificulty_choose_);

		valid_input_ = true;

		if (dificulty_choose_.length() == 0 || !std::all_of(dificulty_choose_.begin(), dificulty_choose_.end(), ::isdigit))
		{
			system("cls");
			std::cout << dificulty_choose_ << " n'est pas un chiffre! entre : (1)facile 15 essai, (2)normal 10 essai, (3)Difficile 5 essai" << std::endl;
			valid_input_ = false;
		}

		if (valid_input_)
		{
			dificulty_number_ = std::stoi(dificulty_choose_);
		}

	} while (!valid_input_);

	//Checks if the number is between 1 and 3
	if (dificulty_number_ < 1 || dificulty_number_ > 3)
	{
		system("cls");
		std::cout << "entrer invalide entre : (1)facile 15 essai, (2)normal 10 essai, (3)Difficile 5 essai" << std::endl;
	}
	else
	{
		input_false_ = false;
	}
} while (input_false_);
#pragma endregion

	// Set the number of tests according to the chosen difficulty and print the choice
	if (dificulty_number_ == 1) dificulty_ = 15;
	if (dificulty_number_ == 2) dificulty_ = 10;
	if (dificulty_number_ == 3) dificulty_ = 5;
	system("cls");
	if (dificulty_number_ == 1) std::cout << "Mode Facile" << std::endl;
	if (dificulty_number_ == 2) std::cout << "Mode Normal" << std::endl;
	if (dificulty_number_ == 3) std::cout << "Mode Difficile" << std::endl;

	return dificulty_;
}

bool Game::GameOver()
{
	bool gameover = false;
	std::string inputplayer;
	int continuegame;
	bool valideinput;

	

	std::cout << "Veux tu rejouer ? (1)oui / (2)non" << std::endl;

	do
	{
		std::getline(std::cin, inputplayer);

		valideinput = true;

		if (inputplayer.length() == 0 || !std::all_of(inputplayer.begin(), inputplayer.end(), ::isdigit))
		{
			system("cls");
			std::cout << inputplayer << " n'est pas y ou n" << std::endl;
			valideinput = false;
		}

		if (valideinput)
		{
			continuegame = std::stoi(inputplayer);
		}

	} while (!valideinput);

	if (continuegame == 1)
	{
		gameover = false;
	}
	else if (continuegame == 2)
	{
		gameover = true;
	}
	else
	{
		std::cout << "Ce n'est pas y ou n" << std::endl;
	}

	return gameover;
}
