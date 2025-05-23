// quick_sort.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

void quick_sort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void swap(int *a, int *b);
int temp;

void quick_sort(int *arr, int low, int high) {
	if(low >= high) {
		return;
	}
	int p_index = partition(arr, low, high);
	quick_sort(arr, low, p_index - 1);
	quick_sort(arr, p_index + 1, high);
}

int partition(int *arr, int low, int high) {
	int pivot = arr[(low + (high - low) / 2)];
	int i = low - 1;
	for(int j = low; j < high; j++) {
		if(arr[j] <= pivot) {
			swap(&arr[++i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i + 1;
}

void swap(int *a, int *b) {
	temp = *a;
	*a = *b;
	*b = temp;
}

void display_array(int *arr, int size) {
	putchar('\n');
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int main() {
	int max = MAX;
	clock_t start, end;
	FILE *fp = fopen("data.txt", "w");
	for(int i = 1; i <= max; i++) {
//		printf("%d elements\n", i);
		int *arr, size = i;
//		printf("Enter the size of the array : ");
//		scanf("%d", &size);
		arr = malloc(size*sizeof(int));

//		printf("Enter the elements : \n");
		for(int j = 0; j < size; j++) {
//			scanf("%d", &arr[j]);
			arr[j] = rand();
		}

//		printf("\n------------------------------------\n\nSize : %d\n", i);
		printf("Given array is\n");
		display_array(arr, size);

		start = clock();
		quick_sort(arr, 0, size-1);
		end = clock();

		printf("\nSorted array is \n");
		display_array(arr, size);
		fprintf(fp, "%d, %d\n", (int) (end - start), i);
	}
	fclose(fp);
	return 0;
}
