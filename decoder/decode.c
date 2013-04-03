#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[80];
	int i;
	system("cls");
	printf("enter the encoded word\n");
	gets(str);
	for(i=0;i<strlen(str);i++)
	{
		str[i] = str[i] - i;
		if((int)str[i] < 97)
		{
			str[i] = str[i] + 25;
		}
	}
	puts(str);
}