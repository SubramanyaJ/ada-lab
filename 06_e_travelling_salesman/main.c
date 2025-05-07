#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

#define MAX 10

int minCost = INT_MAX;
int bestPath[MAX];
int currentPath[MAX];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int calculateCost(int **graph, int path[], int n) {
	int cost = 0;
	for (int i = 0; i < n - 1; i++) {
		cost += graph[path[i]][path[i + 1]];
	}
	cost += graph[path[n - 1]][path[0]];
	return cost;
}

void permute(int **graph, int path[], int l, int r, int n) {
	if (l == r) {
		int cost = calculateCost(graph, path, n);
		if (cost < minCost) {
			minCost = cost;
			for (int i = 0; i < n; i++)
				bestPath[i] = path[i];
		}
		return;
	}

	for (int i = l; i <= r; i++) {
		swap(&path[l], &path[i]);
		permute(graph, path, l + 1, r, n);
		swap(&path[l], &path[i]);
	}
}

int main() {
	int n, e;
	int **graph = graph_create(&n, &e);

	for (int i = 0; i < n; i++)
		currentPath[i] = i;

	permute(graph, currentPath, 1, n - 1, n);

	printf("Minimum cost: %d\n", minCost);
	printf("Optimal tour: ");
	for (int i = 0; i < n; i++)
		printf("%d -> ", bestPath[i]);
	printf("%d\n", bestPath[0]);

	for (int i = 0; i < n; i++)
		free(graph[i]);
	free(graph);

	return 0;
}
