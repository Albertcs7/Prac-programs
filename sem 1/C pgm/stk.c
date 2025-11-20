#include<stdio.h>
int top = -1;

void push(int stk[],int val,int n){
	if(top == n-1){
		printf("\nStack overflow...\n");
		return;
	}
	stk[++top] = val;
	printf("inserted %d",val);
}

void pop(int stk[]){
	int val;
	if(top == -1){
		printf("stack underflow");
		return ;
	}
	val = stk[top];
	--top ;	
	printf("Popped %d ",val);
}

void display(int stk[]){
	int i = top;
	if(top == -1){
		printf("\nstack empty");
		return;
	}
	printf("\nstack is:");
	while(i >= 0){
		printf("%d\t",stk[i--]);
	}
	
}

int main(){
	int n,val;
	printf("ENter number of elements in the stack:");
	scanf("%d",&n);
	int stk[n];
	int ch = 0;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\nenter a choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("ENter element to insert:");
				scanf("%d",&val);
				push(stk,val,n);
				break;
			case 2:
				pop(stk);
				break;
			case 3:
				display(stk);
			 	break;
			case 4:
				return 0;
		}
	}
}

