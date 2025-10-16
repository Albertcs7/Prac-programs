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

// Inorder traversal (Left, Root, Right)
void inorder(struct node* root) {
    if(root!=NULL) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(struct node* root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(struct node* root) {
    if(root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
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
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}

