#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int *arr, int n) {
	int temp;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; i++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return;
}

int main() {
	int n;

	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];

	printf("Enter %d integers:\n", n);
	for(int i = 0; i < n; i++) {
		printf("[%d]: ", i + 1);
		scanf("%d", &arr[i]);
	}

	bubble_sort(arr, n);

	printf("Sorted array:\n");
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
