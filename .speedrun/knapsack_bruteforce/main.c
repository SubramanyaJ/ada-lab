#include <stdio.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int knapsackBruteForce(int weights[], int values[], int n, int capacity) {
	if (n == 0 || capacity == 0)
		return 0;

	if (weights[n - 1] > capacity)
		return knapsackBruteForce(weights, values, n - 1, capacity);

	return max(
		values[n - 1] + knapsackBruteForce(weights, values, n - 1, capacity - weights[n - 1]),
		knapsackBruteForce(weights, values, n - 1, capacity)
	);
}

int main() {
	int n, capacity;

	printf("Enter number of items: ");
	scanf("%d", &n);

	int weights[n], values[n];

	printf("Enter weights and values of items:\n");
	for (int i = 0; i < n; i++) {
		printf("[%d]: ", i + 1);
		scanf("%d %d", &weights[i], &values[i]);
	}

	printf("Enter the capacity of the knapsack: ");
	scanf("%d", &capacity);

	int maxValue = knapsackBruteForce(weights, values, n, capacity);
	printf("Maximum value in knapsack of capacity %d is: %d\n", capacity, maxValue);

	return 0;
}
