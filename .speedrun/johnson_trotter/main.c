#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int direction;
} Element;

void print_permutation(Element *perm, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i].value);
    }
    printf("\n");
}

int get_largest_mobile(Element *perm, int n) {
    int largest_mobile_index = -1;
    int largest_mobile_value = -1;

    for (int i = 0; i < n; i++) {
        int dir = perm[i].direction;
        int adj = i + dir;

        if (adj >= 0 && adj < n && perm[i].value > perm[adj].value) {
            if (perm[i].value > largest_mobile_value) {
                largest_mobile_value = perm[i].value;
                largest_mobile_index = i;
            }
        }
    }

    return largest_mobile_index;
}

void reverse_directions(Element *perm, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (perm[i].value > value) {
            perm[i].direction *= -1;
        }
    }
}

void johnson_trotter(int n) {
    Element *perm = malloc(n * sizeof(Element));
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].direction = LEFT;
    }

    print_permutation(perm, n);

    while (1) {
        int mobile_index = get_largest_mobile(perm, n);
        if (mobile_index == -1) break;

        int dir = perm[mobile_index].direction;
        int swap_index = mobile_index + dir;

        Element temp = perm[mobile_index];
        perm[mobile_index] = perm[swap_index];
        perm[swap_index] = temp;

        reverse_directions(perm, n, perm[swap_index].value);

        print_permutation(perm, n);
    }

    free(perm);
}

int main() {
    int n;
    printf("Enter the number of elements to permute: ");
    scanf("%d", &n);
    johnson_trotter(n);
    return 0;
}
