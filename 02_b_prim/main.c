// prim.c
#include "graph.h"
#include <stdio.h>
#include <limits.h>

int minKey(int key[], int mstSet[], int vertices) {
	int min = INT_MAX, min_index;
	for (int v = 0; v < vertices; v++) {
		if (!mstSet[v] && key[v] < min) {
			min = key[v], min_index = v;
		}
	}
	return min_index;
}

void primMST(int **graph, int vertices) {
	int parent[vertices];  // Stores constructed MST
	int key[vertices];     // Used to pick minimum weight edge
	int mstSet[vertices];  // To represent set of vertices included in MST

	for (int i = 0; i < vertices; i++) {
		key[i] = INT_MAX;
		mstSet[i] = 0;
	}

	key[0] = 0;      // First vertex is picked first
	parent[0] = -1;  // First node is always the root

	for (int count = 0; count < vertices - 1; count++) {
		int u = minKey(key, mstSet, vertices);
		mstSet[u] = 1;

		for (int v = 0; v < vertices; v++) {
			if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
				parent[v] = u, key[v] = graph[u][v];
			}
		}
	}

	printf("\nEdge \tWeight\n");
	for (int i = 1; i < vertices; i++) {
		printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
	}
}

int main() {
	int edges, vertices, **graph = graph_create(&vertices, &edges);
	primMST(graph, vertices);
	return 0;
}
