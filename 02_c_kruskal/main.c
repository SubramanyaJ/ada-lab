// kruskal.c
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

struct Edge {
	int src, dest, weight;
};

struct subset {
	int parent;
	int rank;
};

int find(struct subset subsets[], int i) {
	if (subsets[i].parent != i) {
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank) {
		subsets[xroot].parent = yroot;
	} else if (subsets[xroot].rank > subsets[yroot].rank) {
		subsets[yroot].parent = xroot;
	} else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int compare(const void *a, const void *b) {
	struct Edge *a1 = (struct Edge *) a;
	struct Edge *b1 = (struct Edge *) b;
	return a1->weight - b1->weight;
}

void kruskalMST(int **graph, int vertices) {
	int edgeCount = 0;
	struct Edge result[vertices];

	struct Edge *edges = malloc(vertices * vertices * sizeof(struct Edge));
	int edgeIndex = 0;
	for (int i = 0; i < vertices; i++) {
		for (int j = i + 1; j < vertices; j++) {
			if (graph[i][j] != 0) {
				edges[edgeIndex].src = i;
				edges[edgeIndex].dest = j;
				edges[edgeIndex].weight = graph[i][j];
				edgeIndex++;
			}
		}
	}

	qsort(edges, edgeIndex, sizeof(edges[0]), compare);

	struct subset *subsets = malloc(vertices * sizeof(struct subset));
	for (int v = 0; v < vertices; v++) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	for (int i = 0; i < edgeIndex; i++) {
		int x = find(subsets, edges[i].src);
		int y = find(subsets, edges[i].dest);

		if (x != y) {
			result[edgeCount++] = edges[i];
			Union(subsets, x, y);
		}
	}

	printf("\nEdge \tWeight\n");
	for (int i = 0; i < edgeCount; i++) {
		printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
	}

	free(edges);
	free(subsets);
}

int main() {
	int edges, vertices, **graph = graph_create(&vertices, &edges);
	kruskalMST(graph, vertices);
	return 0;
}
