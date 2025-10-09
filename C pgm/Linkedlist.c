#include<stdio.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;

void insert(int a){
	node *t;
	if(head == NULL){
		head = (node*)malloc(sizeof(node));
		head->data = a;
		head->next = NULL;
	}	
	else{
		t=head;
		while(t->next != NULL){
			t = t->next;
		}	
		t->next=(node*)malloc(sizeof(node));
		t->next->data = a;
		t->next->next =NULL;
	}
}

void delete(int a){
	node *t;
	if(head == NULL){
		printf("List empty");
	}
	else if(head->data == a){
		head = head->next;
	}
	else{
		t=head;
		while(t->next != NULL && t->next->data != a){
			t=t->next;
		}
		if(t->next == NULL){
			printf("ELEMENT NOT FOUND");
		}
		else{
			t->next = t->next->next;
		}
	}
}
void sort(){
	
}

void display(){
	node *t;
	for(t=head;t!=NULL;t=t->next){
		printf("%d\t",t->data);
	}
	printf("\n");
}

int main(){
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	display();
	delete(30);
	display();
}
