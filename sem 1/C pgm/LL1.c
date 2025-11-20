#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *head = NULL;

// Insert a new element at the end
void insert(int a) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = a;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode; // first node
    } else {
        node *t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = newnode;
    }
    printf("Inserted %d successfully.\n", a);
}

// Delete first occurrence of a value
void delete(int val) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = head, *prev = NULL;

    // If head is to be deleted
    if (head->data == val) {
        head = head->next;
        free(temp);
        printf("Deleted %d successfully.\n", val);
        return;
    }

    // Search for the value
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", val);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d successfully.\n", val);
}

// Display all elements
void display() {
    node *t = head;
    if (t == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void rev(){
	node *curr,*prev = NULL,*nxt = NULL;
	curr = head;
	while(curr != NULL){
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}	
	head = prev;
	display();
}

void sortByVal(){
	node *i,*j;
	for(i = head; i->next != NULL ;i=i->next){
		for(j = head ; j->next != NULL ; j= j->next){
			if(j->data > j->next->data){
				int temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}
}

void sortByAdd(){
	;
}

int main() {
    int ch = 0, val;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. reverse\n5.sort by address\n6.sort by value\n7.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &val);
                delete(val);
                break;

            case 3:
                display();
                break;

            case 4:
            	rev();
            	break;
			case 5:
				sortByAdd();
				break;
			case 6:
				sortByVal();
				break;
			case 7:
				return 0;	
				break;
            default:
                printf("Enter a valid choice.\n");
        }
    }
}

