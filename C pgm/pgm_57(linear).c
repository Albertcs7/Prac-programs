#include <stdio.h>

// Function to input array elements
void inputArray(int arr[], int n) {
    int i;
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // Return index if found
    }
    return -1;  // Return -1 if not found
}

// Function to display search result
void displayResult(int result, int key) {
    if (result != -1)
        printf("Element %d found at position %d.\n", key, result + 1);
    else
        printf("Element %d not found in the array.\n", key);
}

int main() {
    int n, key, result;
    int arr[100];  

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    inputArray(arr, n);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);
    displayResult(result, key);

    return 0;
}

