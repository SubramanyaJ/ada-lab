/**
 * Algorithm :
 * function fractionalKnapsack(W, value[], weight[], n):
    items = []
    for i from 0 to n-1:
        ratio = value[i] / weight[i]
        items.append((ratio, value[i], weight[i]))

    sort items by ratio descending

    totalValue = 0.0
    for each (ratio, val, wt) in items:
        if W >= wt:
            totalValue += val
            W -= wt
        else:
            totalValue += ratio * W
            break

    return totalValue
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Item {
	int weight;
	int value;
	float ratio;
};

int itemcmp(const void *x, const void *y) {
	float ret = ((struct Item *) x )->ratio - ((struct Item *) y)->ratio;
	if(ret > 0) {return -1;}
	if(ret < 0) {return 1;}
	return 0;
}

struct Item *get_items(int *n) {
	printf("Enter the number of items : ");
	scanf("%d", n);
	
	struct Item *arr = calloc(*n, sizeof(struct Item));

	printf("Enter the weight and value of each item : \n");
	for(int i = 0; i < *n; i++) {
		printf("Item %d : ", i);
		scanf("%d %d", &arr[i].weight, &arr[i].value);
		arr[i].ratio = (float) arr[i].value / arr[i].weight;
	}
	qsort(arr, *n, sizeof(struct Item), itemcmp);
	return arr;
}

float calculate_max(struct Item *arr, int n, int max) {
	float total = 0;
	for(int i = 0; i < n; i++) {
		if(max == 0) {
			break;
		}
		else if(arr[i].weight < max) {
			total += arr[i].value;
			max -= arr[i].weight;
		}
		else if(arr[i].weight > max) {
			total += arr[i].ratio * max;
			break;
		}
	}
	return total;
}

int main() {
	int n, max;
	printf("Enter the maximum capacity : ");
	scanf("%d", &max);
	struct Item * arr = get_items(&n);
	float max_val = calculate_max(arr, n, max);
	printf("Maximum value : %f\n", max_val);

	free(arr);

	return 0;
}
