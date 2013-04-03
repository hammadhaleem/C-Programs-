#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	int m[100][100],a,b,i,j,dig[80],r,c,ctr,max,min,k;
	char str[80],*p;
	r=c=0;
	gets(str);
	p=str;
	while(*p >= '0' && *p <= '9')
	{
		dig[a]=*p-48;
		a++;
		p++;
	}
	if(*p == ' ');
	{
		dig[a]=0;
		b=a+1;
		a++;
		if(r == 0)
		{
			for(ctr=0;ctr<(a-1);ctr++)
			{
				r = dig[ctr]*pow(10,a-ctr-1) + r;
			}
		}
		p++;
	}
	while(*p >= '0' && *p <= '9')
	{
		dig[a]=*p-48;
		a++;
		p++;
	}
	if(c == 0)
	{
		for(ctr=b;ctr<(a);ctr++)
		{
			c = dig[ctr]*pow(10,a-ctr-1) + c;
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			m[i][j]=rand();
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			ctr=0;
			max=min=m[i][j];
			for(k=0;k<c;k++)
			{
				if(min>m[i][k])
				ctr++;
			}
			for(k=0;k<r;k++)
			{
				if(max<m[k][j])
				ctr++;
			}
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d \t",m[i][j]);
		}
		printf("\n");
	}
	if(ctr != (r*c))
	{
		printf("\n%d",m[i][j]);
    }
    if(ctr == (r*c))
	{
		printf("\n GUESS");
	}
	return 0;
}







