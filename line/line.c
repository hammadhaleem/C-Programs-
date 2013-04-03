#include <stdlib.h>
#include <stdio.h>
#include <string.h>

main()
{
	char str[80],*p,re;
	int sp,no,v,c,ch,i;
	v=c=no=sp=ch=0;
	p = str;
	do
	{
		printf("enter the line\n");
		fflush(stdin);
		i=0;
		while((re = getch())!= '*')
		{
			//gets(str);
			str[i] = re;
			i++;
		}
		printf("confirm ? (y = yes , n = no)\n");
		re = getch();
	}
	while(re == 'y');
		while(*p != '\0')
	{
		if(*p=='a'||*p=='e'||*p=='i'||*p=='o'||*p=='u')
			v++;
		else if(*p>='a'&& *p<='z')
			c++;
		else if(*p>='0'&& *p<='9')
			no++;
		else if (*p==' ')
			sp++;
		else
			ch++;
	p++;
	}
		printf("the string entered by you was \n \n \t");
		puts(str);
		puts("\n");
		printf("the number of vowels in line are: %d \n",v);
		printf("the number of consonants in line are: %d \n",c);
		printf("the number of integers in line are: %d \n",no);
		printf("the number of special symbols in line are: %d \n",ch);
		printf("the number of spaces in line are: %d \n",sp);
		getch();
}