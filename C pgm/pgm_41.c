#include <stdio.h>
#include <stdlib.h>  // for calloc and free

void enterElements(int arr[], int n) {
    int i;
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void findMode(int arr[], int n) {
    int i, j, mode = arr[0], maxCount = 0, count;
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    printf("\nMode = %d (appears %d times)\n", mode, maxCount);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamic allocation using calloc
    int *arr = (int*)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    enterElements(arr, n);
    findMode(arr, n);

    free(arr); // Free allocated memory
    return 0;
}

