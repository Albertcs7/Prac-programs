#include<stdio.h>
#include<malloc.h>

typedef struct node {
    int coeff;
    int pow;
    struct node *next;
} node;
node *poly1 = NULL, *poly2 = NULL, *result = NULL;
// Function to insert a term into polynomial
void insert(node **head, int c, int p) {
    node *t, *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->coeff = c;
    newnode->pow = p;
    newnode->next = NULL;

    if (*head == NULL)
        *head = newnode;
    else {
        t = *head;
        while (t->next)
            t = t->next;
        t->next = newnode;
    }
}
// Function to display a polynomial
void display(node *head) {
    node *t = head;
    if (t == NULL) {
        printf("0\n");
        return;
    }
    while (t) {
        printf("%dx^%d", t->coeff, t->pow);
        t = t->next;
        if (t)
            printf(" + ");
    }
    printf("\n");
}
// Function to add two polynomials
void add() {
    node *p1 = poly1, *p2 = poly2;
    int sum;
    while (p1 && p2) {
        if (p1->pow > p2->pow) {
            insert(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insert(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            sum = p1->coeff + p2->coeff;
            insert(&result, sum, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        insert(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        insert(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
}
// Function to multiply two polynomials
void multiply() {
    node *p1 = poly1, *p2;
    node *temp = NULL;
    int c, p;

    while (p1) {
        p2 = poly2;
        while (p2) {
            c = p1->coeff * p2->coeff;
            p = p1->pow + p2->pow;
            node *r = result, *prev = NULL;
            while (r && r->pow > p) {
                prev = r;
                r = r->next;
            }
            if (r && r->pow == p) {
                r->coeff += c;
            } else {
                node *newnode = (node*)malloc(sizeof(node));
                newnode->coeff = c;
                newnode->pow = p;
                newnode->next = NULL;

                if (prev == NULL) {  // insert at beginning
                    newnode->next = result;
                    result = newnode;
                } else {
                    newnode->next = prev->next;
                    prev->next = newnode;
                }
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

int main() {
    int n, i, c, p;
    
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &c, &p);
        insert(&poly1, c, p);
    }
    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &c, &p);
        insert(&poly2, c, p);
    }
    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);
    printf("\nAddition of polynomial: ");
    add();		//addition function call
    display(result);
    result = NULL;
    printf("\nMultiplication of polynomials: ");
    multiply();		//multiplication function call
    display(result);

    return 0;
}

