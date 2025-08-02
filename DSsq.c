#include<stdio.h>
#define s 5
int a[s],top=-1,front=-1,rear=-1;
void push(int e){
	if(top+1 == s){
		printf("Stack Overflow...");
	}
	else{
		a[++top] = e;
	}
}
void pop(){
	if(top== -1){
		printf("Stack Underflow...");
	}
	else{
		printf("Deleted:%d",a[top--]);
	}
}
void enqueue(int e){
	if(rear+1 == s){
		printf("Queue full...");
	}
	else{
		if(front == -1)
			front = 0;
		a[++rear] = e;
	}
}
void dequeue(){
	if(rear == -1){
		printf("Queue empty...");
	}
	else{
		printf("deleted:%d",a[front]);
		front++;
		if(front>rear){ 
            front=rear=-1;
        }
	}
}
void disp(){
	int i;
	for(i=0;i<s;i++){
		printf("%d\t",a[i]);
	}	
}
void stack(){
	char ch= 'y';
	int opt,p;
	while(ch == 'y'){
		printf("\n1.push\n2.pop\n3.display\n4.exit...");
		printf("\nEnter a option:");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter the number to push:");
				scanf("%d",&p);
				push(p);
				break;
			case 2:
				pop();
				break;
			case 3:
				disp();
				break;
			case 4:
				ch = 'n';
				break;
			default:
				printf("Enter valid option");			
					
		}
			
	}
}
void queue(){
	char ch= 'y';
	int opt,p;
	while(ch == 'y'){
		printf("\n1.Enqueue\n2.Dequeue\n3.display\n4.exit...");
		printf("\nEnter a option:");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter the number to insert:");
				scanf("%d",&p);
				enqueue(p);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				disp();
				break;
			case 4:
				ch = 'n';
				break;
			default:
				printf("Enter valid option");			
					
		}
			
	}
}
int main(){
	char ds;
	printf("Choose btw stack(s) and queue(q):");
	scanf("%c",&ds);
	if(ds == 's'){
		stack();
	}
	else if(ds == 'q'){
		queue();
	}
	return 0;
}
