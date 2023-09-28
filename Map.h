#pragma once
#define WIDTH 5
#define HEIGHT 5

//Tableau
extern  int Chest[WIDTH * HEIGHT];
extern  int GamePlayer[WIDTH * HEIGHT];

//Objet sur la map
enum tile
{
    vide = 0,
    coffre_tresor = 1
};

void random();
void draw_game();
bool CheckTresorAtCoodone(int x, int y);