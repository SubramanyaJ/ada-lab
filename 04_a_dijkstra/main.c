#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

int min_index(int dist[], bool visited[], int n) {
	int min_in = -1, min = INT_MAX;
	for(int i = 0; i < n; i++) {
		if (!visited[i]
			&& dist[i] < min) {
			min = dist[i];
			min_in = i;
		}
	}
	return min_in;
}

void dijkstra(int **graph, int vertices, int start) {
	bool visited[vertices];
	int dist[vertices];

	for(int i = 0; i < vertices; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
	}

	dist[start] = 0;
	
	int curr;
	for(int i = 0; i < vertices - 1; i++) {
		curr = min_index(dist, visited, vertices);
		visited[curr] = true;

		for(int i = 0; i < vertices; i++) {
			if (
				!visited[i]
				&& graph[curr][i]
				&& dist[curr] != INT_MAX
				&& dist[curr] + graph[i][curr] < dist[i]
			) {
				dist[i] = dist[curr] + graph[curr][i];
			}
		}
	}

	for(int i = 0; i < vertices; i++) {
		printf("%d -> %d : %d\n", start, i, dist[i]);
	}
}

int main() {
	int vertices, edges,
	**graph = graph_create(&vertices, &edges);
	printf("Enter the starting vertex : ");
	int start;
	scanf("%d", &start);
	dijkstra(graph, vertices, start);

	graph_free(graph, vertices);

	return 0;
}
