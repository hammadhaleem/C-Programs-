#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int length(int argc , char *argv[])
{
	int a1,a2,a3,a4,a5,i,add[5];
	char **p1,**p2,**p3,**p4,**p5;
	a1 = a2 = a3 = a4 = a5 = 0;
	for(i=0;i<argc;i++)
	{
		if(strlen(argv[i])==1)
		{
			a1++;
		}
		if(strlen(argv[i])==2)
		{
			a2++;
		}
		if(strlen(argv[i])==3)
		{
			a3++;
		}
		if(strlen(argv[i])==4)
		{
			a4++;
		}
		if(strlen(argv[i])==5)
		{
			a5++;
		}
	}
	for(i=0;i<a1;i++)
	{
		*(p1 + i) = (char *)malloc(2);
	}
	for(i=0;i<a2;i++)
	{
		*(p2 + i) = (char *)malloc(3);
	}
	for(i=0;i<a3;i++)
	{
		*(p3 + i) = (char *)malloc(4);
	}
	for(i=0;i<a4;i++)
	{
		*(p4 + i) = (char *)malloc(5);
	}
	for(i=0;i<a5;i++)
	{
		*(p5 + i) = (char *)malloc(6);
	}
	a1 = a2 = a3 = a4 = a5 = 0;
	for(i=0;i<argc;i++)
	{
		if(strlen(argv[i])==1)
		{
			strcpy(*(p1+a1) , argv[i]);
			a1++;
		}
		if(strlen(argv[i])==2)
		{
			strcpy(*(p2+a2) , argv[i]);
			a2++;
		}
		if(strlen(argv[i])==3)
		{
			strcpy(*(p3+a3) , argv[i]);
			a3++;
		}
		if(strlen(argv[i])==4)
		{
			strcpy(*(p4+a4) , argv[i]);
			a4++;
		}
		if(strlen(argv[i])==5)
		{
			strcpy(*(p5+a5) , argv[i]);
			a5++;
		}
	}
	add[0] =(int *)p1;
	add[1] =(int *)p2;
	add[2] =(int *)p3;
	add[3] =(int *)p4;
	add[5] =(int *)p5;
	printf("base address = %d",&add[0]);
	return(&add[0]);
}
int main(int argc , char *argv[])
{
	int *a,i;
	char **q1,**q2,**q3,**q4,**q5;
	a = length(argc , argv);
	printf("base address = %d\n",a);
	for(i=0;i<5;i++)
	{
		printf("base address p%d = %d \n",i+1,*a);
		a++;
	}
	a = length(argc , argv);
	*q1 = *a;
	a++;
	*q2 = *a;
	a++;
	*q3 = *a;
	a++;
	*q4 = *a;
	a++;
	*q5 = *a;
	a++;
	printf("1 start = %c\n",**q1);
	printf("2 start = %c\n",**q2);
	printf("3 start = %c\n",**q3);
	printf("4 start = %c\n",**q4);
	printf("5 start = %c\n",**q5);
	getch();
	return 0;
}