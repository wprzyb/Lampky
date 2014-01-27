#include <stdio.h>
#include <stdlib.h>

int hint_matrix[23][23] = {	{ 0,1,1,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0 },
							{ 1,1,0,1,1,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0 },
							{ 1,0,1,1,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,1,0,1,0 },
							{ 1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1 },
							{ 0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0 },
							{ 0,0,1,0,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0 },
							{ 0,1,0,1,0,1,1,0,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0 },
							{ 1,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1 },
							{ 0,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,0,1,1 },
							{ 1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,1 },
							{ 0,0,0,0,1,0,0,0,1,1,0,0,1,0,1,1,1,1,1,0,0,1,0 },
							{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1 },
							{ 0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,0,0,1,1,0 },
							{ 1,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0 },
							{ 1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,1,0,1,0,0 },
							{ 0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,0,1,1,0,1 },
							{ 0,0,1,1,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,0,0,1 },
							{ 0,0,1,0,1,0,1,1,0,1,1,0,1,0,0,1,1,0,1,1,1,0,0 },
							{ 0,1,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,1,0,0,0,1 },
							{ 1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1 },
							{ 0,0,0,1,1,0,0,1,0,0,0,1,1,0,1,1,0,1,0,1,1,1,0 },
							{ 0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1 },
							{ 0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,0,1,0 },
							};

int n1[25] = {1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1};
int n2[25] = {1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1};

void arr_to_vec(int from[5][5], int to[25])
{
	int i=0,j=0;
	
	for(i;i<5;i++){
		for(j;j<5;j++){
			
			to[i*5+j] = from[i][j];
		}
	}
}

void vec_to_arr(int from[25], int to[5][5])
{
	int i=0;
	for(i;i<25;i++){
		to[i%5][i/5] = from[i];
	}
}

void acpy (int from[25], int to[25])
{
	int i;
    for (i=0; i<25; i++){
			to[i] = from[i];
	}
}

void addto (int src[25], int v[25])
  {
    int i;
    for (i=0; i<25; i++) {
      src[i] = (src[i] + v[i]) %2 ;
    }
  }
    
int wt (int v[25])
  {
    int i,t=0;
    for (i=0; i < 25; i++) {
      t = t + v[i];
    }
    return(t);
  }

void gimme_hint(int current_board[5][5], int result[25], int min)
  {
    int current_state[23];
    int hint_vector[25];
    int best[25];
    int next[25];
    int i,j;

    for (i=0; i<25; i++) {
      hint_vector[i] = 0;
    }
    for (i=0; i<23; i++) {
      if (current_board[i%5][i/5]) {
	current_state[i] = 1; }
      else {
	current_state[i] = 0; }
    }
    for (i=0; i<23; i++) {
      for (j=0; j<23; j++) {
	hint_vector[i] = 
	  (hint_vector[i] + current_state[j]*hint_matrix[i][j])%2;
      }
    }

    // Now we have a working hint vector, but we test h+n1, h+n2 
    // and h+n1+n2 to see which has the lowest weight, giving a
    // shortest solution.

    acpy(hint_vector,best);
    acpy(hint_vector,next);
    addto(next,n1);
    if ( wt(next) < wt(best) ) {
      acpy(next,best);
    }
    acpy(hint_vector,next);
    addto(next,n2);
    if ( wt(next) < wt(best) ) {
      acpy(next,best);
    }
    acpy(hint_vector,next);
    addto(next,n1);
    addto(next,n2);
    if ( wt(next) < wt(best) ) {
      acpy(next,best);
    }
  
  acpy(best,result);
  
  }
