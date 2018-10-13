#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void makeRandomArray(int* a, int size); 
void swap(int*, int*);
int median5(int *a);
int partition(int *a, int size, int pivot);
void select(int *a, int size, int k);
void quicksort(int *x,int first,int last);
