#include <stdio.h>
#include <stdlib.h>

void mallocExample() {
    int n, i, *ptr;
    printf("\nEnter number of elements (for malloc): ");
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    printf("Memory allocated using malloc.\nEnter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &ptr[i]);
    printf("Elements entered (malloc): ");
    for (i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    printf("\n");
    free(ptr);
    printf("Memory freed (malloc block).\n");
}

void callocExample() {
    int n, i, *ptr;
    printf("\nEnter number of elements (for calloc): ");
    scanf("%d", &n);
    ptr = (int*)calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    printf("Memory allocated using calloc.\nInitial values: ");
    for (i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    printf("\nEnter %d new values:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &ptr[i]);
    printf("Elements entered (calloc): ");
    for (i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    printf("\n");
    free(ptr);
    printf("Memory freed (calloc block).\n");
}

int main() {
    int choice;
    do {
        printf("1. Demonstrate malloc()\n");
        printf("2. Demonstrate calloc()\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: mallocExample(); break;
            case 2: callocExample(); break;
            case 3: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}

