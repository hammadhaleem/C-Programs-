#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int a[10][10], max, min,i,k,j,ctr=0,sp=0;


    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
        {
            a[i][j]=rand();
        }



    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
        {
            ctr=0;
            max=min=a[i][j];
            for(k=0; k<10; k++)
                if(min>a[i][k])
                    ctr++;

            for(k=0; k<10; k++)
                if(max<a[k][j])
                    ctr++;

            for(i=0; i<10; i++)
            {
                for(j=0; j<10; j++)
                {
                    printf("%d \t",a[i][j]);
                }
                printf("\n");
            }

            if(ctr==0)
                printf("\n%d",a[i][j]);
            else sp++;
        }
    if(sp==100)
        printf("\nGUESS");



    return 0;
}
