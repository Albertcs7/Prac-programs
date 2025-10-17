#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node* root = NULL;

// Insert a node into BST recursively
node* insert(node* root, int value) {
    if(root == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Postorder traversal without recursion
void postorder(node* root) {
    if(root == NULL) return;
    node* stack1[50];
    node* stack2[50];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while(top1 != -1) {
        node* curr = stack1[top1--];
        stack2[++top2] = curr;
        if(curr->left) stack1[++top1] = curr->left;
        if(curr->right) stack1[++top1] = curr->right;
    }

    while(top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Menu function
int menu() {
    int choice;
    printf("1. Insert\n2. Display Postorder\n3. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function with menu loop
int main() {
    int choice, value;
    for(choice = menu(); choice != 3; choice = menu()) {
        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

