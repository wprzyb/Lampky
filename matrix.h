#ifndef MATRIX_H
#define MATRIX_H
void arr_to_vec(int from[5][5], int to[25]);
void vec_to_arr(int from[25], int to[5][5]);
void acpy (int from[25], int to[25]);
void addto (int src[25], int v[25]);
int wt (int v[25]);
void gimme_hint(int current_board[5][5], int result[25]);
#endif
