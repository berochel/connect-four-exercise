// Jaros³aw Zabuski, gr. 3, 1 sem Informatyka, EITI
// Program realizuj¹cy grê znan¹ z angielskiego jako "Connect Four" w konsoli za pomoc¹ funkcji, których definicje znajduj¹ siê poni¿ej.
#include <stdio.h>
#include "Matrix.h"
#include "Interface.h"
#include "Functions.h"
void czyscBledneZnaki( void ) {
    char c;
    do
        c = getchar();
    while ( c != '\n' && c != EOF );
}
void clrScr(){
  printf("\033[2J"); // Czyści ekran
  printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu
}
void wyzeruj(int b, int c, struct Mapa *mat) //definicja funkcji zeruj¹cej matrycê po zakoñczonej grze.
{
    for(int i=0;i<b;++i)
    {

        for(int j=0;j<c;++j)
        {
            mat[i].x[j]=0;
        }
    }
}
void wypisz(int a, int b,struct Mapa *mat) //definicja funkcji wypisuj¹cej matrycê na ekran z odpowiednim formatowaniem
{
    printf("   %c[%dm",0x1B,33); for(int i=0;i<b;++i) {if(i<9)printf("%d  ", i+1);else printf("%d ", i+1);} //wypisywanie indeksów kolumn na gorze matrycy z formatowaniem koloru czcionki na zólty
    printf("\n");
    for(int i=0;i<a;++i)
    {
        printf("%c[%dm",0x1B,33); if (i < 9)printf("%d  ", i+1); //wypisywanie indeksow wierszy od ich lewej strony z kolorem zoltym
        else printf("%d ", i+1);
        for(int j=0;j<b;++j)
        {
            printf("%c[%dm",0x1B,0); // wypisywanie danych znajduj¹cych siê w matrycy i formatowañ, unikatowych dla ka¿dej wartoœci w matrycy
            if(mat[i].x[j] ==2){printf("%c[%dm",0x1B,32);printf("%d  ",mat[i].x[j]);} //gdy w danym miejscu znajduje siê wartoœæ 2, przypisywany jest jej kolor zielony w formatowaniu
            else if (mat[i].x[j] ==1){printf("%c[%dm",0x1B,31);printf("%d  ",mat[i].x[j]);} //gdy w danym miejscu znajduje siê wartoœæ 1, przypisywany jest jej kolor czerwony w formatowaniu
            else {printf("%c[%dm",0x1B,0); printf("%d  ",mat[i].x[j]);} //gdy w danym miejscu znajduje siê wartoœæ ró¿na od 1 i 2 (w domyœle 0), nie jest przypisywany  jej kolor formatowania
        }
        printf("%c[%dm",0x1B,33); if (i < 9)printf(" %d", i+1); //wypisywanie indeksów wierszy od ich prawej strony z kolorem zoltym
        else printf("%d", i+1);
        printf("\n");
        printf("%c[%dm",0x1B,0); //usuwanie formatowania czcionki w celu unikniêcia pokolorowania np. instrukcji dla gracza
    }
    printf("   %c[%dm",0x1B,33); for(int i=0;i<b;++i) {if(i<9)printf("%d  ", i+1);else printf("%d ", i+1);} //wypisywanie indeksów kolumn na dole matrycy z formatowaniem koloru czcionki na zólty
    printf("\n"); printf("%c[%dm",0x1B,0);
}
