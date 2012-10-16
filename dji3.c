 #include<stdio.h>
#include<conio.h>

#define MAX 10
#define TEMP 0
#define PERM 1
#define infinity 9999

struct node
{
          int predecessor;
          int dist;
          int status;
};

int adj[MAX][MAX];
int n;
void main()
{
          int i,j;
          int source,dest;
          int path[MAX];
          int shortdist,count;
          clrscr();
printf("************************ DIJKSTRA'S SHORTEST PATH **********************");
          create_graph();
          printf("The adjacency matrix is :\n");
          display();

          while(1)
          {
                   printf("\nEnter source node(0 to quit) : ");
                   scanf("%d",&source);
                   printf("\nEnter destination node(0 to quit) : ");
                   scanf("%d",&dest);

                   if(source==0 || dest==0)
                             exit(1);

                   count = findpath(source,dest,path,&shortdist);
                    if(shortdist!=0)
                   {
                             printf("\nShortest distance is : %d\n", shortdist);
                             printf("\nShortest Path is : ");
                             for(i=count;i>1;i--)
                                      printf("%d->",path[i]);
                             printf("%d",path[i]);
                             printf("\n");
                   }
                   else
                             printf("\nThere is no path from source to destination node\n");
          }
          getch();
}

create_graph()
{
          int i,max_edges,origin,destin,wt;

          printf("Enter number of vertices : ");
          scanf("%d",&n);
          max_edges=n*(n-1);

          for(i=1;i<=max_edges;i++)
          {
                   printf("\nEnter edge %d(0 0 to quit) : ",i);
                   scanf("%d %d",&origin,&destin);
                   if((origin==0) && (destin==0))
                             break;
                   printf("\nEnter weight for this edge : ");
                   scanf("%d",&wt);
                   if( origin > n || destin > n || origin<=0 || destin<=0)
                   {
                             printf("\nInvalid edge!\n");
                             i--;
                   }
                   else
                             adj[origin][destin]=wt;
          }
}

display()
{
          int i,j;
          for(i=1;i<=n;i++)
          {
                   for(j=1;j<=n;j++)
                             printf("%3d",adj[i][j]);
                   printf("\n");
          }

}

int findpath(int s,int d,int path[MAX],int *sdist)
{
          struct node state[MAX];
          int i,min,count=0,current,newdist,u,v;
          *sdist=0;
          for(i=1;i<=n;i++)
          {
                   state[i].predecessor=0;
                   state[i].dist = infinity;
                   state[i].status = TEMP;
          }
          state[s].predecessor=0;
          state[s].dist = 0;
          state[s].status = PERM;
          current=s;
          while(current!=d)
          {
                   for(i=1;i<=n;i++)
                   {
                             if ( adj[current][i] > 0 && state[i].status == TEMP )
                             {
                                      newdist=state[current].dist + adj[current][i];
                                      if( newdist < state[i].dist )
                                      {
                                                state[i].predecessor = current;
                                                state[i].dist = newdist;
                                      }
                             }
                   }
                   min=infinity;
                   current=0;
                   for(i=1;i<=n;i++)
                   {
                             if(state[i].status == TEMP && state[i].dist < min)
                             {
                                      min = state[i].dist;
                                      current=i;
                             }
                   }

                   if(current==0)
                             return 0;
                   state[current].status=PERM;
          }
          while( current!=0 )
          {
                   count++;
                   path[count]=current;
                    current=state[current].predecessor;
          }
          for(i=count;i>1;i--)
          {
                   u=path[i];
                   v=path[i-1];
                   *sdist+= adj[u][v];
          }
          return (count);
}