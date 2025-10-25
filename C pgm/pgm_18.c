#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// function to push into stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// function to pop from stack
char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return -1;
}

// function to peek
char peek() {
    if (top != -1) return stack[top];
    return -1;
}

// function to check precedence
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Function to check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// function to reverse string
void reverse(char str[]) {
    int n = strlen(str);
    int i;
    for (i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// function to convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    for (i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;  
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); //  to remove until '('
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

// function to convert infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
    char rev[MAX], postfix[MAX];
	int i;
    strcpy(rev, infix);
    reverse(rev);

    // Swap brackets
    for (i = 0; rev[i]; i++) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }

    infixToPostfix(rev, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

// main function
int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);	//calling prefix function

    printf("Prefix expression: %s\n", prefix);
    return 0;
}

