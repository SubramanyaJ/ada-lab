#include <stdio.h>
#include <limits.h>
#include "graph.h"

void floyd(int **graph, int vertices) {
	// Initialize: Convert 0s to INT_MAX, but not the diagonal
	for(int i = 0; i < vertices; i++) {
		for(int j = 0; j < vertices; j++) {
			if(i != j && graph[i][j] == 0) {
				graph[i][j] = INT_MAX;
			}
		}
	}

	// Floyd–Warshall core logic
	for(int k = 0; k < vertices; k++) {
		for(int i = 0; i < vertices; i++) {
			for(int j = 0; j < vertices; j++) {
				if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX &&
					graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

void graph_print(int **graph, int vertices) {
	printf("\nDistance Matrix:\n");
	for(int i = 0; i < vertices; i++) {
		for(int j = 0; j < vertices; j++) {
			if (graph[i][j] == INT_MAX)
				printf("INF\t");
			else
				printf("%d\t", graph[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}

int main() {
	int edges, vertices;
	int **graph = graph_create(&vertices, &edges);
	printf("\nOriginal Graph:\n");
	graph_print(graph, vertices);
	floyd(graph, vertices);
	printf("\nAfter Floyd's Algorithm:\n");
	graph_print(graph, vertices);
	return 0;
}
