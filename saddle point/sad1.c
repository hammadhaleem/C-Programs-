#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
void main()
{
	int a[100][100], max, min,i,k,j,ctr=0,sp=0,r,c,s=0,l;
	scanf("%d%d",&r,&c);
	srand ( time(NULL) );
	for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    {
		a[i][j]=(rand()/1000);
    }
	for(i=0;i<r;i++)
	{
		if(ctr ==(r+c))
		{
			break;
		}
		else
		{
			for(j=0;j<c;j++)
			{
				if(ctr==(r+c))
				{
					s=a[i][j];
					break;
				}
				else
				{
					ctr=0;
					max=min=a[i][j];
					for(k=0;k<c;k++)
					{
						if(min<=a[i][k])
						{
							ctr++;
						}
					}
					for(l=0;l<r;l++)
					{
						if(max>=a[k][j])
						{
							ctr++;
						}
					}
				}
			}
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
    if (s == 0)
	{
		printf("\n GUESS \n");
	}
	else
	{
		printf("\n %d %d\n",i,j);
	}   
	getch();
 }
