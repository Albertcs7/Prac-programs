#include <stdio.h>

#define MAX 100

int value[MAX];
int priority[MAX];
int size = 0;

// Function to insert element
void enqueue(int val, int pr) {
    if (size == MAX) {
        printf("Priority Queue is full!\n");
        return;
    }
    value[size] = val;
    priority[size] = pr;
    size++;
    printf("Inserted: value=%d priority=%d\n", val, pr);
}

// Function to find the index of highest priority element
int getHighestPriorityIndex() {
    int highest = 0,i;
    for ( i = 1; i < size; i++) {
        if (priority[i] > priority[highest])
            highest = i;
    }
    return highest;
}

// Function to delete highest priority element
void dequeue() {
	int i;
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    int index = getHighestPriorityIndex();
    printf("Deleted: value=%d priority=%d\n", value[index], priority[index]);

    // Shift all elements after index
    for ( i = index; i < size - 1; i++) {
        value[i] = value[i + 1];
        priority[i] = priority[i + 1];
    }
    size--;
}

// Function to display all elements
void display() {
	int i;
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("\nPriority Queue Elements:\n");
    for ( i = 0; i < size; i++) {
        printf("Value: %d  Priority: %d\n", value[i], priority[i]);
    }
}

int main() {
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(3, 1);
    enqueue(8, 3);

    display();

    dequeue();
    display();

    return 0;
}
