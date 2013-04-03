#include<stdio.h>
#include<math.h>
#include<string.h>

int convert(int no)
{
	int i,noc;
	if(no >= 48 && no <= 57)
	{
		noc = no - 48;
		printf("%d \n",noc);
	}
	if(no>= 65 && no <= 90)
	{
		noc = no - 55;
		printf("%d \n",noc);
	}
	if(no>= 97 && no <= 122)
	{
		noc = no - 61;
		printf("%d \n",noc);
	}
	return noc;
}

int convertb(int noc)
{
	int i;
	int nocb;
	if(noc >= 0 && noc <= 9)
	{
		nocb = noc + 48;
	}
	if(noc >= 10 && noc <= 35)
	{
		nocb = noc + 55;
	}
	if(noc >= 36 && noc <= 61)
	{
		nocb = noc + 61;
	}
	return nocb;
}

char *base(char no[] , int b , int b1)
{
	int i,no2=0,r;
	char no1[80]="";
	for(i=0;i<strlen(no);i++)
	{
		if(no[i] >= '0' && no[i] <= '9')
		{
			no2 = no2 + (pow(b,(strlen(no)-1)-i)*(no[i]-48));
		}
		if(no[i]>='A' && no[i] <='Z')
		{
			no2 = no2 + (pow(b,(strlen(no)-1)-i)*(no[i]-55));
		}
		if(no[i]>='a' && no[i] <='z')
		{
			no2 = no2 + (pow(b,(strlen(no)-1)-i)*(no[i]-61));
		}
	}
	i=0;
	do
	{
		r = no2%b1;
		r = convertb(r);
		no1[i] = r;
		i++;
		no2 = no2/b1;
	}
	while(no2 > 0);
	strrev(no1);
	return no1;
}
	
char *add(char no[] , char no1[] , int b , int b1)
{
	int i,r=0,j,noc1[80],noc2[80],t=0,l=0;
	for(i=0;i<strlen(noc1);i++)
	{
		noc1[i] == 0;
		noc2[i] == 0;
	}
	char no2[80]="",temp="";
	if(b != b1)
	{
		strcpy(no1,base(no1,b1,b));
		b1 = b;
	}
	if(strlen(no) > strlen(no1))
	{
		j = strlen(no) - strlen(no1);
		for(i=strlen(no)-1;i>=j;i--)
		{
			no1[i] = no1[i-j];
		}
		for(i=0;i<j;i++)
		{
			no1[i] = '0';
		}
	}	
	else if(strlen(no1) > strlen(no))
	{
		j = strlen(no1) - strlen(no);
		for(i=strlen(no1)-1;i>=j;i--)
		{
			no[i] = no[i-j];
		}
		for(i=0;i<j;i++)
		{
			no[i] = '0';
		}
	}
	for(i=0;i<strlen(no);i++)
	{
		noc1[i] = convert(no[i]);
		noc2[i] = convert(no1[i]);
	}
	puts(noc1);
	puts(noc2);
	do
	{
		t = noc1[i] + noc2[i] + l;
		r = t%b;
		r = convertb(r);
		no2[i] = r;
		i++;
		l = t/b;
	}
	while(l > 0);
	return no2;
}			

int main()
{
	int b,b1,i,no2=0,r;
	char no[80]="",no1[80]="",o;
	system("cls");
	system("color A");
	printf("what do you want to do \n\n");
	printf(" 1 : base convert \n");
	printf(" 2 : add numbers \n");
	o = getchar();
	fflush(stdin);
	if(o == '1')
	{
		printf("enter the number \n");
		gets(no);
		printf("enter the base of the number \n");
		scanf("%d",&b);
		printf("enter the base you want to conver to \n");
		scanf("%d",&b1);
		printf("%s in base %d = %s",no,b1,base(no,b,b1));
	}
	if(o =='2')
	{
		printf("enter the number \n");
		gets(no);
		printf("enter the base of the number \n");
		scanf("%d",&b);
		printf("enter the number \n");
		fflush(stdin);
		gets(no1);
		printf("enter the base of the number \n");
		scanf("%d",&b1);
		printf("sum  = %s  (base : %d)",add(no,no1,b,b1),b);
	}
	getch();
	return 0;
}
	