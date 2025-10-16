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

// Inorder traversal without recursion
void inorder(struct node* root) {
    struct node* stack[50];
    int top=-1;
    struct node* curr=root;
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

int main() {
    struct node* root=NULL;
    int n,i,value;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter %d values:\n",n);
    for(i=0;i<n;i++) {
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("\nInorder Traversal (without recursion): ");
    inorder(root);
    printf("\n");
    return 0;
}

