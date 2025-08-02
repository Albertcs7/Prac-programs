#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Function to swap two elements (no pointers)
void swap(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Heapify up for insertion
void heapify_up(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[parent] < heap[index]) {
        swap(parent, index);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Heapify down for deletion
void heapify_down(int index) {
    int left, right, largest;

    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        largest = index;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == index)
            break;

        swap(index, largest);
        index = largest;
    }
}

// Insert an element into the heap
void insert(int value) {
    heap[size] = value;
    heapify_up(size);
    size++;
}

// Delete and return the max (root)
int delete_max() {
    if (size == 0)
        return -1;

    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify_down(0);

    return max;
}

// Display the heap
void display() {
	int i;
    printf("Priority Queue (Max-Heap): ");
    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Main
int main() {
    insert(50);
    insert(20);
    insert(30);
    insert(10);
    insert(60);

    display();

    printf("Deleted max: %d\n", delete_max());
    display();

    printf("Deleted max: %d\n", delete_max());
    display();

    return 0;
}

