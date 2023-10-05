#pragma once

#define WIDTH 5
#define HEIGHT 5

//Map
extern  int Chest[WIDTH * HEIGHT];
extern  int GamePlayer[WIDTH * HEIGHT];

//Object on the map
enum tile
{
    Nothing = 0,
    TreasureChest = 1
};

// Hide a chest in the map
void random();

// Draw the map with the search information
void draw_game();

// Prevents putting 1 from one side to another of the map if the chest is on the edge of the map
bool CheckTresorAtCoodone(int x, int y);