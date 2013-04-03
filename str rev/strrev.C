#include<stdio.h>
#include<conio.h>

int main()
{
	char str[80],*p,*q,a,re;
	do
	{
		fflush(stdin);
		printf("enter the string\n \n \t");
		gets(str);
		p=q=str;
		while(*p != '\0')
		{
			q=p;
			while(*q != ' ' && *q != '\0')
			{
				q++;
			}
			q--;
			while(p < q)
			{
				a = *p;
				*p = *q;
				*q = a;
				q--;
				p++;
			}
			while(*p != ' ' && *p != '\0')
			{
				p++;
			}
			p++;
		}
		printf("the string words in reversed order are \n \n \t%s",str);
		printf("\n \n enter again ? y = yes n = no \n \n");
		scanf("%c",&re);
		re=toupper(re);
	}
	while(re == 'Y');
	return 0;
}



