#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int main()
{
	int a[20][20],s[20][20],i,j,k,l,m,n,c=9999,temp=0,d,e,g,h,o,p,n2,n1;
	clrscr();
	printf("enter the length of row\t");
	scanf("%d",&m);
	printf("\nenter the length of column0\t");
	scanf("%d",&n);
// function to genrate randmoize array
	randomize();
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		 n2=rand()%100;
		 n1=rand()%2;
		 if(n1==1)
		 {
		 n2=n2*-1;
		 a[i][j]=n2;
		 }
		 else
		 a[i][j]=n2;
		}
	}
      // random genrated
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for(k=1;k<=m;k++)
	{
	for(l=1;l<=n;l++)
	{
	for(d=1;d<=m;d++)
	{
	for(e=1;e<=n;e++)
	{
	temp = 0;
	for(i=l-1;i<d;i++)
	{
	for(j=k-1;j<e;j++)
	{
	temp += a[i][j];
	}
	}
	if(temp < c)
	{
	c = temp;
	g = l-1;
	h = k-1;
	o = d;
	p = e;
	}
	}
	}
	}
	}
	printf("\n min = %d\n ",c);
	printf("the minimum possible sub array in given array\n");
	for(i=g;i<o;i++)
	{
	for(j=h;j<p;j++)
	{
	printf("%d \t",a[i][j]);
	}
	printf("\n");
	}
	getch();
	return 0;

	}



