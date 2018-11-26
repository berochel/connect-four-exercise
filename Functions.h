// Jaros³aw Zabuski, gr. 3, 1 sem Informatyka, EITI
// Plik nag³ówkowy zawieraj¹cy wstêpne deklaracje funkcji u¿ytych w Functions.c do realizacji gry "Connect Four".
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "Matrix.h"
int sprawdzCzyCztery(int , int , struct Mapa *, int , int , int);
void sprawdzCzyPoprawneXY(int , int , int , int , struct Mapa *,int);
void gra(int ,int , struct Mapa *);
void startGra();
void sprawdzKtoWygral(int , int, int, struct Mapa *);
int czyWszystkieRozneOdZera(int , int , struct Mapa *);
#endif // FUNCTIONS_H_INCLUDED
