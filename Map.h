#pragma once
#define WIDTH 5
#define HEIGHT 5

//Tableau
extern  int coffre[WIDTH * HEIGHT];
extern  int affichage_plateau[WIDTH * HEIGHT];

//Objet sur la map
enum tile
{
    vide = 0,
    coffre_tresor = 1
};

void random();
void draw_game();
bool check_tresor_at_coodone(int x, int y);