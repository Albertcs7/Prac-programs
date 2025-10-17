#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Insert a node into BST
struct node* insert(struct node* root, int value) {
    if(root==NULL) {
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
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

// Inorder traversal
void inorder(struct node* root) {
    if(root!=NULL) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct node* root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct node* root) {
    if(root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

// Menu function
int menu() {
    int choice;
    printf("1. Insert\n2. Display Inorder\n3. Display Preorder\n4. Display Postorder\n5. Exit\nEnter your choice: ");
    scanf("%d",&choice);
    return choice;
}

// Main function with menu-driven loop
int main() {
    struct node* root=NULL;
    int choice,value;
    for(choice=menu();choice!=5;choice=menu()) {
        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d",&value);
                root=insert(root,value); // Insert element
                break;
            case 2:
                printf("Inorder: ");
                inorder(root); // Display inorder
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preorder(root); // Display preorder
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root); // Display postorder
                printf("\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

