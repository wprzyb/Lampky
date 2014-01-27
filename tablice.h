#ifndef TABLICE_H
#define TABLICE_H
void flip_the_light(int x, int y, int tab[5][5], int size);
void fill_randomly(int size, int table[5][5]);
void empty(int size, int table[5][5]);
void full(int size, int table[5][5]);
int did_i_win(int table[5][5]);
#endif
