#include <stdio.h>
#include <string.h>

int BruteForceStringMatch(char T[], char P[]) {
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
	char text[1000], pattern[1000];

	printf("Enter the text: ");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")] = '\0';

	printf("Enter the pattern to search: ");
	fgets(pattern, sizeof(pattern), stdin);
	pattern[strcspn(pattern, "\n")] = '\0';

	int index = BruteForceStringMatch(text, pattern);

	if (index != -1)
		printf("Pattern found at index %d\n", index);
	else
		printf("Pattern not found.\n");

	return 0;
}
