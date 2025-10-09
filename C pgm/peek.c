#include <stdio.h>
#define s 5

int a[s], top = -1;

// Function to push into stack
void push(int e) {
    if (top + 1 == s) {
        printf("Stack Overflow...\n");
    } else {
        a[++top] = e;
    }
}

// Function to pop from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow...\n");
        return -1;  // Sentinel value indicating underflow
    } else {
        return a[top--];
    }
}

// New peek function: returns top element without removing it
int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;  // Sentinel value indicating stack is empty
    } else {
        return a[top];
    }
}

// Function to display stack elements
void disp() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (i = 0; i <= top; i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
}

// Menu function
void menu() {
    char ch = 'y';
    int opt, p, poppedElement, topElement;

    while (ch == 'y') {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the number to push: ");
                scanf("%d", &p);
                push(p);
                break;
            case 2:
                poppedElement = pop();
                if (poppedElement != -1) {
                    printf("Popped element: %d\n", poppedElement);
                }
                break;
            case 3:
                disp();
                break;
            case 4:
                topElement = peek();
                if (topElement != -1) {
                    printf("Top element is: %d\n", topElement);
                }
                break;
            case 5:
                ch = 'n';  // Exit loop
                break;
            default:
                printf("Enter valid option\n");
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}

