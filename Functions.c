// Jaros³aw Zabuski, gr. 3, 1 sem Informatyka, EITI
// Program realizuj¹cy grê znan¹ z angielskiego jako "Connect Four" w konsoli za pomoc¹ funkcji, których definicje znajduj¹ siê poni¿ej.
#include <stdio.h>
#include "Matrix.h"
#include "Interface.h"
#include "Functions.h"
int sprawdzCzyCztery(int a, int b, struct Mapa *mat, int x, int y, int stalaGracza) //funkcja boolowska, sprawdzaj¹ca czy dana kropka jest po³¹czona z trzema innymi w prostej linii
{
    if(x+3 <= b && mat[y].x[x+1]==stalaGracza && mat[y].x[x+2]==stalaGracza && mat[y].x[x+3]==stalaGracza) {return 1;}
    else if(y+3 <= a && x+3 <= b && mat[y+1].x[x+1]==stalaGracza && mat[y+2].x[x+2]==stalaGracza && mat[y+3].x[x+3]==stalaGracza) {return 1;}
    else if(y+3 <= a && mat[y+1].x[x]==stalaGracza && mat[y+2].x[x]==stalaGracza && mat[y+3].x[x]==stalaGracza) {return 1;}
    else if(y+3 <= a && x-3 >= 0 && mat[y+1].x[x-1]==stalaGracza && mat[y+2].x[x-2]==stalaGracza && mat[y+3].x[x-3]==stalaGracza) {return 1;}
    else if(x-3 >= 0 && mat[y].x[x-1]==stalaGracza && mat[y].x[x-2]==stalaGracza && mat[y].x[x-3]==stalaGracza) {return 1;}
    else if(y-3 >= 0 && x-3 >= 0 && mat[y-1].x[x-1]==stalaGracza && mat[y-2].x[x-2]==stalaGracza && mat[y-3].x[x-3]==stalaGracza) {return 1;}
    else if(y-3 >= 0 && mat[y-1].x[x]==stalaGracza && mat[y-2].x[x]==stalaGracza && mat[y-3].x[x]==stalaGracza) {return 1;}
    else if(y-3 >= 0 && x+3 <= b && mat[y-1].x[x+1]==stalaGracza && mat[y-2].x[x+2]==stalaGracza && mat[y-3].x[x+3]==stalaGracza) {return 1;}
    else return 0;
}
void gra(int a,int b, struct Mapa *mat); // wstêpna definicja funkcji gra() w której odbywa sie ca³a gra, w celu umieszczenia jej w funkcji startGra()
void startGra() //funkcja inicjalizuj¹ca now¹ grê, pozwalaj¹ca na wybranie rozmiaru planszy, na której odbywa siê gra, lub zmianê go podczas kolejnego podejœcia w grze
{
    int x,y;
    puts("Podaj rozmiar planszy X x Y (od 4 do 60 w obu osiach, np. \"12 15\"):");
    while(scanf("%d %d",&x,&y) != 2)
    {
        puts("Prosze podac rozmiar planszy jeszcze raz:");
        czyscBledneZnaki();
    }
    while(x > 60 || x < 4 || y > 60 || x < 4)
{
    puts("Prosze podac rozmiar planszy jeszcze raz:");
    while(scanf("%d %d",&x,&y) != 2)
    {
        puts("Prosze podac rozmiar planszy jeszcze raz:");
        czyscBledneZnaki();
    }
}
    gra(y,x,mat);
}
int czyWszystkieRozneOdZera(int a, int b, struct Mapa *mat)
{
    for(int i=0;i<a;++i)
    {
        for(int j=0;j<b;++j)
        {
            if(mat[i].x[j]==0)return 0;
        }
    }
    return 1;
}
void sprawdzKtoWygral(int KtoWygral, int a,int b, struct Mapa *mat)
{
char czyDalej; // zmienna przechowujaca dane o tym, czy gracz chce zagrac ponownie czy wyjsc z programu
wypisz(a,b,mat);
if(KtoWygral==0){
            clrScr();
            printf("\nRemis! Czy chcecie sprobowac ponownie? (T jezeli tak, N jezeli nie):");
            czyscBledneZnaki(); scanf(" %c",&czyDalej);
            if(czyDalej == 'T')
            {
                    wyzeruj(a,b,mat); startGra();
            }
    }
    else {  clrScr();
            printf("%c[%dm",0x1B,35); printf("\nGratulacje, Graczu %d! Wygrales!",KtoWygral); printf("%c[%dm",0x1B,0);
            printf("\n\nCzy chcecie sprobowac ponownie? (T jezeli tak, N jezeli nie):");
            czyscBledneZnaki(); scanf(" %c",&czyDalej);
            if(czyDalej == 'T')
            {
                wyzeruj(a,b,mat); startGra();
            }
    }
}
void gra(int a,int b, struct Mapa *mat) //glowne cialo gry, skladajaca sie z petli trwajacej do zapelnienia ca³ej matrycy liczbami (w wypadku remisu) lub wygranej jednego z graczy
{
    wyzeruj(a,b,mat);
    int KtoWygral = 0; //zmienna ktora przechowuje wiadomosc o tym, ktory z graczy wygral
    int x,y; //zmienne utrzymujace w sobie wspo³rzêdne punktu, który wybiera gracz do zakreœlenia
    do
        {
            clrScr();
            puts("Czas na gracza numer jeden! Wybierz miejsce, ktore chcesz zamalowac, piszac w ktorej jest kolumnie i w ktorym rzedzie (np. \"1 1\"):");
            wypisz(a,b,mat);
            while(scanf("%d %d",&x,&y) != 2)
            {
            puts("Nie ma takiego znaku! Wybierz odpowiednie miejsce na planszy:");
            czyscBledneZnaki();
            }
            while (y-1 >= a || y-1 < 0 || x-1 >= b || x-1 < 0 || mat[y-1].x[x-1]!=0)
            {
                if (y-1 >= a || y-1 < 0 || x-1 >= b || x-1 < 0) {puts("Nie ma takiego miejsca na planszy. Wybierz miejsce ponownie:"); czyscBledneZnaki(); scanf("%d %d", &x, &y);}
                else if(mat[y-1].x[x-1]!=1) {puts("Gracz 2 juz zaznaczyl to miejsce! Wybierz inne miejsce na planszy."); czyscBledneZnaki(); scanf("%d %d", &x, &y);}
                else if(mat[y-1].x[x-1]==1) {puts("Juz zaznaczyles to miejsce! Wybierz inne miejsce na planszy."); czyscBledneZnaki(); scanf("%d %d", &x, &y);}
            }
            mat[y-1].x[x-1]=1;
            if(sprawdzCzyCztery(a,b,mat,x-1,y-1,1)) {KtoWygral =1; break;}
            clrScr();
            puts("Czas na gracza numer dwa! Wybierz miejsce, ktore chcesz zamalowac, piszac w ktorej jest kolumnie i w ktorym rzedzie (np. \"1 1\"):");
            wypisz(a,b,mat);
            while(scanf("%d %d",&x,&y) != 2)
            {
            puts("Nie ma takiego znaku! Wybierz odpowiednie miejsce na planszy:");
            czyscBledneZnaki();
            }
            while (y-1 >= a || y-1 < 0 || x-1 >= b || x-1 < 0 || mat[y-1].x[x-1]!=0)
            {
                if (y-1 >= a || y-1 < 0 || x-1 >= b || x-1 < 0) {puts("Nie ma takiego miejsca na planszy. Wybierz miejsce ponownie:"); czyscBledneZnaki(); scanf("%d %d", &x, &y);}
                else if(mat[y-1].x[x-1]!=2) {puts("Gracz 1 juz zaznaczyl to miejsce! Wybierz inne miejsce na planszy."); czyscBledneZnaki(); scanf("%d %d", &x, &y);}
                else if(mat[y-1].x[x-1]==2) {puts("Juz zaznaczyles to miejsce! Wybierz inne miejsce na planszy."); czyscBledneZnaki(); scanf("%d %d", &x, &y);}
            }
            mat[y-1].x[x-1]=2;
            if(sprawdzCzyCztery(a,b,mat,x-1,y-1,2)){KtoWygral =2; break;}
        } while(!czyWszystkieRozneOdZera(a,b,mat));
     sprawdzKtoWygral(KtoWygral,a,b,mat);
}
