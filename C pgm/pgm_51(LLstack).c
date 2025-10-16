#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;
node *top = NULL;

// Function to push an element onto the stack
void push(int val) {
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("Element %d pushed onto the stack.\n", val);
}
// Function to pop an element from the stack
void pop() {
    node *temp;
    if (top == NULL) {
        printf("Stack is empty! Nothing to pop.\n");
    } else {
        temp = top;
        printf("Popped element: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}
// Function to display all stack elements
void display() {
    node *t = top;
    if (t == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements (Top to Bottom):\n");
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}
// Function to show the top element
void peek() {
    if (top == NULL)
        printf("Stack is empty!\n");
    else
        printf("Top element is: %d\n", top->data);
}
// Function to count total elements
void count() {
    node *t = top;
    int c = 0;
    while (t != NULL) {
        c++;
        t = t->next;
    }
    printf("Total elements in stack: %d\n", c);
}

int main() {
    int ch = 0;
	int val;
    while (ch != 6) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                count();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

