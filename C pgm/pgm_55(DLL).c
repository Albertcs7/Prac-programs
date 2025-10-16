#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL, *tail = NULL;

// Function to insert at beginning
void insert_begin(int val) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = head;

    if (head == NULL)
        tail = newnode; 
    else
        head->prev = newnode;

    head = newnode;
    printf("Inserted %d at beginning.\n", val);
}

// Function to insert at end
void insert_end(int val) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = tail;

    if (tail == NULL)
        head = newnode;
    else
        tail->next = newnode;

    tail = newnode;
    printf("Inserted %d at end.\n", val);
}

// Function to delete a node
void delete_node(int val) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head;
    while (temp && temp->data != val)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element %d not found!\n", val);
        return;
    }

    if (temp == head && temp == tail) {
        head = tail = NULL;
    } else if (temp == head) {
        head = head->next;
        head->prev = NULL;
    } else if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted %d from list.\n", val);
}

// Function to display from beginning to end
void display_forward() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head;
    printf("Doubly Linked List (Forward): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display from end to beginning
void display_backward() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = tail;
    printf("Doubly Linked List (Backward): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function (menu-driven)
int main() {
    int ch = 0, val;

    while (ch != 6) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display Forward\n");
        printf("5. Display Backward\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_begin(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete_node(val);
                break;
            case 4:
                display_forward();
                break;
            case 5:
                display_backward();
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

