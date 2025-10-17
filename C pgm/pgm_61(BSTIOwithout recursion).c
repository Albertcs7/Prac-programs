#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node* root=NULL;

// Insert a node into BST recursively
node* insert(node* root,int value) {
    if(root==NULL) {
        node* newNode=(node*)malloc(sizeof(node));
        newNode->data=value;
        newNode->left=newNode->right=NULL;
        return newNode;
    }
    if(value<root->data)
        root->left=insert(root->left,value);
    else if(value>root->data)
        root->right=insert(root->right,value);
    return root;
}

// Inorder traversal without recursion
void inorder(node* root) {
    node* stack[50];
    int top=-1;
    node* curr=root;
    while(curr!=NULL || top!=-1) {
        while(curr!=NULL) {
            stack[++top]=curr;
            curr=curr->left;
        }
        curr=stack[top--];
        printf("%d ",curr->data);
        curr=curr->right;
    }
}

// Display function
void display() {
    printf("BST Elements in Inorder: ");
    inorder(root);
    printf("\n");
}

// Menu function
int menu() {
    int choice;
    printf("1. Insert\n2. Display Inorder\n3. Exit\nEnter your choice: ");
    scanf("%d",&choice);
    return choice;
}

// Main function with menu-driven loop
int main() {
    int choice,value;
    for(choice=menu();choice!=3;choice=menu()) {
        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d",&value);
                root=insert(root,value); // Insert element
                break;
            case 2:
                display(); // Display BST in inorder
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

