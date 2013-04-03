#include<stdio.h>
#include<string.h>
 
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    	char temp;
    	temp = *x;
    	*x = *y;
    	*y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n) 
{
   	int j; 
   	if (i == n)
     	printf("%s\n", a);
   	else
   	{
        	for (j = i; j <= n; j++)
       		{
         	 	swap((a+i), (a+j));
          		permute(a, i+1, n);
          		swap((a+i), (a+j)); //backtrack
      		}
   	}
} 
 
/* Driver program to test above functions */
int main()
{
   	char a[80];
	system("cls");
	printf("enter string \n");
	gets(a);  
   	permute(a, 0, strlen(a)-1);
   	getch();
   	return 0;
}
