#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"public_functions.h"

#define N 1000

void select_sort(int* array, int size)
{
		for(int i=0; i<size-1; i++)
				for(int j=i+1; j<size; j++)
						if(array[i]>array[j])
								exchange(&array[i], &array[j]);
}

int main(void)
{
		int* array = (int*)malloc(N*sizeof(int));
		if(!array)
				return -1;
		srand(time(NULL));
		for(int i=0; i<N; i++)
		{
				array[i] = rand()%10;
				printf("%d\n", array[i]);
		}
		printf("--------\n");
		select_sort(array, N);
		for(int i=0; i<N; i++)
				printf("%d\n", array[i]);
		free(array);
		array = NULL;
		return 0;
}
