#include<stdio.h>
#include<conio.h>

int a[80][80],m,n;
int path(int sum , int i , int j)
{
	int sum1,sum2,sum3;
	if(j==(n-1)&&i==(m-1))
	{
		return sum;
	}
	if(i==(m-1))
	{
		return path(sum+a[i][j+1],i,j+1);
	}
	if(j==(n-1))
	{
		return path(sum+a[i+1][j],i+1,j);
	}
	else
	{
		sum1 = path(sum+a[i+1][j],i+1,j);
		sum2 = path(sum+a[i][j+1],i,j+1);
		if(sum1 > sum2)
		{
			sum3 = sum1;
		}
		if(sum2 > sum1)
		{
			sum3 = sum1;
		}
	}
	return sum3;
}
int main()
{
	int b,c;
	printf("enter the no of rows \n");
	scanf("%d",&m);
	printf("enter the no of columsn \n");
	scanf("%d",&n);
	for(b=0;b<m;b++)
	{
		for(c=0;c<n;c++)
		{
			scanf("%d",&a[b][c]);
		}
	}
	printf("the matrix entered by you was \n \n");
	for(b=0;b<m;b++)
	{
		for(c=0;c<n;c++)
		{
			printf("%d \t",a[b][c]);
		}
		printf("\n");
	}
	printf ("the sum of max path is %d",path(a[0][0],0,0));
	getch();
	return 0;
}