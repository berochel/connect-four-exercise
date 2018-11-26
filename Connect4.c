// Jarosław Zabuski, gr. 3, 1 sem Informatyka, EITI
// Program inicjalizujący grę znaną z angielskiego jako "Connect Four" w konsoli
#include <stdio.h>
#include "Matrix.h"
#include "Interface.h"
#include "Functions.h"

int main(void)
{
clrScr();
printf("%c[%dm",0x1B,35); puts("Dzien dobry, czas zagrac w \"Polacz Cztery\"!"); printf("%c[%dm",0x1B,0); //miejsce na powitanie u¿ytkownika i zapoznanie go z dzialaniem programu
puts("W Polacz Cztery gra sie w dwie osoby. Macie przed soba plansze o dowolnym rozmiarze, na ktorym musicie zaznaczyc takie miejsca, by mozna bylo cztery z nich polaczyc pojedyncza linia. Kto pierwszy to zrobi, wygrywa!");
puts("W takim razie: zaczynajmy!");
startGra();
clrScr();
printf("%c[%dm",0x1B,35); puts("Dzieki wielkie za gre! Do zobaczenia!"); printf("%c[%dm",0x1B,0); return 0;
}
