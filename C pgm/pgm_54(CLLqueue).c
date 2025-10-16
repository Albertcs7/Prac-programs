#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Front and rear pointers for circular queue
node *front = NULL, *rear = NULL;

// Function to insert element (Enqueue)
void enqueue(int val) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
        rear->next = front; // Make it circular
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
    printf("Element %d inserted into the circular queue.\n", val);
}

// Function to delete element (Dequeue)
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty! Nothing to delete.\n");
        return;
    }

    node *temp = front;
    if (front == rear) { // Only one node
        printf("Deleted element: %d\n", front->data);
        front = rear = NULL;
    } else {
        printf("Deleted element: %d\n", front->data);
        front = front->next;
        rear->next = front;
    }
    free(temp);
}

// Function to view the front element
void peek() {
    if (front == NULL)
        printf("Queue is empty!\n");
    else
        printf("Front element is: %d\n", front->data);
}

// Function to display all elements
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    node *temp = front;
    printf("Circular Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Main function (menu-driven)
int main() {
    int ch = 0, val;

    while (ch != 5) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
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

