#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include "funcprot.h"

int main()
{
    
    int *x,n,i;
  /*int x[20]={20,30,10,50,-700,90,60,100,-40,80,-3,25,754,69,-77,88,12,0,112,-75},n=20,i;
  printf("The random arrray is\n ");
  for(i=0;i<n;i++)
     printf("%d ",x[i]);
 */
  printf("Enter size of the array: ");
  scanf("%d",&n);
    x=(int *)malloc(sizeof(int) * n);  
  makeRandomArray(x,n);
  printf("The random arrray is\n ");
  for(i=0;i<n;i++)
    printf("%d\n",x[i]);
  
  clock_t start;
  start = clock();
   select(x,n,n/2);
   printf("\npivot is median of median = %d",x[n/2]);
  quicksort(x,0,n-1);

  printf("\nSorted elements: ");
  for(i=0;i<n;i++)
  printf(" %d\n",x[i]);
    	printf("   %d ticks\n", clock() - start);
    getch();
  return 0;
  
  
}
