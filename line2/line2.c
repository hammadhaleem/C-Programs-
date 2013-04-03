#include<stdio.h>
#include<conio.h>

void main()
{
char a,*p,str[80];
int i,j,digit[36];
for(i=0;i<36;i++)
{
	digit[i]=0;
}
printf("enter the line\n");
gets(str);
for(i=65;i<=90;i++)
{
	p=str;
	while(*p != '\0')
	{
		j=toupper(*p);
		if (j == i)
		{
			digit[i-65]=digit[i-65]+1;
		}
		p++;
	}
}
for(i=48;i<=57;i++)
{
	p=str;
	while(*p != '\0')
	{
		j=*p;
		if (j == i)
		{
			digit[i-22]=digit[i-22]+1;
		}
		p++;
	}
}
printf("the line entered by you was \n \n \t");
puts(str);
printf("\n \nletter/number \t frequency \n");
a='a';
for(i=0;i<26;i++)
{
	printf("%c \t \t %d \n",a,digit[i]);
	a++;
}
a='0';
for(i=26;i<36;i++)
{
	printf("%c \t \t %d \n",a,digit[i]);
	a++;
}
getch();
}