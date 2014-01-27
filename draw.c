#include <stdio.h>
#define BGY     "\x1b[43m"
#define BGZ     "\x1b[42m"
#define BGL     "\x1b[42;1m"
#define BGR     "\x1b[0m"

void kreski(int size)
{
        int i;
        printf("\t ");
        for(i=0;i<(2*size-1);i++)  {printf("_");};
        printf("\n");
}

void litery(int size)
{
        char rowIdentifier[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
        int h;
        printf("\t ");
        for(h=0;h<size;h++)
                {
                        printf("%c ",rowIdentifier[h]);
                }
                printf("\n");
}

void render(int size, int tab[5][5], int cursor_x, int cursor_y)
{

int j,k;        //do tablicy
char sp;        //ponazywać zmienne po ludzku
litery(size);
kreski(size);


sp = '_'; //rozdzielnikiem bazowo jest spacja

for(j=0;j<size;j++)
{
        printf("%d",j+1);
        printf("\t|");
        if(j==size-1)
        {       sp='_'; // Ten kawałek zamknie dół w ostatnim przebiegu petli
        }

        for(k=0;k<size;k++)
        {
                if(tab[j][k] == 0)
                {
                    if(j == cursor_x && k == cursor_y)
                    {
                            printf(BGL "%c" BGR,sp);
                    }
                    else
                    {
                            printf(BGR "%c" BGR,sp);
                    }
                }
                else
                {
                    if(j == cursor_x && k == cursor_y)
                    {
                            printf(BGZ "%c" BGR,sp);
                    }
                    else
                    {
                            printf(BGY "%c" BGR,sp);
                    }
                }
                printf("|");
        }
        printf("\n");

}

}

void print_welcome(int podpowiedzi, char user[64])
{
        printf("Projekt zaliczeniowy\n");
        printf("--------------------\n");
        printf("gra \"Lights Out\"\n");
        printf("Wiktor Przybylski, WFAIS UJ\n");
        printf("Informatyka I Rok, Język C: Grupa 9 \n\n");
        printf("--------------------\n");
        printf("Zalogowano jako: %s\n",user);
if(podpowiedzi==1){
        printf("--------------------\n");
        printf("Sterowanie:\tWSAD + strzałki -\tPoruszanie się po planszy\n");
        printf("\t\tSpacja\\Enter -\t\tZgaszenie światła\n");
        printf("\t\tq\\Q -\t\t\tWyjście z gry\n");
        printf("\t\th\\H -\t\t\tWyłączenie podpowiedzi\n");
        printf("\t\tl\\L -\t\t\tLogowanie użytkownika\n");
        printf("\t\tb -\t\t\tHighscore Leaderboard\n");
}
        printf("--------------------\n\n");
}

void print_login()
{
		printf("Aby móc zapisywać swoje wyniki\n");
		printf("Należy się zalogować\n");
		printf("--------------------\n\n");
}
