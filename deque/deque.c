#include<stdlib.h>
#include<stdio.h>

struct sll
{
	int data;
	struct sll *link;
};

struct sll *ins(struct sll *head)
{
	int no;
	struct sll *ptr = NULL;
	struct sll *temp;
	temp = head;
	ptr = (struct sll*)malloc(sizeof(struct sll*));
	printf("enter element \n");
	scanf(" %d",&no);
	ptr -> data = no;
	ptr -> link = NULL;
	if(head == NULL)
	{
		head = ptr;
		printf("test \n");
	}
	else if((temp = head->link) == NULL)
	{
		head->link = ptr;
	}
	else
	{
		while(temp -> link != NULL)
		{
			temp = temp -> link;
		}
		temp -> link = ptr;
	}
	printf("data inserted \n");
	getch();
}

struct sll *del(struct sll *head)
{
	int re;
	struct sll *temp;
	temp = head;
	if(head == NULL)
	{
		printf("queue empty \n");
	}
	else
	{
		printf("delete from head (0) / tail (1) ?\n");
		scanf(" %d",&re);
		switch(re)
		{
			case 0:
			printf("%d deleted \n",head->data);
			head = head -> link;
			break;
			
			case 1:
			while((temp -> link)-> link != NULL)
			{
				temp = temp -> link;
			}
			printf("%d deleted \n",(temp->link)->data);
			temp -> link = NULL;
			break;
			
			default:
			printf("wrong choice \n");
			break;
		}
	}
	getch();
}

void display(struct sll *head)
{
	struct sll *temp;
	temp = head;
	if(head == NULL)
	{
		printf("queue empty \n");
	}
	else
	{
		printf("queueu is \n");
		do
		{
			printf("%d \n",temp->data);
			temp = temp -> link;
		}
		while(temp -> link != NULL);
	}
	getch();
}

void isempty(struct sll *head)
{
	if(head == NULL)
	{
		printf("queue empty \n");
	}
	else
	{
		printf("queue not empty \n");
	}
	getchar();
}

int main()
{
	int re;
	struct sll *head = NULL;
	do
	{
		system("cls");
		printf("MENU \n\n1.Insert \n2.Delete \n3.Display \n4.Check Empty \n5.Exit \nenter your response \n");
		scanf(" %d",&re);
		switch(re)
		{
			case 1:
			head = ins(head);
			break;
		
			case 2:
			head = del(head);
			break;
			
			case 3:
			display(head);
			break;
			
			case 4:
			isempty(head);
			break;
			
			case 5:
			exit(0);
			break;
			
			default:
			printf("invalid choice \n");
			break;
		}
	}
	while(re != 5);
	getch();
	return 0;
}
	
			
	