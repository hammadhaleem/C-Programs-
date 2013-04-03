#include<stdio.h>
#include<stdlib.h>

struct sll
{
	char name[20];
	int sal;
	struct sll *link;
}*head,*temp;

void push()
{
	struct sll *ptr;
	ptr = (struct sll*)malloc(sizeof(struct sll));
	printf("enter name \n");
	fflush(stdin);
	scanf("%s",&ptr->name);
	printf("enter salary \n");
	scanf(" %d",&ptr->sal);
	ptr->link = NULL;
	if(head == NULL)
	{
		head = ptr;
	}
	else
	{
		temp = head;
		while(temp->sal >= ptr->sal)
		{
			temp = temp->link;
		}
		ptr->link = temp->link;
		temp->link = ptr;
	}
}

void pop()
{
	if(head == NULL)
	{
		printf("list empty nothing to pop \n");
	}
	else
	{
		head=head->link;
	}
}

void display()
{
	for(temp=head;temp!=NULL;temp=temp->link)
	{
		printf("[ %s %d ]");
		if(temp->link != NULL)
		{
			printf(" -> ");
		}
	}
}

void save()
{
	FILE *p;
	p = fopen("data.dat","w");
	for(temp=head;temp!=NULL;temp=temp->link)
	{
		fprintf(p,"%s %d ",temp->name,temp->sal);
	}
	fclose(p);
	printf("data saved \n");
}

int main()
{
	FILE *p;
	int re;
	p=fopen("data.dat","r+");
	do
	{	
		system("cls");
		display();
		printf("\n\nMENU \n\n");
		printf("1.Insert \n2.Delete \n3.Display \n4.Save \n5.Exit \nenter response value \n");
		scanf(" %d",&re);
		switch(re)
		{
			case 1:
			push();
			getch();
			
			case 2:
			pop();
			getch();
			
			case 3:
			display();
			getch();
			
			case 4:
			save();
			getch();
			
			case 5:
			exit(0);
			
			default:
			printf("wrong value \n");
			break;
		}
	}
	while(re != 4);
	getch();
	return 0;
}
	
	
	