#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"public_functions.h"

void quicksort(int* array, int left, int right)
{
		if(!array || left>=right)
				return;
		int i = left, j = right;
		int key = array[left];
		/*ATTENTION: we must consider a problem: array[i] = array[j] = key. This can probably make the WHILE run forever*/
		while(i<j)
		{
				while(i<j && array[j]>=key)
						j--;
				/*if array[j]<=key, <-*/
				array[i] = array[j];
				while(i<j && array[i]<key)
						i++;
				/*if array[left]>=key, ->*/
				array[j] = array[i];
		}
		/*move element KEY correctly*/
		array[i] = key;
		/*sort the left part of the array*/
		quicksort(array, left, i-1);
		/*sort the right part of the array*/
		quicksort(array, i+1, right);
}

int main(void)
{
		const int n = 1000;
		int* array = (int*)malloc(n*sizeof(int));
		if(!array)
				return -1;
		srand(time(NULL));
		for(int i=0; i<n; i++)
		{
				array[i] = rand()%10;
				printf("%d\n", array[i]);
		}
		printf("----------\n");
		int left = 0, right = n-1;
		quicksort(array, left, right);
		for(int i=0; i<n; i++)
				printf("%d\n", array[i]);
		free(array);
		array = NULL;
		return 0;
}
