#include <stdio.h>
int front = -1, rear = -1, count = 0;

//function to enqueue into queue
void enq(int q[], int n, int s) {
    if ((rear + 1) % n == front) {
        printf("\nQueue is full!");
        return;
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % n;
        q[rear] = s;
        count++;
        printf("\n%d inserted into queue.", s);
    }
}

//function to dequeue from queue
void deq(int q[], int n) {
    if (front == -1) {
        printf("\nQueue is empty!");
        return;
    } else {
        printf("\nDequeued element: %d", q[front]);
        count--;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % n;
    }
}

//function to display the queue elements
void dis(int q[], int n) {
    if (front == -1) {
        printf("\nQueue is empty!");
        return;
    }
    printf("\nQueue elements are:\n");
    int i = front;
    while (1) {
        printf("%d\t", q[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
    printf("\n");
}

//function to print menu
int menu() {
    int ch;
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter a choice: ");
    scanf("%d", &ch);
    return ch;
}

// Process control function
void aprocess(int q[], int n) {
    int ch, s;
    for (ch = menu(); ch != 4; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &s);
                enq(q, n, s);
                break;
            case 2:
                deq(q, n);
                break;
            case 3:
                dis(q, n);
                break;
            default:
                printf("Enter a valid choice!");
        }
    }
}

//main function
int main() {
    int n;
    printf("Enter size of Queue: ");
    scanf("%d", &n);
    int que[n];
    aprocess(que, n);
    return 0;
}

