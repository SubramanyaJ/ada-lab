#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100000

void merge(int *arr, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *L = (int *) malloc(n1 * sizeof(int));
	int *R = (int *) malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

void sortArray(int *arr, int size) {
	mergeSort(arr, 0, size - 1);
	printf("\n\n");
}

void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
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
//		printf("Given array is\n");
//		printArray(arr, size);

		start = clock();
		sortArray(arr, size);
		end = clock();

//		printf("\nSorted array is \n");
//		printArray(arr, size);
		fprintf(fp, "%d, %d\n", (int) (end - start), i);
	}
	fclose(fp);
	return 0;
}
