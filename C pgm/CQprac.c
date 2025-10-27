#include <stdio.h>
#include <stdlib.h>

int rear = -1, front = -1;

void enqueue(int a[], int val, int num) {
    if ((rear + 1) % num == front) {
        printf("Queue is full!\n");
        return;
    }

    if (front == -1) // first element
        front = 0;

    rear = (rear + 1) % num;
    a[rear] = val;
    printf("%d inserted successfully.\n", val);
}

void deq(int a[], int num) {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", a[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % num;
}

void display(int a[], int num) {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", a[i]);
        if (i == rear)
            break;
        i = (i + 1) % num;
    }
    printf("\n");
}

int main() {
    int num, choice, val;
    printf("Enter the queue size: ");
    scanf("%d", &num);
    int a[num];

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(a, val, num);
                break;
            case 2:
                deq(a, num);
                break;
            case 3:
                display(a, num);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

