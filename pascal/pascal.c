#include<stdio.h>

int main()
{
	int i,j,a[100][100],no;
	system("cls");
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(i == 0)
			{
				a[i][j] = 1;
			}
			else
			{
				if(j == 0)
				{
					a[i][j] = 0 + a[i-1][j];
				}
				else if(j == i)
				{
					a[i][j] = a[i-1][j-1] + 0;
				}
				else
				{
					a[i][j] = a[i-1][j] + a[i-1][j-1];
				}
			}
		}
	}
	for(i=0;i<no;i++)
	{
		for(j=no;j>i+1;j--)
		{
			printf("  ");
		}
		for(j=0;j<=i;j++)
		{
			printf("%d   ",a[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}