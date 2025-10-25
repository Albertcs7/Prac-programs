#include <stdio.h>
#include <ctype.h>
#define s 100

char arr[s];
char res[s];
char stk[s];
int top = -1;
int pos = -1;

//Function to check precedence
int prec(char op) {
    if (op == '+' || op == '-') // assigning precedence
		return 1;
    if (op == '*' || op == '/') 
		return 2;
    return 0;
}

//Function to push operators into stack
void push(char e) {
    stk[++top] = e;
}

//Function to pop operators from stack
char pop() {
    if (top == -1) 
		return '\0'; 
    return stk[top--];	
}

//Function to get the top element of stack
char peek() {
    if (top == -1) 
		return '\0';
    return stk[top];
}

//Function to convert to postfix
void postfix() {
	int i;
    for (i = 0; arr[i] != '\0'; i++) {
        char d = arr[i];

        if(isalnum(d)) {		
            res[++pos] = d;
        } else if (d == '(') {
            push(d);
        } else if (d == ')') {
            while (peek() != '(' && top != -1) {
                res[++pos] = pop();
            }
            pop(); 
        } else {
            while (top != -1 && prec(peek()) >= prec(d)) {
                res[++pos] = pop();
            }
            push(d);
        }
    }

    while (top != -1) {
        res[++pos] = pop();
    }

    res[++pos] = '\0'; 
}

int main() {
    printf("Enter an infix expression: ");
    scanf("%s", arr);

    postfix();

    printf("Postfix expression: %s\n", res);
    return 0;
}

