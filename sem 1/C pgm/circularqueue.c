#include<stdio.h>
int front = -1 ,rear = -1;

void enqueue(int que[],int val,int n){
	if(front == o && rear ==  n-1 || (rear+1)%n == front){
		printf("Queue full");
		return;
	}
	if(front == -1)
		front = rear = 0;
	rear = (rear + 1)% n;
	que[rear] = val;
}

void dequeue(int que[]){
	if(front == -1 || front > rear){
		printf("Queue empty..");
		return;
	}
	printf("Deleted %d",que[front]);
	front++;
}


void display(int que[]){
	int i = front;
	if(front == -1 || front > rear){
		printf("Empty...");
		return;
	}
	printf("\nQueue is : ");
	while(i <= rear){
		printf("%d\t",que[i]);
		i++;
	}
}

int main(){
	int n,val;
	printf("\nEnter numer of elements:");
	scanf("%d",&n);
	int que[n];
	int ch = 0;
	while(1){
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\nEnter a choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter element to insert:");
				scanf("%d",&val);
				enqueue(que,val,n);
				break;
			case 2:
				dequeue(que);
				break;
			case 3:
				display(que);
			 	break;
			case 4:
				return 0;
		}
	}
}

