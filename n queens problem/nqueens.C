#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int a[4][4],q[4]={0},m=0;

void reset()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j] = 0;
		}
	}
	for(i=0;i<4;i++)
	{
		q[i] = 0;
		m = 0;
	}
}

void move(int no)
{
	int r,c,i,j;
	no = no - 1;
	r = no / 4;
	c = no % 4;
	for(i=0;i<4;i++)
	{
		a[i][c] = 20;
	}
	for(j=0;j<4;j++)
	{
		a[r][j] = 20;
	}
	i=r;
	j=c;
	while(i <= 4 && j <= 4)
	{
		a[i][j] = 20;
		i++;
		j++;
	}
	i=r;
	j=c;
	while(i >= 0 && j >= 0)
	{
		a[i][j] = 20;
		i--;
		j--;
	}
	i=r;
	j=c;
	while(i <= 4 && j >= 0)
	{
		a[i][j] = 20;
		i++;
		j--;
	}
	i=r;
	j=c;
	while(i >= 0 && j <= 4)
	{
		a[i][j] = 20;
		i--;
		j++;
	}
}

int check(int no)
{
	int r,c,f=0,i,j;
	no = no - 1;
	r = no / 4;
	c = no % 4;
	for(i=0;i<4;i++)
	{
		if(a[i][c] == 20)
		{
			f = -1;
			break;
		}
	}
	for(j=0;j<4;j++)
	{
		if(a[r][j] == 20)
		{
			f = -1;
			break;
		}
	}
	i=r;
	j=c;
	while(i <= 4 &&  j <= 4)
	{
		if(a[i][j] == 20)
		{
			f = -1;
			break;
		}
		i++;
		j++;
	}
	i=r;
	j=c;
	while(i >= 0 && j >= 0)
	{
		if(a[i][j] == 20)
		{
			f = -1;
			break;
		}
		i--;
		j--;
	}
	i=r;
	j=c;
	while(i <= 4 &&  j >= 0)
	{
		if(a[i][j] == 20)
		{
			f = -1;
			break;
		}
		i++;
		j--;
	}
	i=r;
	j=c;
	while(i >= 0 && j <= 4)
	{
		if(a[i][j] == 20)
		{
			f = -1;
			break;
		}
		i--;
		j++;
	}
	return f;
}

void display()
{
	int i,j,k,f=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			f = 0;
			for(k=0;k<m;k++)
			{
				if(q[k] ==  ((4*i)+j+1))
				{
					printf("Q \t");
					f = 1;

				}
			}
			if(f == 0)
			{
				if(a[i][j] == 20)
				{
					printf("* \t");
				}
				else
				{
			       //printf("%d \t",a[i][j]);
			       printf("%d \t",(4*i)+j+1);
			       }
			}
		}
		printf("\n\n");
	}
	printf("\n\n");
	/*for(i=0;i<m;i++)
	{
		printf("%d ",q[i]);
	}*/
}

int main()
{
	int i,j=0,r,c,re,l=0;
	clrscr();
	printf("----CHESS QUEEN GAME BY MOONIS JAVED----\n\n\n");
	printf("\t A 4X4 CHESS BOARD IS GIVEN \n");
	printf("\t PLAYER HAS TO ENTER THE POSITION ON WHICH HE WANTS TO PLACE THE QUEEN \n");
	printf("\t IF YOU PLACE 4 QUEEN ON THE BOARD SUCH THAT NO QUEEN CAN KILL THE OTHER YOU WIN \n");
	printf("\t PRESS 0 TO RESET BOARD \n");
	printf("\t PRESS -1 TO QUIT \n");
	getch();
	reset();
	do
	{
		clrscr();
		display();
		printf("\n\nPosition : ");
		scanf("%d",&re);
		if(re == 0)
		{
			reset();
		}
		else if(re == -1)
		{
			printf("\nTHANK YOU FOR PLAYING \n");
			getch();
			exit(0);
		}
		else if(re >= 1 && re <= 16)
		{
			r = (re-1)/4;
			c = (re-1)%4;
			if(a[r][c] == 0)
			{
				j = 0;
				for(i=0;i<m;i++)
				{
					if(q[i] == re)
					{
						j = 1;
					}
				}
				if(j == 1)
				{
					printf("position already entered \n");
				}
				if(j == 0)
				{
					move(re);
					q[m] = re;
					m++;
				}
			}
			else
			{
				printf("Cant move there chose another position \n");
				getch();
			}
			if(m == 4)
			{
				clrscr();
				display();
				printf("\nYOU WIN \n\n");
				getch();
			}
			l = 0;
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(a[i][j] == 20)
					{
						l++;
					}
				}
			}
			if(l == 16)
			{
				if(m < 4)
				{
					clrscr();
					display();
					printf("you lose \n");
					getch();
					reset();
				}
			}

		}
		else
		{
			printf("invalid entered \n");
		}
	}
	while(m != 4 && re != -1);
	getch();
	return 0;
}





