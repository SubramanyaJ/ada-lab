#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100000

void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int *) malloc(n1 * sizeof(int));
    int *R = (int *) malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    free(L);
    free(R);
}

// Main function that implements Merge Sort
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Wrapper function to call mergeSort
void sortArray(int *arr, int size) {
    mergeSort(arr, 0, size - 1);
}

// Function to print an array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Example usage
int main() {
    int max = MAX;
    clock_t start, end;
    FILE *fp = fopen("data.txt", "w");
    for(int i = 1; i <= max; i++) {
      //  printf("%d elements\n", i);
        int *arr, size = max;
        // printf("Enter the size of the array : ");
        // scanf("%d", &size);
        arr = malloc(size*sizeof(int));

    //    printf("Enter the elements : \n");
        for(int i = 0; i < size; i++) {
            // scanf("%d", &arr[i]);
            arr[i] = rand();
        }

  //      printf("Given array is \n");
//        printArray(arr, size);

        start = clock();
        sortArray(arr, size);
        end = clock();

//        printf("\nSorted array is \n");
//        printArray(arr, size);
        fprintf(fp, "%d, %d\n", i, (int) (end - start));
    }
    fclose(fp);
    return 0;
}
