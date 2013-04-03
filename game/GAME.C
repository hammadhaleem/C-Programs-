#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void display(int puzz[5][5])
{
	int i,j;
	clrscr();


	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(puzz[i][j]==77)

			{
				printf(" ");
				//puzz[4][4]=77;
			}

			else if(puzz[i][j]<10)

			printf("0%d  ",puzz[i][j]);

			else
			printf("%d  ",puzz[i][j]);
		}
		printf("\n");
	}

}


void game(int game[5][5])
{
char a;
int moves,i=4,j=4;
a='j';

printf("\n ENTER YOUR MOVE  ");




while(a!='\n')
{
     a=getch();

     if(a==80)
     {
	if(i==4)
	{

		game[i][j]=game[0][j];
		game[0][j]=77;
		i=0;
		display(game);
	}

		else
		{
			game[i][j]=game[i+1][j];
			game[i+1][j]=77;
			i=i+1;
			display(game);
		}
     }

	else if(a==72)
	{
		if(i==0)
		{
			game[0][j]=game[4][j];
			game[4][j]=77;
			i=4;
			display(game);
		}

			else
			{
				game[i][j]=game[i-1][j];
				game[i-1][j]=77;
				i--;
				display(game);
			}
	}


	else if(a==75)
	{
		if(j==0)
		{
			game[i][0]=game[i][4];
			game[i][[4]=77;
			j=4;
			display(game);
		}
			else
			{
				game[i][j]=game[i][j-1];
				game[i][j-1]=77;
				j--;
				display(game);
			}
	}

	else if(a==77)
	{
		if(j==4)
		{
			game[i][4]=game[i][0];
			game[i][0]=77;
			j=0;
			display(game);
		}

			else
			{
				game[i][j]=game[i][j+1];
				game[i][j+1]=77;
				j++;
				display(game);






}


}

void main()
{
	int arr[25]={0};
	int puzz[5][5],i,j,a;
	clrscr();

	randomize();


       //	for(i=0;i<5;i++)
       //	{
		for(j=0;j<24;j++)
		{
			ABC:
			a=rand()%24;
			if(arr[a]==1)
			goto ABC;

			else
			{
			       //	puzz[i][j]=a;
				puzz[j%5][j/5]=a;
				arr[a]++;
			}

		}
      //	}

	puzz[4][4]=77;
    /*	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i==4 && j==4)
			{
				printf(" ");
				puzz[4][4]=77;
			}

			else if(puzz[i][j]<10)

			printf("0%d  ",puzz[i][j]);

			else
			printf("%d  ",puzz[i][j]);
		}
		printf("\n");
	}     */

	display(puzz);
	game(puzz);

getch();

}