#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	char str[80],*p,re;
	float p1,p2;
	int dig[80],i,l;
	do
	{
		printf("Enter the expression \n \n \n \t");
		fflush(stdin);
		p1=p2=i=l=0;
		for(l=0;l<80;l++)
		{
			dig[l]=0;
		}
		p = str;
		gets(str);
		while(*p >= '0' && *p <= '9')
		{
			if (*p >= '0' && *p <= '9')
			{
				dig[i]=*p-48;
				i++;
			}
			else
			{
				printf("Invalid Expression\n");
				break ;
			}
			p++;
		}
		for(l=0;l<(i+1);l++)
		{
			p1 = (dig[l] * pow(10,i-l-1)) + p1;
		}
		while(*p != '\0')
		{
			if(*p == '+')
			{
				p++;
				for(l=0;l<80;l++)
				{
					dig[l]=0;
				}
				p2=0;
				i=0;
				while(*p >= '0' && *p <= '9')
				{
					dig[i]=*p-48;
					i++;
					p++;
				}
				for(l=0;l<(i+1);l++)
				{
					p2 = (dig[l] * pow(10,i-l-1)) + p2;
				}
				p1 = p1 + p2;
			}
			if(*p == '-')
			{
				p++;
				for(l=0;l<80;l++)
				{
					dig[l] = 0;
				}
				p2=0;
				i=0;
				while(*p >= '0' && *p <= '9')
				{
					dig[i]=*p-48;
					i++;
					p++;
				}	
				for(l=0;l<(i+1);l++)
				{
					p2 = (dig[l] * pow(10,i-l-1)) + p2;
				}
				p1 = p1 - p2;
			}
			if(*p == '*')
			{
				p++;
				for(l=0;l<80;l++)
				{
					dig[l] = 0;
				}
				p2=0;
				i=0;
				while(*p >= '0' && *p <= '9')
				{
					dig[i]=*p-48;
					i++;
					p++;
				}
				for(l=0;l<(i+1);l++)
				{
					p2 = (dig[l] * pow(10,i-l-1)) + p2;
				} 
				p1 = p1 * p2;
			}
			if(*p == '/')
			{
				p++;
				for(l=0;l<80;l++)
				{
					dig[l] = 0;
				}
				p2=0;
				i=0;
				while(*p >= '0' && *p <= '9')
				{
					dig[i]=*p-48;
					i++;
					p++;
				}		
				for(l=0;l<(i+1);l++)
				{
					p2 = (dig[l] * pow(10,i-l-1)) + p2;
				}
				p1 = p1 / p2;
			}
			if(*p == '^')
			{
				p++;
				for(l=0;l<80;l++)
				{
					dig[l] = 0;
				}
				p2=0;
				i=0;
				while(*p >= '0' && *p <= '9')
				{
					dig[i]=*p-48;
					i++;
					p++;
				}
				for(l=0;l<(i+1);l++)
				{
					p2 = (dig[l] * pow(10,i-l-1)) + p2;
				}
				p1 = pow(p1,p2);
			}
			if(*p <= '0' && *p >= '9')
			{
				printf("Invalid Expression \n");
				break ;
			}
			p--;
			p++;
		}
		if(*p == '\0')
		{
			printf("The expression entered by you is \n \t");
			puts(str);
			printf("\n \n Result : %f\n\n",p1);
		}
		printf("Enter expression again ? (y = yes / n = no)");
		scanf(" %c",&re);
		re = toupper(re);
	}
	while(re == 'Y');
}