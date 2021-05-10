/*about mergesort, first merge and next sort*/
/*the mergesort need an assistant array*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 1000

void merge(int* array, int left, int mid, int right)
{
		if(!array || left>=right)
				return;
		int* temp = (int*)malloc(LEN*sizeof(int));
		if(!temp)
				return;
		int i = left, j = mid+1;
		int k = 0;
		while(i<=mid && j<=right)
		{
				if(array[i]<array[j])
						temp[k++] = array[i++];
				else
						temp[k++] = array[j++];
		}
		if(i == mid+1)
		{
				while(j<=right)
						temp[k++] = array[j++];
		}
		if(j == right+1)
		{
				while(i<=mid)
						temp[k++] = array[i++];
		}
		/*copy the assistant array into the old array*/
		for(int i=left, j=0; j<k; i++, j++)
				array[i] = temp[j];
		free(temp);
		temp = NULL;
}

void mergesort(int* array, int left, int right)
{
		if(!array || left>=right)
				return;
		/*get the mid number*/
		int mid = (left&right)+((left^right)>>1);
		/*sort the left part*/
		mergesort(array, left, mid);
		/*sort the right part*/
		mergesort(array, mid+1, right);
		/*merge at the end of the program*/
		merge(array, left, mid, right);
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
		int start = 0, end = LEN-1;
		mergesort(array, start, end);
		printf("-----------\n");
		/*sort code*/
		for(int i=0; i<LEN; i++)
				printf("%d\n", array[i]);
		free(array);
		array = NULL;
		return 0;
}
