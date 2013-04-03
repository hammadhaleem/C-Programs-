#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sll
{
	char name[20];
	int sal,age;
	struct sll *link;
}*head,*temp,*temp1;

int len()
{
	int len = 0;
	temp = head;
	printf("test");
	if(head == NULL)
	{
		len = 0;
	}
	else
	{
		do
		{
			temp = temp -> link;
			len++;
		}
		while(temp -> link != NULL);
	}
	return len;
}

void ins()
{
	struct sll *ptr;
	ptr = (struct sll*)malloc(sizeof(struct sll));
	system("cls");
	printf("enter name \n");
	scanf("%s",&(ptr->name));
	printf("enter salary \n");
	scanf("%d",&(ptr->sal));
	printf("enter age \n");
	scanf("%d",&(ptr->age));
	ptr->link = NULL;
	if(head == NULL)
	{
		head = ptr;
	}
	else
	{
		temp = head;
		while((ptr -> sal <= temp -> sal) && temp->link!=NULL)
		{
			temp = temp -> link;
		}
		ptr -> link = temp -> link;
		temp -> link = ptr;
	}
	printf("data inserted \n");
}

void del()
{
	int pos = 0,le,i = 0;
	system("cls");
	printf("enter which record to delete \n");
	scanf("%d",&pos);
	le = len();
	if(pos != 0 && pos >= le && pos != 1)
	{
		temp = head;
		for(i=0;i<pos-2;i++)
		{
			temp = temp -> link;
		}
		temp -> link = (temp->link)->link;
	}
	if(pos == 1)
	{
		head = head -> link;
	}
	else
	{
		printf("invalid link \n");
	}
}

void display()
{
	int i = 1;
	struct sll *ptr;
	ptr = (struct sll *)malloc(sizeof(struct sll));
	system("cls");
	printf("S.no\tName\tSalary\tAge\n\n");
	puts(head->name);
	if(head != NULL)
	{
		ptr = head;
		do
		{
			printf("%d\t%s\t%d\t%d\n",i,ptr->name,ptr->sal,ptr->age);
			i++;
			ptr = ptr -> link;
		}
		while(ptr -> link != NULL);
	}
	else
	{
		printf("NOTHING TO DISPLAY \n");
	}
	getch();
}

int main()
{
	int re;
	do
	{
		system("cls");
		printf("MENU\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter response value:\t");
		scanf(" %d",&re);
		switch(re)
		{
			case 1:
			ins();
			getchar();
			break;
			
			case 2:
			del();
			getchar();
			break;
			
			case 3:
			display();
			getchar();
			break;
			
			case 4:
			exit(0);
			
			case 5:
			printf("length = %d",len());
			getch();
			break;
			
			default:
			printf("invalid value enter again \n");
			break;
		}
	}
	while(re != 4);
	getch();
	return 0;
}
		