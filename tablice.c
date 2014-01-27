#include <stdio.h>
#include <time.h>

void flip_the_light(int x, int y, int tab[5][5], int size)
{
	if(x <= size && x >= 0 && y <= size && y >= 0 )
	{
		tab[x][y] = (tab[x][y] == 0) ? 1:0;

		if(x != 0)
		 tab[x-1][y] = (tab[x-1][y] == 0) ? 1:0;
		if(x != size-1)
		 tab[x+1][y] = (tab[x+1][y] == 0) ? 1:0;

		if(y != 0)
		 tab[x][y-1] = (tab[x][y-1] == 0) ? 1:0;
		if(y != size-1)
		 tab[x][y+1] = (tab[x][y+1] == 0) ? 1:0;
	}
}

void fill_randomly(int size, int table[5][5])
{
    srand(time(NULL));
        int temp_w, temp_h;
        for(temp_w = 0; temp_w < size; temp_w++)
        {
                for(temp_h = 0; temp_h < size; temp_h++)
                {
                table[temp_w][temp_h] = (rand()%100)%2;
                }
        }
}

void empty(int size, int table[5][5])
{
        int temp_w, temp_h;
        for(temp_w = 0; temp_w < size; temp_w++)
        {
                for(temp_h = 0; temp_h < size; temp_h++)
                {
                table[temp_w][temp_h] = 0;
                }
        }
}

void full(int size, int table[5][5])
{
        int temp_w, temp_h;
        for(temp_w = 0; temp_w < size; temp_w++)
        {
                for(temp_h = 0; temp_h < size; temp_h++)
                {
                table[temp_w][temp_h] = 1;
                }
        }
}

int did_i_win(int table[5][5])
{
	int i,j,suma=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			suma = suma+table[i][j];
		}
	}
	if(suma==0){return 1;}
	else {return 0;}
			
}
