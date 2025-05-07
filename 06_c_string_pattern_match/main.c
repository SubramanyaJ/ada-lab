#include <stdio.h>
#include <string.h>

int BFSM(char T[], char P[]) {
	int n = strlen(T);
	int m = strlen(P);

	for (int i = 0; i <= n - m; i++) {
		int j = 0;
		while (j < m && P[j] == T[i + j]) {
			j++;
		}
		if (j == m) {
			return i;
		}
	}
	return -1;
}

int main() {
	char t[1000], p[1000];

	printf("Enter the text: ");
	fgets(t, sizeof(t), stdin);
	t[strcspn(t, "\n")] = '\0';

	printf("Enter the pattern to search: ");
	fgets(p, sizeof(p), stdin);
	p[strcspn(p, "\n")] = '\0';

	int idx = BFSM(t, p);

	if (idx != -1)
		printf("Pattern found at index %d\n", idx);
	else
		printf("Pattern not found.\n");

	return 0;
}
