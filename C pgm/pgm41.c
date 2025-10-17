#include <stdio.h>
#include <stdlib.h>

// Function to read elements and return pointer
int* enterElements(int *n) {
    int i;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", n);

    arr = (int*)malloc((*n) * sizeof(int)); // allocate memory
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        return NULL;
    }

    printf("Enter %d integers:\n", *n);
    for (i = 0; i < *n; i++)
        scanf("%d", &arr[i]);

    return arr;
}

// Function to calculate and display mean
void calculateMean(int *arr, int n) {
    int i;
    float sum = 0, mean;

    for (i = 0; i < n; i++)
        sum += arr[i];

    mean = sum / n;
    printf("Mean = %.2f\n", mean);
}

int main() {
    int n;
    int *arr = enterElements(&n);

    if (arr != NULL) {
        calculateMean(arr, n);
        free(arr); // free memory
    }

    return 0;
}

