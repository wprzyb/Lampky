#ifndef FILES_H
#define FILES_H
int dofileexist(char filename[64]);
int register_user(char nickname[64], char password[64]);
int check_login_data(char* nickname, char* password);
int is_anybody_logged_in(char* user);
void push_to_hiscores(char* user, int score);
void print_hiscores();
#endif
