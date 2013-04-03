#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	int i,n,l,k;
	printf("please enter the value of n");
	scanf("%d",&n);
	l=0;
	while(l<n)
	{
		for(i=0;i<(n-l);i++)
		{
			printf(" ");
		}
		k=pow(11,l+1);
		while(k%10)
		{
			printf("%d ",k%10);
			k=k/10;
		}
		printf("\n");
		l++;
	}
getch();
}
			