#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"public_functions.h"

#define LEN 1000

void insert_sort(int* array, int size)
{
		for(int i=1; i<size; i++)
		{
				for(int j=i; j>0; j--)
				{
						if(array[j-1]>array[j])
								exchange(&array[j-1], &array[j]);
				}
		}
}

int main(void)
{
		int* array = (int*)malloc(LEN*sizeof(int));
		if(!array)
				return -1;
		srand(time(NULL));
		for(int i=0; i<LEN; i++)
		{
				array[i] = rand()%10;
				printf("%d\n", array[i]);
		}
		printf("----------\n");
		insert_sort(array, LEN);
		for(int i=0; i<LEN; i++)
				printf("%d\n", array[i]);
		free(array);
		array = NULL;
		return 0;
}
