#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    struct node *next;
} node;
node *head = NULL;
// Function to insert a name
void insert(char n[]) {
    node *t, *newnode;
    newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->name, n);
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else {
        t = head;
        while (t->next)
            t = t->next;
        t->next = newnode;
    }
    printf("Name inserted successfully.\n");
}

// Function to display all names
void display() {
    node *t = head;
    if (t == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("\nNames in the list:\n");
    while (t) {
        printf("%s\n", t->name);
        t = t->next;
    }
}

// Function to delete a name
void deleteName(char n[]) {
    node *t, *temp;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (strcmp(head->name, n) == 0) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Name deleted successfully.\n");
        return;
    }

    t = head;
    while (t->next && strcmp(t->next->name, n) != 0)
        t = t->next;

    if (t->next == NULL)
        printf("Name not found!\n");
    else {
        temp = t->next;
        t->next = t->next->next;
        free(temp);
        printf("Name deleted successfully.\n");
    }
}

// Function to count total names
void count() {
    node *t = head;
    int c = 0;
    while (t) {
        c++;
        t = t->next;
    }
    printf("Total names in the list: %d\n", c);
}

// Function to sort names alphabetically
void sort() {
    node *i, *j;
    char temp[50];
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(temp, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp);
            }
        }
    }
    printf("List sorted successfully.\n");
}

// Function to reverse the linked list
void reverse() {
    node *prev = NULL, *curr = head, *next = NULL;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully.\n");
}

int main() {
    char n[50];
	int ch = 0;
    while (ch != 7){
        printf("1. Insert Name\n");
        printf("2. Delete Name\n");
        printf("3. Display Names\n");
        printf("4. Sort Names\n");
        printf("5. Reverse List\n");
        printf("6. Count Names\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar(); // to consume newline after number input

        switch (ch) {
            case 1:
                printf("Enter name to insert: ");
                gets(n);
                insert(n);
                break;

            case 2:
                printf("Enter name to delete: ");
                gets(n);
                deleteName(n);
                break;

            case 3:
                display();
                break;

            case 4:
                sort();
                break;

            case 5:
                reverse();
                break;

            case 6:
                count();
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

