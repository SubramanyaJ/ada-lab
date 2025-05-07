// graph.c
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

int **graph_create(int *vertices, int *edges) {
	printf("Enter the number of vertices and edges : ");
	scanf("%d %d", vertices, edges);
	int **arr = calloc(*vertices, sizeof(int *));
	for(int i = 0; i < *vertices; i++) {
		arr[i] = calloc(*vertices, sizeof(int));
	}
	int start, end, weight;
	printf("Enter the start vertex, end vertex, and weight : ");
	for(int i = 0; i < *edges; i++) {
		scanf("%d %d %d", &start, &end, &weight);
		arr[start][end] = arr[end][start] = weight;
	}


	return arr;
}
