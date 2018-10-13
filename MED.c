#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include "funcprot.h"

const int SEED = 352302;

void makeRandomArray(int* a, int size) 
{
      srand(SEED);
      int i;
     for( i=0; i<size; i++) 
     {
         a[i] = rand();
       // a[i]=  i;
     }

}
//swap two elements
void swap(int *a, int *b)
    {
		int t = *a;
		*a = *b;
    	*b = t;
	}
//compute the median of 5 elements
int median5(int *a)
 {
 int a0 = a[0];
 int a1 = a[1];
 int a2 = a[2];
 int a3 = a[3];
 int a4 = a[4];
}


if (a1 < a0)
swap(&a0, &a1);
if (a2 < a0)
swap(&a0, &a2);
if (a3 < a0)
swap(&a0,& a3);
if (a4 < a0)
swap(&a0, &a4);
if (a2 < a1)
swap(&a1, &a2);
if (a3 < a1)
swap(&a1, &a3);
if (a4 < a1)
swap(&a1, &a4);
if (a3 < a2)
swap(&a2, &a3);
if (a4 < a2)
swap(&a2, &a4);

if (a2 == a[0])
return 0;
if (a2 == a[1])
return 1;
if (a2 == a[2])
return 2;
if (a2 == a[3])
return 3;
// else if (a2 == a[4])
return 4;
}


//partition the array
int partition(int *a, int size, int pivot)
{
    int loadPos;
    int pivotValue = a[pivot];
    swap(&a[pivot], &a[size-1]);
    int storePos = 0;
    for( loadPos=0; loadPos < size-1; loadPos++)
    {
	    if (a[loadPos] < pivotValue)
	    {
			   swap(&a[loadPos], &a[storePos]);
			   storePos++;
	    }
    }
    swap(&a[storePos], &a[size-1]);
    return storePos;
}


//select median of median
void select(int *a, int size, int k)
{
    
    int MOMIdx,l,i,j;
    if (size < 5)   //insertion sort
     {
    	for ( i=0; i<size; i++)
	    for ( j=i+1; j<size; j++)
		if (a[j] < a[i])
		    swap(&a[i], &a[j]);
	return;
    }
    else
    {
int groupNum = 0;
int *group = a;

for( ; groupNum*5 <= size-5; group += 5, groupNum++)
{
   swap(&group[median5(group)], &a[groupNum]);
}
int numMedians = size/5;
// Index of median of medians
 MOMIdx = numMedians/2;
 select(a,numMedians,MOMIdx);
 int newMOMIdx = partition(a, size, MOMIdx) ;
 if (k != newMOMIdx)
 {
   if (k < newMOMIdx)
   {
      select(a, newMOMIdx +1 , k);
   }
   else /* if (k > newMOMIdx) */
     {
     select(a + newMOMIdx +1, size - newMOMIdx-1, k - newMOMIdx-1);
     }
 }
     }
}

//quick sort with pivot as median of medians
void quicksort(int *x,int first,int last)
{
    int pivot,j,temp,i,l,size;
    size=last-first+1;
    if (size < 5)
     {
    	for ( i=first; i<=last; i++)
	    for ( j=i+1; j<=last; j++)
		if (x[j] < x[i])
		    swap(&x[i], &x[j]);
    }

     if(size>=5)
     {
	    select(x+first,size,size/2);  //finds pivot(which is mom)
	                                  //Also shifts all the elements of the array less than pivot before the pivot element
                                      // and greater than pivot after the pivot
	    pivot=size/2+first;
  
	  quicksort(x,first,pivot-1);
     	 quicksort(x,pivot+1,last);
    } 
    
}

