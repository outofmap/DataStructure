#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<time.h>

int intcomp(const void* x, const void* y){
	int* xx = (int*)x;
	int* yy = (int*)y;

	return *xx - *yy;
}

//int floatcomp(const void* x, const void* y){
//	float* xx = (float*)x;
//	float* yy = (float*)y;
//
//	return *xx - *yy < 0? -1: *xx - *yy > 0 ? 1:0;
//}

void swap(int w[], int a, int b)
{
	int temp = 0;

	temp = w[a];
	w[a] = w[b];
	w[b] = temp;

}

void myqsort(int w[], int start, int end)
{
	int x = w[start];
	int p = start + 1;
	int q = end;
	//printf("xxx %d %d\n", start, end);

	if(start < end){
		while (p < q) {

			while (w[p] <= x && p < end){
				p++;
			}
			while (w[q] > x){
				q--;
			}

			if (p < q)
				swap(w, p, q);
		}

		if (w[start]>w[q])
			swap(w, start, q);
		//printf("%d %d\n", p, q);

		myqsort(w, start, q - 1);
		myqsort(w, q+1, end);
	}

}


main()
{
	int w[] = { 83,86,77,15,93,35,86,92,49,21 };
	int n = sizeof(w) / sizeof(w[0]);

	int i;

	myqsort(w, 0, n - 1);
	for(i = 0; i < n; i++){
		printf("%d\n", w[i]);
	}
	printf("\n");

}