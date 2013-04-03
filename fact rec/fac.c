#include "stdio.h"
fact(int n)
	{ int factorial;
	  if(n==1)
	   return 1;
	  else
	   factorial=fact(n-1)*n;
	  return factorial;
	}
main()
	{ int num,factorial;
	  printf("Enter any number : ");
	  scanf("%d",&num);
	  factorial=fact(num);
	  printf("The factorial of %d is %d ",num,factorial);
	  return 0;
	}
