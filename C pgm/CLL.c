#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node *head = NULL;
node *createnode(int val){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = val;
	return newnode;
}
void insert(int a) {
	node *newnode = createnode(a);
	if(head == NULL){
		head = newnode;
		return;
	}
	node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->prev = temp;
}

void delete(int val) {
	if(head == NULL){
		printf("\nEmpty..");
		return;
	}
	node *temp = head;
	while(temp->data != val  && temp != NULL){
		temp = temp->next;
	}
	if(temp == NULL){
		printf("Element not found..");
		return;
	}
	if(temp == head){
		head = temp->next;
		head->prev = NULL;
		free(temp);
		return;
	}
	if(temp->next == NULL){
		temp->prev->next = NULL;
		free(temp);
		return;
	}
	
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	free(temp);
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

void dispback(){
	node *temp = head;
	if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
	while(temp->next != NULL){
		temp=temp->next;
	}
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp = temp->prev;
	}	
}

int main() {
    int ch = 0, val;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4.display backwards\n7.exit\n");
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
				dispback();
				break;
			case 7:
				return 0;	
				break;
            default:
                printf("Enter a valid choice.\n");
        }
    }
}

