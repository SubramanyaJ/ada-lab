#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

int minCost = INT_MAX;
int bestPerm[MAX];
int currentPerm[MAX];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int calculateCost(int cost[MAX][MAX], int perm[], int n) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += cost[i][perm[i]];
	}
	return total;
}

void permute(int cost[MAX][MAX], int perm[], int l, int r, int n) {
	if (l == r) {
		int currentCost = calculateCost(cost, perm, n);
		if (currentCost < minCost) {
			minCost = currentCost;
			for (int i = 0; i < n; i++) {
				bestPerm[i] = perm[i];
			}
		}
		return;
	}

	for (int i = l; i <= r; i++) {
		swap(&perm[l], &perm[i]);
		permute(cost, perm, l + 1, r, n);
		swap(&perm[l], &perm[i]);  // backtrack
	}
}

int main() {
	int n;
	int cost[MAX][MAX];

	printf("Enter the number of persons/jobs (n): ");
	scanf("%d", &n);

	if (n > MAX) {
		printf("Maximum supported size is %d.\n", MAX);
		return 1;
	}

	printf("Enter the %dx%d cost matrix:\n", n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		currentPerm[i] = i;
	}

	permute(cost, currentPerm, 0, n - 1, n);

	printf("Minimum cost: %d\n", minCost);
	printf("Optimal assignment (Person -> Job):\n");
	for (int i = 0; i < n; i++) {
		printf("Person %d -> Job %d\n", i + 1, bestPerm[i] + 1);
	}

	return 0;
}
