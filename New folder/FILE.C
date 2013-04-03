#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	FILE *p;
	char ch;
	p = fopen("file.c","r+");
	clrscr();
	do
	{
	       ch = fgetc(p);
	       if(ch == '\n')
	       {
			delay(300);
	       }
	       printf("%c",ch);
	}
	while (!feof(p));
	fclose(p);
	getch();
	return 0;
}
