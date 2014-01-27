#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern int errno;
FILE *fp = NULL;

int dofileexist(char* filename)
{
	fp = fopen(filename, "r");
    return errno;
    fclose(fp);
}

void register_user(char* nickname, char* password)
{
	fp = fopen(nickname, "aw");
	fprintf(fp, "%s",password);
	fclose(fp);
}

int check_login_data(char* nickname, char* password)
{
	fp = fopen(nickname, "r");
	char pass[256];
	fscanf (fp, "%s", pass);
//	printf("%s", pass);
	fclose(fp);
	
	return strncmp(pass, password, 256);

}

int is_anybody_logged_in(char* user)
{
	char* guest = "Gość";
	int test = strncmp(user, guest, 256);
	if (test != 0) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push_to_hiscores(char* user, int score)
{
	fp = fopen("hi.scores", "aw");
	fprintf(fp, "%s|%d\n",user, score);
	fclose(fp);
}

void print_hiscores()
{
	fp = fopen("hi.scores", "r");
	int i=0;
	printf("Hiscores:\n");
	printf("-------------------------------\n");
	char dane[256];
	while(!feof(fp))
	{
		fscanf (fp, "%s ",&dane);
		printf("|\t%s\t|\n",dane);
		i++;
	}
	printf("-------------------------------\n\n\n");
	fclose(fp);
}
