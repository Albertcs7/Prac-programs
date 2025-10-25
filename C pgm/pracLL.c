#include<stdio.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node node;
node *head = NULL;

void insert(int a){
	if(head == NULL){
		head->data = a;
		head->next = NULL;
	}
	node *t;
	t = head;
	while(t->next != NULL){
		t= t->next;
	}		
	t->next->data = a;
	t->next->next = NULL;
}

void delete(){
	
}

void display(){
	node *t;
	t = head;
	while(t != NULL){
		printf("%d",t->data);
		t= t->next;
	}
}

int main(){
	int ch = 0;
	int val;
	printf("1.insert\n2.delet\n3.Display\n4.exit\n");
	scanf("%d",&ch);
	while(ch != 5){
		switch(ch){
			case 1:
				printf("Enter element to insert:");
				scanf("%d",&val);
				insert(val);
				break;
			case 2:
				printf("Enter element to delete:");
				scanf("%d",&val);
				delete();
				break;
			case 3:
				display();
			case 4:
				printf("Exiting...");
				break;
			default:
				printf("ENter valid choice...");
				break;		
		}
	}
}
