#include <stdio.h>
#include <stdlib.h>

#define L -1
#define R 1

typedef struct { int v, d; } E;

void p(E *a, int n) {
	for (int i = 0; i < n; i++) printf("%d ", a[i].v);
	printf("\n");
}

int lm(E *a, int n) {
	int m = -1, lv = -1;
	for (int i = 0; i < n; i++) {
		int adj = i + a[i].d;
		if (adj >= 0 && adj < n && a[i].v > a[adj].v && a[i].v > lv) {
			lv = a[i].v;
			m = i;
		}
	}
	return m;
}

void rd(E *a, int n, int v) {
	for (int i = 0; i < n; i++) if (a[i].v > v) a[i].d *= -1;
}

void jt(int n) {
	E *a = malloc(n * sizeof(E));
	for (int i = 0; i < n; i++) { a[i].v = i + 1; a[i].d = L; }
	p(a, n);

	while (1) {
		int idx = lm(a, n);
		if (idx == -1) break;
		int d = a[idx].d, si = idx + d;
		E t = a[idx]; a[idx] = a[si]; a[si] = t;
		rd(a, n, a[si].v);
		p(a, n);
	}

	free(a);
}

int main() {
	int n; 
	printf("Enter the number of elements to permute: "); 
	scanf("%d", &n); 
	jt(n); 
	return 0; 
}
