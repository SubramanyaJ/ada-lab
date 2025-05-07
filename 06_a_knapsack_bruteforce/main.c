#include <stdio.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int knap(int w[], int v[], int n, int c) {
	if (n == 0 || c == 0)
		return 0;

	if (w[n - 1] > c)
		return knap(w, v, n - 1, c);

	return max(
		v[n - 1] + knap(w, v, n - 1, c - w[n - 1]),
		knap(w, v, n - 1, c)
	);
}

int main() {
	int n, c;

	printf("Enter number of items: ");
	scanf("%d", &n);

	int w[n], v[n];

	printf("Enter weights and values of items:\n");
	for (int i = 0; i < n; i++) {
		printf("[%d]: ", i + 1);
		scanf("%d %d", &w[i], &v[i]);
	}

	printf("Enter the capacity of the knapsack: ");
	scanf("%d", &c);

	int maxV = knap(w, v, n, c);
	printf("Maximum value in knapsack of capacity %d is: %d\n", c, maxV);

	return 0;
}
