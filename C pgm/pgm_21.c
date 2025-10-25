#include<stdio.h>
#include <ctype.h>
#define n 25

char res[n] , top = -1;

//Function to push elemnt inton stack 
void push(char a){
	if( top < n-1 ){
		res[++top] = a;
	}
}

//Function to pop element from stack
void pop(){
	if(top == -1){
		printf("Nohting to pop");
	}
	else{
		printf("%c",res[top]);	//poppig and displaying the characters
		top--;  
	}
}

int main(){
	char str[25] ;
	int i;
	printf("Enter the element:");
	for( i=0 ; i<n ; i++){
		scanf("%c",&str[i]);
	}
	printf("The output is : ");
	for(i=0 ; str[i] != '\0' ; i++){
		if(str[i] == '*'){ 
			
			pop();	// popping when '*' occurs
		}
		else{ 
			push(str[i]);	// pushing characters into stack
		}
	}
}	

