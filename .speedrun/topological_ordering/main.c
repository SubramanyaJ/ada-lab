#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define MAX 100

void topological_sort(int **adj, int n) {
	int in_degree[MAX] = {0};
	int *order = malloc(n * sizeof(int));
	int index = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (adj[i][j] != 0)
				in_degree[j]++;

	int stack[MAX], top = -1;
	for (int i = 0; i < n; i++)
		if (in_degree[i] == 0)
			stack[++top] = i;

	while (top != -1) {
		int u = stack[top--];
		order[index++] = u;

		for (int v = 0; v < n; v++) {
			if (adj[u][v] != 0) {
				in_degree[v]--;
				if (in_degree[v] == 0)
					stack[++top] = v;
			}
		}
	}

	if (index != n) {
		printf("Cycle detected. Topological sorting not possible.\n");
	} else {
		printf("Topological order: ");
		for (int i = 0; i < n; i++)
			printf("%d ", order[i]);
		printf("\n");
	}

	free(order);
}

int main() {
	int n, e;
	int **graph = graph_create(&n, &e);
	topological_sort(graph, n);

	for (int i = 0; i < n; i++)
		free(graph[i]);
	free(graph);

	return 0;
}
