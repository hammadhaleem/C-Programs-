#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()
{
	char str[80],*p;
	int sp,no;
	p=str;
	printf("enter the line\n");
	gets(str);
	while(*p != "\0")
	{
		if((*p)>=0 && (*p)<=9)
		{
			no++;
			p++;
		}
		if(*p == " ")
		{
			sp++;
			p++;
		}
	}
	printf("the number of spaces in line are %d \n",no);
	printf("the number of integers in line are %d \n",sp);
	getch();
}
