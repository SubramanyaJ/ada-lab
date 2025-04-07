// warshall.c

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void warshall(int **graph, int vertices) {
	for(int i = 0; i < vertices; i++) {
		graph[i][i] = 1;
	}
	for(int k = 0; k < vertices; k++) {
		for(int i = 0; i < vertices; i++) {
			for(int j = 0; j < vertices; j++) {
				if(graph[i][k] && graph[k][j]) {
					graph[i][j] = 1;
				}
			}
		}
	}
}

void graph_print(int **graph, int vertices) {
	printf("\nTransitive closure : \n");
	for(int i = 0; i < vertices; i++) {
		for(int j = 0; j < vertices; j++) {
			printf("%d ", graph[i][j]);
		}	putchar('\n');
	}
	putchar('\n');
}

int
main() {
	int edges, vertices, **graph = graph_create(&vertices, &edges);
	graph_print(graph, vertices);
	warshall(graph, vertices);
	graph_print(graph, vertices);
	return 0;
}
