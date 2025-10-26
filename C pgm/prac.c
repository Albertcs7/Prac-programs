#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node *front = NULL;
node *rear = NULL;
void enqueue(int val){
	if(front == NULL){
		front = (node *)malloc(sizeof(node));
		front->data = val;
		front->next = NULL;
		rear = front;
		rear->next = front;
	}
	else{
		rear->next = (node *)malloc(sizeof(node));
		rear->next->data = val;
		rear->next->next = front;	
 		rear = rear->next;
	}	
}
int dequeue(){
	if(front == NULL){
		printf("Queue is empty...");
		return 0;
	}
	node *temp;
	temp = front;
	front = front->next;
	rear->next = front;
	free(temp);
	if(front == NULL){
		rear = NULL;
	}
}
int display(){
	node *t;
	t = front;
	if(front == NULL)
		printf("Queue empty");
	while(t->next != front){
		printf("%d ",t->data);
		t = t->next;
	}
}
int main(){
	int ch = 0,val;
	while(ch != 4){
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit...\nenter the choise:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter element:");
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
		}
	}
}
