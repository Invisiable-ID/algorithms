#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"public_functions.h"

#define N 1000

void shell_sort(int* array, int size)
{
		int h = 1;
		while(h<size/3)
				h = 3*h+1;
		for(int i=h; i<size; i++)
		{
				for(int j=i; j>=h; j-=h)
				{
						if(array[j]<array[j-h])
								exchange(&array[j-h], &array[i]);
				}
				h /= 3;
		}
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
		printf("-----------\n");
		shell_sort(array, N);
		for(int i=0; i<N; i++)
				printf("%d\n", array[i]);
		free(array);
		array = NULL;
		return 0;
}
