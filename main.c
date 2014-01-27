#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "draw.h"
#include "brakujace.h"
#include "tablice.h"
#include "files.h"
#include "matrix.h"

/////////////////////////
#define DEBUG 0
/////////////////////////

#define W_KEY       119
#define A_KEY       97
#define S_KEY       115
#define D_KEY       100

#define UP_KEY      65
#define DOWN_KEY    66
#define RIGHT_KEY   67
#define LEFT_KEY    68

#define SPACEBAR    32
#define RETURN      10

#define H_LOWER     104
#define H_UPPER     72

#define Q_LOWER		113
#define Q_UPPER		81

#define L_LOWER		108
#define L_UPPER		76

#define B_LOWER		98

#define QUESTION	63

main(){
int tablica[5][5] ;
empty(5,tablica);
char uzytkownik[64] = "Gość";
int	size = 5;

int klawisz;
int ruchy = 0;
int tip = 1;
int solve = 0;
int kur_x = 0, kur_y = 0;
int temp;
char login[256];
char password[256];
int hint_v[25];
int hint_a[5][5];
int robocza[25];

int min=0;
    

        fill_randomly(size,tablica);
		gimme_hint(tablica, hint_v);
		min = wt(hint_v);
        print_welcome(tip, uzytkownik);
        render(size,tablica, 0, 0);

while(klawisz = getch()) //q
    {
		czysc();

		if(klawisz == W_KEY || klawisz == UP_KEY)
		{
			kur_x = (kur_x>0) ? kur_x-1:size-1;
		}
		if(klawisz == A_KEY || klawisz == LEFT_KEY)
		{
			kur_y = (kur_y>0) ? kur_y-1:size-1;
		}
		if(klawisz == S_KEY || klawisz == DOWN_KEY)
		{
			kur_x = (kur_x<size-1) ? kur_x+1:0;
		}
		if(klawisz == D_KEY || klawisz == RIGHT_KEY)
		{
			kur_y = (kur_y<size-1) ? kur_y+1:0;
		}
		if(klawisz == SPACEBAR || klawisz == RETURN)
		{
			flip_the_light(kur_x, kur_y, tablica, size);
			ruchy++;
		}
		if(klawisz == H_LOWER || klawisz == H_UPPER)
		{
			tip = (tip == 0) ? 1:0;
		}
		if(klawisz == B_LOWER)
		{
			czysc();
			print_hiscores();
		}
		if(klawisz == Q_LOWER || klawisz == Q_UPPER)
		{
			break;
		}
		if(klawisz == QUESTION)
		{
			solve = (solve == 0) ? 1:0;
		}
		if(klawisz == L_LOWER || klawisz == L_UPPER)
		{
			czysc();
			print_login();
			printf("\nLogin: ");
			scanf("%s", login);
			if( (temp = dofileexist(login)) != 0) 
			{
				printf("\n\nUżytkownika nie było w bazie, \nrejestruję użytkownika o loginie: %s\nWpisz hasło jakie mam nadać użytkownikowi\nPo zarejestrowaniu uruchom grę ponownie\n\n", login);
			}
			else
			{
				printf("Użytkownik %s znajduje się w bazie - wpisz poprawne hasło:\n\n", login);
			}
			printf("\nHaslo: ");
			scanf("%s", password);
			if(temp != 0)
			{
				register_user(login, password);
				break;
			}
			else
			{
				if (check_login_data(login,password) == 0) {printf("Logowanie zakończone pomyślnie\n"); strcpy(uzytkownik,login);}
				else {printf("Wprowadzono złe hasło\n");}
			}
			czysc();
		}
		
		

			print_welcome(tip, uzytkownik);
			
			render(size,tablica,kur_x, kur_y);
			if(solve == 1){
				gimme_hint(tablica, hint_v);
				vec_to_arr(hint_v,hint_a);
				render(size,hint_a,kur_x, kur_y);
			}
			
			printf("\nIlość wykonanych ruchów: %d, minimalna ilosc ruchów do wygranej: %d\n", ruchy,min);
			
			
			if(did_i_win(tablica)!=1){printf("\nJeszcze nie wygrałeś");}
			else
			{
				printf("\nWygrałeś\n\n");
				if(ruchy != min)
				{
						if(ruchy < min){printf("\nSzczere gratulacje, komputer był gorszy od Ciebie w szukaniu najszybszej metody\n");}
						if(ruchy > min){printf("\nNajszybsza metoda nie została przez Ciebie użyta do rozwiązania tej łamigłówki\n");}
				}
				else if(ruchy == min) {printf("\nWybrano dokładnie tą samą metodę co komputer ;)\n");}
				
				if(is_anybody_logged_in(uzytkownik) != 0)
				{
					printf("Zostałeś wpisany na listę najwyższych wyników jako %s z wynikiem %d punktów",uzytkownik, ruchy);
					push_to_hiscores(uzytkownik, ruchy);
				}
				else
				{
					printf("Nie byłeś zalogowany, twój wynik to %d, jednak nie zostanie on wpisany na listę najlepszych wyników", ruchy);
					
				}
			}
    }

}
