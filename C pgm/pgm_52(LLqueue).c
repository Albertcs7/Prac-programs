#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node *next;
} node;
// Declare global front and rear pointers
node *front = NULL, *rear = NULL;

// Function to enqueue
void enqueue(int val) {
    node *newnode = (node*)malloc(sizeof(node)); // Allocate memory
    newnode->data = val;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Element %d inserted into the queue.\n", val);
}

// Function to dequeue
void dequeue() {
    node *temp;
    if (front == NULL) {
        printf("Queue is empty! Nothing to delete.\n");
    } else {
        temp = front;
        printf("Deleted element: %d\n", temp->data);
        front = front->next;
        if (front == NULL)
            rear = NULL; // If queue becomes empty
        free(temp);
    }
}

// Function to display the front element
void peek() {
    if (front == NULL)
        printf("Queue is empty!\n");
    else
        printf("Front element is: %d\n", front->data);
}

// Function to display all elements
void display() {
    node *t = front;
    if (t == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements : ");
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

// Main function with menu-driven structure
int main() {
    int ch = 0, val;

    while (ch != 5) {
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Peek \n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

