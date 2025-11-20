#include <stdio.h>
#define max 20

int a[max];

void heapify(int n, int i) {
    int temp;
    int larg = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[larg])
        larg = left;

    if (right < n && a[right] > a[larg])
        larg = right;

    if (larg != i) {
        temp = a[i];
        a[i] = a[larg];
        a[larg] = temp;
        heapify(n, larg);
    }
}

void heapsort(int n) {
    int i;

    // Build max heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    // Extract elements one by one
    for (i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(i, 0);
    }
}

void display(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nOriginal array: ");
    display(n);

    heapsort(n);

    printf("Sorted array: ");
    display(n);

    return 0;
}

