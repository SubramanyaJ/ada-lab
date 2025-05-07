#include <stdio.h>

void bubble_sort(int *arr, int n) {
	int temp;
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - 1 - i; j++) {
			if(arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
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
