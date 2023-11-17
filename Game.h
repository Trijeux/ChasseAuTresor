#pragma once
#include <string>

#define WIDTH 5
#define HEIGHT 5

enum Tile
{
	kNothing = 0,
	kTreasureChest = 1
};

extern  int chest[WIDTH * HEIGHT];
extern  int game_player[WIDTH * HEIGHT];

class Game
{
public:
	Game();
	~Game();

	bool GameLoop();
private:

	void random();
	void draw_game();
	bool CheckTresorAtCoodone(int x, int y);
	int Coordinate();
	bool Compar(int indexresult);
	int Dificulty();
	bool GameOver();


	int dificulty_;
	int tries_max_;
	bool treasure_found_ = false;
	int tries_ = 0;
	int chest_[WIDTH * HEIGHT]{ 0 };
	int game_player_[WIDTH * HEIGHT]{ 0 };
	bool valid_input_ = false;
	bool valid_number_ = true;
	int dificulty_number_;
	std::string dificulty_choose_;
	//char dificulty_choose_;
	bool input_false_ = true;
};

