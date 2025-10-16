#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

// Function to insert at beginning
void insert_begin(int val) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;

    if (head == NULL) {
        head = newnode;
        head->next = head; // Points to itself
    } else {
        node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    printf("Inserted %d at beginning.\n", val);
}

// Function to insert at end
void insert_end(int val) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;

    if (head == NULL) {
        head = newnode;
        head->next = head;
    } else {
        node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
    printf("Inserted %d at end.\n", val);
}

// Function to delete a specific element
void delete_node(int val) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *curr = head, *prev = NULL;

    // If node to be deleted is head
    if (head->data == val) {
        node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        if (head->next == head) { // Only one node
            free(head);
            head = NULL;
        } else {
            temp->next = head->next;
            head = head->next;
            free(curr);
        }
        printf("Deleted %d from list.\n", val);
        return;
    }

    // Search for the node
    prev = head;
    curr = head->next;
    while (curr != head && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head)
        printf("Element %d not found!\n", val);
    else {
        prev->next = curr->next;
        free(curr);
        printf("Deleted %d from list.\n", val);
    }
}

// Function to display all elements
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function (menu-driven)
int main() {
    int ch, val;
    while (1) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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

