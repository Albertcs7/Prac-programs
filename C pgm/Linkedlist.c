#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node node;

node *head = NULL;
node* creNode(int val){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = val;
	newnode->next = NULL;
	return newnode;
}
void insertAtBeg(int val){
	node *newnode = creNode(val);
	if(head == NULL){
		head = newnode;
		return;
	}
	else{
		newnode->next = head;
		head = newnode;
	}
}

void insertAtEnd(int val){
	node *newnode = creNode(val);
	if(head == NULL){
		head = newnode;
		return;	
	}
	node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode;
}

void insertAtSpec(int val, int pos){
	if(head == NULL){
		printf("no value in list..");
		return;
	}
	node *temp = head;
	while(temp != NULL && temp->data != pos){
		temp = temp->next;
	}
	if(temp == NULL){
		printf("Element not found...");
		return;
	}
	node *newnode = creNode(val);
	newnode->next = temp->next;
	temp->next = newnode;
}

int delFirstElem(){
	if(head == NULL){
		printf("NO ELEMENTS...");
		return;
	}
	node *temp = head;
	head = head->next;
	free(temp);
}

int delLastElem(){
	if(head == NULL){
		printf("NO ELEMENTS...");
		return;
	}
	node *t;
	if(head->next == NULL){
		t = head;
		head = NULL;
		free(t);
		return;
	}
	node *temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}	
	t= temp->next;
	temp->next = NULL;
	free(t);
}

int display(){
	if(head == NULL){
		printf("Empty");
		return;
	}
	node *temp = head;
	while(temp != NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(){
	int ch = 0,val,pos;
	while(ch != 9){
		printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specific element\n4.delete first element\n");
		printf("5.Delete last element\n6.Deloete element at position\n7.display\n8.exit\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter element to insert:");
				scanf("%d",&val);
				insertAtBeg(val);
				break;
		    case 2:
		    	printf("Enter element to insert:");
				scanf("%d",&val);
				insertAtEnd(val);
				break;
			case 3:
				printf("Enter element to insert:");
				scanf("%d",&val);
				printf("After which element to insert:");
				scanf("%d",&pos);
				insertAtSpec(val,pos);
			case 4:
				delFirstElem();
				break;
			case 5:
				delLastElem();
				break;
//			case 6:
//				printf("Enter psoition to delete:");
//				scanf("%d",&pos);
//				delSpecElem(pos);
//				break;
			case 7:
				display();
				break;
			case 8:
				ch = 9	;
				break;
		}
	}	
}

