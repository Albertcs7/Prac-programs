#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
typedef struct node {
    char data[50];
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;

// Function to insert at beginning
void insert_begin(char val[]) {
    node *newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->data, val);

    if (head == NULL) {
        head = newnode;
        newnode->next = newnode->prev = head;
    } else {
        node *tail = head->prev;
        newnode->next = head;
        newnode->prev = tail;
        tail->next = head->prev = newnode;
        head = newnode;
    }
    printf("Inserted '%s' at beginning.\n", val);
}

// Function to insert at end
void insert_end(char val[]) {
    node *newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->data, val);

    if (head == NULL) {
        head = newnode;
        newnode->next = newnode->prev = head;
    } else {
        node *tail = head->prev;
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
    }
    printf("Inserted '%s' at end.\n", val);
}

// Function to delete a node with specific string
void delete_node(char val[]) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head, *found = NULL;
    do {
        if (strcmp(temp->data, val) == 0) {
            found = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (found == NULL) {
        printf("Element '%s' not found!\n", val);
        return;
    }

    if (found->next == found) { // Only one node
        head = NULL;
    } else {
        found->prev->next = found->next;
        found->next->prev = found->prev;
        if (found == head)
            head = found->next;
    }
    free(found);
    printf("Deleted '%s' from list.\n", val);
}

// Function to display list forward
void display_forward() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head;
    printf("CDLL (Forward): ");
    do {
        printf("%s ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to display list backward
void display_backward() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head->prev;
    node *tail = temp;
    printf("CDLL (Backward): ");
    do {
        printf("%s ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("\n");
}

// Main function (menu-driven)
int main() {
    int ch;
    char val[50];

    while (1) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display Forward\n");
        printf("5. Display Backward\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar(); // Consume newline after scanf

        switch (ch) {
            case 1:
                printf("Enter string to insert: ");
                fgets(val, sizeof(val), stdin);
                val[strcspn(val, "\n")] = '\0'; // Remove newline
                insert_begin(val);
                break;
            case 2:
                printf("Enter string to insert: ");
                fgets(val, sizeof(val), stdin);
                val[strcspn(val, "\n")] = '\0';
                insert_end(val);
                break;
            case 3:
                printf("Enter string to delete: ");
                fgets(val, sizeof(val), stdin);
                val[strcspn(val, "\n")] = '\0';
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

