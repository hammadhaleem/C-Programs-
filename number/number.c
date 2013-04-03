#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int rem(int i)
{
		if(i>10)
		return i%10 ;
		else
		return i;
}
void main()
{
	char re;
	int num,a,b,c,d,i,j,s=0,arr[4];
	do
	{
	printf("Enter integer \n");
	scanf("%d",&i);
	printf("confirm (y = yes , n = no)\n");
	scanf(" %c",&re);
	}
	while(re == 'n');
	for (j=0;j<4;j++)
		{
            arr[j]=rem(i);
            i=i/10 ;
		}
    for (a=0;a<4;a++)
    {
        for (b=0;b<4;b++)
        {
            for (c=0;c<4;c++)
            {
                for (d=0;d<4;d++)
                {
                    if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
                    {
                        num = (arr[a]*1000)+(arr[b]*100)+(arr[c]*10)+(arr[d]);
                        printf("%d. %d \n",++s,num);
                    }
                }
            }
        }
    }
getch();
}
