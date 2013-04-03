#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

float f(float x)
{
	float sum;
	sum=pow(x,3)+x+3;
	return sum;
}

int main()
{
	float a,b,c,y0,y1,m;
	Step:
	printf("enter the value of a,b and c");
	scanf("%f%f%f",&a,&b,&c);
	y1=f(a);
	y0=f(b);
	if(y0*y1>0)
    {
        goto Step;
    }
	step1:
	m=(a+b)/2;
	if(f(m)==0)
	{
		printf("the root is : %f",m);
		exit(0);
	}
	else 
    {
		if (y1*f(m)<0)
        b=m;
		else
        a=m; 
    }
	if(a-b>c) 
	{
        goto step1;
    }
    printf("the root is :%f",m);
    getch();
	return 0;
}