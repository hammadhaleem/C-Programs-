/* Program for searching a node through BFS and DFS */
#include<stdio.h>
#include<conio.h>
#define MAX 20

typedef enum boolean{false,true} bool;
int adj[MAX][MAX];
bool visited[MAX];
int n;
create_graph()
{
	int i,j,max_edges,origin,destin;
	int mat[20][20];
	FILE *fp;
	fp=fopen("bfsdfs.txt","r+");
	fscanf(fp,"%d",&n);
	while(!feof(fp))
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				fscanf(fp,"%d",&mat[i][j]);
	}
	max_edges=n*(n-1);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(mat[i][j]==1)
				adj[i+1][j+1]=1;
}
display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%4d",adj[i][j]);
		printf("\n");
	}
}
dfs(int v,int node)
{
	int i,stack[MAX],top=-1,pop_v,j,t;
	int ch;
	top++;
	stack[top]=v;
	while (top>=0)
	{
		pop_v=stack[top];
		top--;
		if( visited[pop_v]==false)
		{
			if(pop_v==node)
				return(1);
			visited[pop_v]=true;
		}
		else
			continue;
		for(i=n;i>=1;i--)
		{
			if( adj[pop_v][i]==1 && visited[i]==false)
			{
				top++;
				stack[top]=i;
			}
		}
	}
	return(0);
}
bfs(int v,int node)
{
	int i,front,rear;
	int que[20];
	front=rear= -1;
	visited[v]=true;
	rear++;
	front++;
	que[rear]=v;
	while(front<=rear)
	{
		v=que[front];
		front++;
		for(i=1;i<=n;i++)
		{
			if( adj[v][i]==1 && visited[i]==false)
			{
				if(i==node)
					return(1);
				visited[i]=true;
				rear++;
				que[rear]=i;
			}
		}
	}
	return(0);
}
main()
{
	int i,v,choice,search,node;
	clrscr();
	create_graph();
	while(1)
	{
		clrscr();
		printf("\n\t**MENU**\n");
		printf("1. Adjacency matrix\n");
		printf("2. Search Using Depth First Search\n");
		printf("3. Search Using Breadth First Search\n");
		printf("4. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nNo of nodes=%d \n\n",n);
				printf("Adjacency Matrix\n");
				display();
				break;
			case 2:
				printf("Enter starting node for Depth First Search : ");
				scanf("%d",&v);
				printf("Enter Node to be Searched : ");
				scanf("%d", &node);
				for(i=1;i<=n;i++)
					visited[i]=false;
				search=dfs(v,node);
				display();
				if(search==1)
					printf("\nNODE FOUND...");
				else
					printf("\nNODE NOT FOUND...");
				break;
			case 3:
				printf("Enter starting node for Breadth First Search : ");
				scanf("%d", &v);
				printf("Enter Node to be Searched : ");
				scanf("%d", &node);
				for(i=1;i<=n;i++)
					visited[i]=false;
				search=bfs(v,node);
				display();
				if(search==1)
					printf("\nNODE FOUND...");
				else
					printf("\nNODE NOT FOUND...");
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice\n");
				break;
		}
		printf("\n\nPress any key to continue...");
		getch();
	}
}