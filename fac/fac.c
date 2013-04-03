#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int numArr[3000];			
	int total,rem=0,count,no;	
	register int i;
	i=2999;				//start from end of array.
	numArr[2999]=1;	
	system("cls");
	scanf("%d",&no);
	for(count=2;count<=no;count++)
	{
		while(i>0)
		{
			total=numArr[i]*count+rem;
			rem=0;
				if(total>9)
				{
					numArr[i]=total%10;
					rem=total/10;
				}
				else
					numArr[i]=total;
				i--;
		}
		rem=0;
		total=0;
		i=2999;
	}
	for(count=2999;count>=0;count--)
	{
		printf("%d",numArr[count]);
	}
	getch();
	return 0;
}