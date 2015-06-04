#include <stdio.h > 
#include <stdlib.h > 

/* c program for heap sorting method*/

void manage(int *, int);
void heapsort(int *, int, int);

void manage(int *arr, int i)
{
	int tmp;
	tmp = arr[i];
	while ((i > 1) && (arr[i / 2] < tmp)) {
		arr[i] = arr[i / 2];
		i = i / 2;
	}
	arr[i] = tmp;
}


void heapsort(int *arr, int i, int size)
{
	int tmp, j;
	tmp = arr[i];
	j = i * 2;

	while (j <= size)  {
		if ((j < size) && (arr[j] <  arr[j + 1]))
			j++;
		if (arr[j] < arr[j / 2])
			break;
		arr[j / 2] = arr[j];
		j = j * 2;
	}
	arr[j / 2] = tmp;
}

#define NDATA 20

int main()
{
	int arr[NDATA + 1];
	int i, j, size, tmp, k;
	size = NDATA;
	j = size;

	for (i = 1; i <= NDATA; i++) {
		arr[i] = rand() % 100;
	}

	for (i = 1; i <= j; i++) {
		tmp = arr[1];
		arr[1] = arr[size];
		arr[size] = tmp;
		size--;
		heapsort(arr, 1, size);

	}

	size = j;
	for (i = 1; i <= size; i++)
		printf("%d ", arr[i]);

	return 0;
}