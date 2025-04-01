#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE *fp = fopen("data.txt", "w");
	int max = atoi(argv[1]);
	printf("%d\n", max);
	fprintf(fp, "%d\n", max);
	// for(int j = 0; j < max; j++) {
	fprintf(fp, "%d\n", rand());
}
}
